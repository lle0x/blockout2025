# BlockOut II v2.5

![BlockOut II Gameplay](gameplay-screenshot.png)

**A 3D Tetris-style puzzle game**

BlockOut II is an OpenGL adaptation of the original BlockOut DOS game edited by California Dreams in 1989. BlockOut II has the same features as the original game with few graphic improvements. Score calculation is also nearly similar to the original game. BlockOut II has been designed by an addicted player for addicted players.

Have fun with BlockOut II...

---

*Blockout® is a registered trademark of Kadon Enterprises, Inc., used by permission. This USA company produces hands-on sets of polycubes since 1980. [www.gamepuzzles.com](http://www.gamepuzzles.com)*

---

## 🌐 Official Home Page

**http://www.blockout.net/blockout2**

## 🌍 Languages / Idiomas / Langues

- [English](README.md) (this file)
- [Español](docs/README.es.md)
- [Português](docs/README.pt.md)
- [Français](docs/README.fr.md)

## 📦 Downloads

Get the latest release for your platform from the [Releases page](https://github.com/lle0x/blockout2025/releases):

- **Windows**: `blockout-windows-*.zip` - Extract and run `Blockout.exe`
- **Linux (Generic)**: `blockout-linux-x64-*.tar.gz` - Extract and run `./blockout/blockout`
- **macOS**: `blockout-macos-*.tar.gz` - Extract and run the binary
- **Ubuntu/Debian**: `blockout_*.deb` - Install with `sudo dpkg -i blockout_*.deb`
- **Fedora/RHEL**: `blockout-*.rpm` - Install with `sudo dnf install blockout-*.rpm`
- **Arch Linux**: `blockout-*.pkg.tar.zst` - Install with `sudo pacman -U blockout-*.pkg.tar.zst`

## 🎮 System Requirements

### Windows
- OpenGL support

### Linux
**Runtime:**
- `libgl1-mesa`
- `libglu1-mesa`
- `libxext6`
- `libsdl1.2`
- `libsdl-mixer1.2`

**Build Dependencies:**
- `build-essential`
- `libgl1-mesa-dev`
- `libglu1-mesa-dev`
- `libxext-dev`
- `libsdl1.2-dev`
- `libsdl-mixer1.2-dev`
- `libasound2-dev`

### macOS
- SDL 1.2 (via sdl12-compat)
- SDL_mixer 1.2
- OpenGL

## 📝 Version History

### 2.5
- 64-bit support
- OpenGL is now used both on Linux and Windows
- Little graphics improvements
- Practice mode improvements
- Improved the demo mode (Bot player plays better)
- Local data directory moved from installation directory to "AppData" directory

### 2.4
- Added frame limiter
- Added demo mode
- Added practice mode
- Fixed replay bug
- Fixed random generator (FLAT block set)
- Fixed fullscreen bug (Linux)

### 2.3
- Added player/rank name when replaying
- New punctuation characters added
- Little effect when rotation is blocked
- Fixed "Cannot open blX.bl2replay for writing"
- New style (Marble/Arcade)
- Fixed crash when pressing [Esc]
- Pit animation when the game is over
- Jump to Score Details page after end of game
- Added DOS blockout sound preset
- New randomizer

### 2.2
- NUMPAD Key control added
- Block transparency configurable with slider
- Abort menu startup demo with [Esc]
- Empty pit (Flush) in score details added
- On-line score database
- Replay
- Credits page added
- Other minor updates

### 2.1
- Fixed block descent algorithm
- Increased a little bit drop time
- Improved tuning of motion speed

### 2.0
- Initial release

## 🔧 Building from Source

### Ubuntu/Debian

**Automated:**
```bash
sudo ./install-ubuntu-deps.sh
./build-and-run.sh
```

**Manual:**
```bash
# Install dependencies
sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev \
  libxext-dev libsdl1.2-dev libsdl-mixer1.2-dev libasound2-dev

# Build ImageLib
make -C ImageLib/src

# Build BlockOut
make -C BlockOut _linux64=1 _release=1

# Run
cd BlockOut
./blockout
```

### Windows

1. Install Microsoft Visual Studio 2022 (or 2019/2017)
2. Install SDL 1.2.15 development libraries from [libsdl.org](http://www.libsdl.org)
3. Install SDL_mixer 1.2.12 development libraries from [libsdl.org](http://www.libsdl.org/projects/SDL_mixer/release-1.2.html)
4. Set appropriate include and lib paths in project properties
5. Build the solution

### macOS

```bash
# Install dependencies via Homebrew
brew install sdl12-compat pkg-config

# Build SDL_mixer 1.2 from source (see .github/workflows/build-macos-brew.yml)

# Build ImageLib
make -C ImageLib/src

# Build BlockOut
make -C BlockOut _macos=1

# Run
cd BlockOut
./blockout
```

## 🤖 GitHub Actions CI/CD

This repository uses GitHub Actions for automated building and releasing across all platforms. The workflows are triggered on pushes to `main` and `development` branches.

### Available Workflows

#### Build Workflows (Automated)

- **`build-windows.yml`** - Builds Windows x64 binaries and creates a zip package
  - Builds with Visual Studio 2022 (v143 toolset)
  - Includes SDL runtime DLLs and game assets
  - Outputs: `blockout-windows-*.zip`

- **`build-macos-brew.yml`** - Builds macOS binaries using Homebrew dependencies
  - Uses `sdl12-compat` for SDL 1.2 API compatibility
  - Builds SDL_mixer 1.2 from source
  - Outputs: `blockout-macos-*.tar.gz`

- **`build-fedora-rpm.yml`** - Builds RPM packages for Fedora/RHEL
  - Builds in Fedora container
  - Outputs: `blockout-*.rpm`

- **`build-arch-pkg.yml`** - Builds Arch Linux packages
  - Uses `makepkg` in Arch container
  - Outputs: `blockout-*.pkg.tar.zst`

- **`package-deb.yml`** - Builds Debian packages for multiple Ubuntu versions
  - Builds for Ubuntu 24.04, 25.04, and 25.10
  - Outputs: `blockout-*-ubuntu*.deb`

#### Release Workflow (Manual)

- **`create-release.yml`** - Creates a new release (manual trigger only)
  - Merges `development` into `main`
  - Creates a version tag
  - Builds a generic Linux x64 tarball
  - Waits for all platform builds to complete
  - Creates a GitHub Release with all platform packages
  - **Usage**: Go to Actions → "Create Release" → Run workflow → Enter version (e.g., `v2.5.0`)

### Triggering Builds

All build workflows automatically trigger on:
- Push to `main` or `development` branches
- Changes to source files (`BlockOut/**`, `ImageLib/**`)
- Changes to the workflow file itself

You can also manually trigger any workflow from the GitHub Actions tab.

### Release Process

1. Ensure all changes are merged to `development` and tested
2. Go to GitHub Actions → "Create Release" workflow
3. Click "Run workflow"
4. Enter the version number (e.g., `v2.5.0`)
5. The workflow will:
   - Merge `development` → `main`
   - Create and push the version tag
   - Build all platform packages
   - Create a GitHub Release with all artifacts

## 🎯 Game Features

### Replay System
For each high score you make, a `.bl2replay` file is created in the replay directory. These files contain replay data needed for uploading scores to the online database. A replay can be uploaded only once after successful registration.

### Score Uploading
Upload your high scores to the online database from the Score Details page. Only scores from version 2.2+ can be uploaded (replay file required).

### Randomizer
BlockOut II uses a bag randomizer that generates a sequence of all possible pieces (depending on pit dimension and block set) permuted randomly. It deals all pieces before generating another bag, preventing getting the same piece 3 times in a row.

### Frame Limiter
To synchronize animations with your monitor's vertical blanking, select VSync in the frame limiter settings, save, and restart the application.

## 📜 License

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

## 👤 Author

Jean-Luc PONS (jlp_38@yahoo.com)

## 🔗 Links

- [Official Website](http://www.blockout.net/blockout2)
- [GitHub Repository](https://github.com/lle0x/blockout2025)
- [Kadon Enterprises](http://www.gamepuzzles.com)
