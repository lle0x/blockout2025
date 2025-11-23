#!/bin/bash
# GitHub Actions Monitor Script
# Monitor and check GitHub Actions workflow runs via API

set -e

# Configuration
REPO_OWNER="${GITHUB_REPOSITORY_OWNER:-coderdojo-cordoba}"
REPO_NAME="${GITHUB_REPOSITORY_NAME:-blockout2025}"
REPO="${REPO_OWNER}/${REPO_NAME}"
API_BASE="https://api.github.com"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Get authentication token
get_auth_token() {
    # Try multiple methods to get GitHub token
    
    # Method 1: Use gh CLI if available
    if command -v gh &> /dev/null; then
        if gh auth status &> /dev/null; then
            echo "gh" # Signal to use gh CLI
            return 0
        fi
    fi
    
    # Method 2: Check GITHUB_TOKEN environment variable
    if [ -n "$GITHUB_TOKEN" ]; then
        echo "$GITHUB_TOKEN"
        return 0
    fi
    
    # Method 3: Check ~/.github-token file
    if [ -f "$HOME/.github-token" ]; then
        cat "$HOME/.github-token"
        return 0
    fi
    
    echo "" >&2
    echo "ERROR: No GitHub authentication found!" >&2
    echo "Please use one of the following methods:" >&2
    echo "  1. Install and authenticate with GitHub CLI: gh auth login" >&2
    echo "  2. Set GITHUB_TOKEN environment variable: export GITHUB_TOKEN=your_token" >&2
    echo "  3. Create ~/.github-token file with your token" >&2
    echo "" >&2
    exit 1
}

# Make API request
api_request() {
    local endpoint="$1"
    local method="${2:-GET}"
    
    local auth_token
    auth_token=$(get_auth_token)
    
    if [ "$auth_token" = "gh" ]; then
        # Use gh CLI
        gh api "$endpoint" 2>/dev/null || echo "{\"error\": \"API request failed\"}"
    else
        # Use curl with token
        curl -s -X "$method" \
            -H "Authorization: token $auth_token" \
            -H "Accept: application/vnd.github.v3+json" \
            "${API_BASE}${endpoint}" 2>/dev/null || echo "{\"error\": \"API request failed\"}"
    fi
}

# List all workflows
list_workflows() {
    echo -e "${BLUE}Workflows in ${REPO}:${NC}"
    echo ""
    
    local response
    response=$(api_request "/repos/${REPO}/actions/workflows")
    
    echo "$response" | jq -r '.workflows[] | [.id, .name, .state, .path] | @tsv' | \
        while IFS=$'\t' read -r id name state path; do
            local color=$GREEN
            [ "$state" != "active" ] && color=$YELLOW
            echo -e "${color}ID: ${id}${NC}"
            echo -e "  Name: ${name}"
            echo -e "  State: ${state}"
            echo -e "  Path: ${path}"
            echo ""
        done
}

# List recent workflow runs
list_runs() {
    local workflow_name="$1"
    local branch="$2"
    local limit="${3:-10}"
    
    echo -e "${BLUE}Recent workflow runs for ${REPO}:${NC}"
    echo ""
    
    local endpoint="/repos/${REPO}/actions/runs?per_page=${limit}"
    [ -n "$branch" ] && endpoint="${endpoint}&branch=${branch}"
    
    local response
    response=$(api_request "$endpoint")
    
    # Filter by workflow name if provided
    local jq_filter='.workflow_runs[]'
    if [ -n "$workflow_name" ]; then
        jq_filter=".workflow_runs[] | select(.name == \"$workflow_name\")"
    fi
    
    echo "$response" | jq -r "${jq_filter} | [.id, .name, .status, (.conclusion // \"running\"), .head_branch, .created_at] | @tsv" | \
        while IFS=$'\t' read -r id name status conclusion branch created; do
            local color=$YELLOW
            case "$conclusion" in
                success) color=$GREEN ;;
                failure) color=$RED ;;
                cancelled) color=$YELLOW ;;
            esac
            
            echo -e "${color}Run ID: ${id}${NC}"
            echo -e "  Workflow: ${name}"
            echo -e "  Status: ${status}"
            echo -e "  Conclusion: ${conclusion}"
            echo -e "  Branch: ${branch}"
            echo -e "  Created: ${created}"
            echo ""
        done
}

# Get details of a specific run
get_run_details() {
    local run_id="$1"
    local show_failed_logs="${2:-yes}"  # Default to showing failed logs
    
    echo -e "${BLUE}Workflow Run Details (ID: ${run_id}):${NC}"
    echo ""
    
    local response
    response=$(api_request "/repos/${REPO}/actions/runs/${run_id}")
    
    local name status conclusion branch created updated
    name=$(echo "$response" | jq -r '.name')
    status=$(echo "$response" | jq -r '.status')
    conclusion=$(echo "$response" | jq -r '.conclusion // "running"')
    branch=$(echo "$response" | jq -r '.head_branch')
    created=$(echo "$response" | jq -r '.created_at')
    updated=$(echo "$response" | jq -r '.updated_at')
    
    local color=$YELLOW
    case "$conclusion" in
        success) color=$GREEN ;;
        failure) color=$RED ;;
        cancelled) color=$YELLOW ;;
    esac
    
    echo -e "${color}Workflow: ${name}${NC}"
    echo -e "Status: ${status}"
    echo -e "Conclusion: ${conclusion}"
    echo -e "Branch: ${branch}"
    echo -e "Created: ${created}"
    echo -e "Updated: ${updated}"
    echo ""
    
    # Get jobs for this run
    echo -e "${BLUE}Jobs:${NC}"
    local jobs_response
    jobs_response=$(api_request "/repos/${REPO}/actions/runs/${run_id}/jobs")
    
    local has_failures=false
    local failed_job_ids=()
    
    echo "$jobs_response" | jq -r '.jobs[] | [.id, .name, .status, (.conclusion // "running")] | @tsv' | \
        while IFS=$'\t' read -r job_id job_name job_status job_conclusion; do
            local job_color=$YELLOW
            case "$job_conclusion" in
                success) job_color=$GREEN ;;
                failure) 
                    job_color=$RED
                    has_failures=true
                    ;;
                cancelled) job_color=$YELLOW ;;
            esac
            
            echo -e "  ${job_color}${job_name}${NC}"
            echo -e "    Status: ${job_status}, Conclusion: ${job_conclusion}"
            
            # Store failed job IDs for later
            if [ "$job_conclusion" = "failure" ]; then
                echo "$job_id" >> /tmp/failed_jobs_${run_id}.txt
            fi
        done
    echo ""
    
    # Show logs for failed jobs if requested
    if [ "$show_failed_logs" = "yes" ] && [ -f "/tmp/failed_jobs_${run_id}.txt" ]; then
        echo -e "${RED}Failed Jobs Detected - Fetching Logs:${NC}"
        echo ""
        
        while read -r failed_job_id; do
            get_job_logs "$run_id" "$failed_job_id"
        done < /tmp/failed_jobs_${run_id}.txt
        
        rm -f /tmp/failed_jobs_${run_id}.txt
    fi
}

# Get logs for a specific job
get_job_logs() {
    local run_id="$1"
    local job_id="$2"
    
    local auth_token
    auth_token=$(get_auth_token)
    
    echo -e "${BLUE}Fetching logs for job ${job_id}...${NC}"
    
    if [ "$auth_token" = "gh" ]; then
        # Use gh CLI to get job logs
        local job_info
        job_info=$(gh api "/repos/${REPO}/actions/jobs/${job_id}" 2>/dev/null)
        local job_name
        job_name=$(echo "$job_info" | jq -r '.name')
        
        echo -e "${YELLOW}Job: ${job_name}${NC}"
        echo ""
        
        # Get the log for this specific job
        gh api "/repos/${REPO}/actions/jobs/${job_id}/logs" 2>/dev/null | tail -100
        echo ""
        echo -e "${YELLOW}(Showing last 100 lines - use 'logs' command for full output)${NC}"
        echo ""
    else
        # Use curl to get job logs
        local job_info
        job_info=$(curl -s -H "Authorization: token $auth_token" \
            -H "Accept: application/vnd.github.v3+json" \
            "${API_BASE}/repos/${REPO}/actions/jobs/${job_id}")
        
        local job_name
        job_name=$(echo "$job_info" | jq -r '.name')
        
        echo -e "${YELLOW}Job: ${job_name}${NC}"
        echo ""
        
        # Get the log for this specific job
        curl -s -H "Authorization: token $auth_token" \
            -H "Accept: application/vnd.github.v3+json" \
            "${API_BASE}/repos/${REPO}/actions/jobs/${job_id}/logs" | tail -100
        echo ""
        echo -e "${YELLOW}(Showing last 100 lines - use 'logs' command for full output)${NC}"
        echo ""
    fi
}


# Get logs for a workflow run
get_run_logs() {
    local run_id="$1"
    local output_file="${2:-}"
    
    echo -e "${BLUE}Downloading logs for run ${run_id}...${NC}"
    
    local auth_token
    auth_token=$(get_auth_token)
    
    if [ "$auth_token" = "gh" ]; then
        # Use gh CLI to download logs
        if [ -n "$output_file" ]; then
            gh run view "$run_id" --log > "$output_file"
            echo -e "${GREEN}Logs saved to: ${output_file}${NC}"
        else
            gh run view "$run_id" --log
        fi
    else
        # Use curl to download logs (returns a ZIP file)
        local log_url="${API_BASE}/repos/${REPO}/actions/runs/${run_id}/logs"
        
        if [ -n "$output_file" ]; then
            curl -L -H "Authorization: token $auth_token" \
                -H "Accept: application/vnd.github.v3+json" \
                "$log_url" -o "${output_file}.zip"
            echo -e "${GREEN}Logs saved to: ${output_file}.zip${NC}"
            echo "Extract with: unzip ${output_file}.zip"
        else
            echo "Downloading logs to run-${run_id}-logs.zip..."
            curl -L -H "Authorization: token $auth_token" \
                -H "Accept: application/vnd.github.v3+json" \
                "$log_url" -o "run-${run_id}-logs.zip"
            echo -e "${GREEN}Logs saved to: run-${run_id}-logs.zip${NC}"
            echo "Extract with: unzip run-${run_id}-logs.zip"
        fi
    fi
}

# Wait for a workflow run to complete
wait_for_completion() {
    local run_id="$1"
    local timeout="${2:-3600}" # Default 1 hour timeout
    local check_interval=30
    
    echo -e "${BLUE}Waiting for run ${run_id} to complete...${NC}"
    
    local elapsed=0
    while [ $elapsed -lt $timeout ]; do
        local response
        response=$(api_request "/repos/${REPO}/actions/runs/${run_id}")
        
        local status conclusion
        status=$(echo "$response" | jq -r '.status')
        conclusion=$(echo "$response" | jq -r '.conclusion // "running"')
        
        if [ "$status" = "completed" ]; then
            echo ""
            case "$conclusion" in
                success)
                    echo -e "${GREEN}✓ Workflow completed successfully!${NC}"
                    return 0
                    ;;
                failure)
                    echo -e "${RED}✗ Workflow failed!${NC}"
                    return 1
                    ;;
                cancelled)
                    echo -e "${YELLOW}⊘ Workflow was cancelled${NC}"
                    return 2
                    ;;
                *)
                    echo -e "${YELLOW}? Workflow completed with status: ${conclusion}${NC}"
                    return 3
                    ;;
            esac
        fi
        
        echo -n "."
        sleep $check_interval
        elapsed=$((elapsed + check_interval))
    done
    
    echo ""
    echo -e "${RED}Timeout waiting for workflow to complete${NC}"
    return 4
}

# Check status of latest runs for all workflows
check_status() {
    echo -e "${BLUE}Latest workflow run status:${NC}"
    echo ""
    
    local response
    response=$(api_request "/repos/${REPO}/actions/runs?per_page=50")
    
    # Get unique workflow names and their latest run
    echo "$response" | jq -r '.workflow_runs | group_by(.name) | .[] | .[0] | [.name, .status, (.conclusion // "running"), .id, .created_at] | @tsv' | \
        while IFS=$'\t' read -r name status conclusion run_id created; do
            local color=$YELLOW
            case "$conclusion" in
                success) color=$GREEN ;;
                failure) color=$RED ;;
                cancelled) color=$YELLOW ;;
            esac
            
            echo -e "${color}${name}${NC}"
            echo -e "  Status: ${status}, Conclusion: ${conclusion}"
            echo -e "  Run ID: ${run_id}"
            echo -e "  Created: ${created}"
            echo ""
        done
}

# Show usage
usage() {
    cat << EOF
GitHub Actions Monitor Script

Usage: $0 <command> [options]

Commands:
  list                          List all workflows
  runs [workflow] [branch] [n]  List recent workflow runs (default: 10)
  details <run-id> [no-logs]    Show details of a specific run (shows failed job logs by default)
  logs <run-id> [output-file]   Download logs for a run
  wait <run-id> [timeout]       Wait for a run to complete (default timeout: 3600s)
  status                        Check status of latest runs for all workflows

Examples:
  $0 list
  $0 runs "Create Release"
  $0 runs "" main 20
  $0 details 1234567890              # Shows failed job logs automatically
  $0 details 1234567890 no-logs      # Skip showing failed job logs
  $0 logs 1234567890
  $0 logs 1234567890 release-logs.txt
  $0 wait 1234567890
  $0 status

Environment:
  GITHUB_TOKEN                  GitHub personal access token
  GITHUB_REPOSITORY_OWNER       Repository owner (default: coderdojo-cordoba)
  GITHUB_REPOSITORY_NAME        Repository name (default: blockout2025)

Authentication (in order of priority):
  1. GitHub CLI (gh) - if installed and authenticated
  2. GITHUB_TOKEN environment variable
  3. ~/.github-token file

EOF
}

# Main
main() {
    # Check for jq
    if ! command -v jq &> /dev/null; then
        echo -e "${RED}Error: jq is required but not installed.${NC}"
        echo "Install with: sudo apt-get install jq"
        exit 1
    fi
    
    local command="${1:-}"
    
    case "$command" in
        list)
            list_workflows
            ;;
        runs)
            list_runs "$2" "$3" "${4:-10}"
            ;;
        details)
            if [ -z "$2" ]; then
                echo "Error: run-id required"
                usage
                exit 1
            fi
            # Check if user wants to skip logs
            local show_logs="yes"
            if [ "$3" = "no-logs" ]; then
                show_logs="no"
            fi
            get_run_details "$2" "$show_logs"
            ;;
        logs)
            if [ -z "$2" ]; then
                echo "Error: run-id required"
                usage
                exit 1
            fi
            get_run_logs "$2" "$3"
            ;;
        wait)
            if [ -z "$2" ]; then
                echo "Error: run-id required"
                usage
                exit 1
            fi
            wait_for_completion "$2" "${3:-3600}"
            ;;
        status)
            check_status
            ;;
        help|--help|-h)
            usage
            ;;
        *)
            echo "Error: Unknown command '$command'"
            echo ""
            usage
            exit 1
            ;;
    esac
}

main "$@"
