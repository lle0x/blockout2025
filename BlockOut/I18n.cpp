/*
   File:        I18n.cpp
  Description: Internationalization support using gettext
  Program:     BlockOut
  Author:      BlockOut Team

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
*/

#include "I18n.h"
#include <string.h>
#include <stdio.h>
#include <cstdlib>

#ifdef WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#endif

static char currentLanguage[8] = "en";

static const char* availableLanguages[] = {
  "en",  // English
  "es",  // Spanish (Español)
  "pt",  // Portuguese (Português)
  "fr",  // French (Français)
  "it",  // Italian (Italiano)
  "de",  // German (Deutsch)
  "pl",  // Polish (Polski)
  "ro",  // Romanian (Română)
  "zh",  // Chinese (中文)
  "ja",  // Japanese (日本語)
  "ga",  // Irish (Gaeilge)
  "el",  // Greek (Ελληνικά)
  "nl",  // Dutch (Nederlands)
  "da",  // Danish (Dansk)
  "ca",  // Catalan (Català)
  "no",  // Norwegian (Norsk)
  "cs",  // Czech (Čeština)
  "fi",  // Finnish (Suomi)
  "sv",  // Swedish (Svenska)
  "et",  // Estonian (Eesti)
  "tr",  // Turkish (Türkçe)
  "af",  // Afrikaans
  "ar",  // Arabic (العربية)
  NULL
};

static const char* languageDisplayNames[] = {
  "English",
  "Español",
  "Português",
  "Français",
  "Italiano",
  "Deutsch",
  "Polski",
  "Română",
  "中文",
  "日本語",
  "Gaeilge",
  "Ελληνικά",
  "Nederlands",
  "Dansk",
  "Català",
  "Norsk",
  "Čeština",
  "Suomi",
  "Svenska",
  "Eesti",
  "Türkçe",
  "Afrikaans",
  "العربية",
  NULL
};

// Get the locale directory path
static const char* GetLocaleDir() {
#ifdef WINDOWS
  static char localeDir[512];
  char exePath[512];
  GetModuleFileNameA(NULL, exePath, sizeof(exePath));
  char* lastSlash = strrchr(exePath, '\\');
  if (lastSlash) *lastSlash = '\0';
  snprintf(localeDir, sizeof(localeDir), "%s\\locale", exePath);
  return localeDir;
#else
  // Check if BL2_HOME is set
  const char* bl2Home = getenv("BL2_HOME");
  if (bl2Home && strlen(bl2Home) > 0) {
    static char localeDir[512];
    snprintf(localeDir, sizeof(localeDir), "%s/locale", bl2Home);
    return localeDir;
  }
  // Fallback to current directory
  return "./locale";
#endif
}

void InitI18n() {
#ifdef ENABLE_NLS
  bool debug = (getenv("BLOCKOUT_DEBUG") != NULL);

  // Set locale from environment first
  char* result = setlocale(LC_ALL, "");
  if (debug) fprintf(stderr, "[I18N] Initial setlocale(LC_ALL, \"\") result: %s\n", result ? result : "(failed)");

  // Try to detect system language
  // Priority: LC_ALL > LANG > LC_MESSAGES > LANGUAGE
  // We prioritize LANG over LC_MESSAGES/LANGUAGE to allow users to override with LANG=es ./blockout
  const char* lc_all = getenv("LC_ALL");
  const char* lang = getenv("LANG");
  const char* lc_messages = getenv("LC_MESSAGES");
  const char* language = getenv("LANGUAGE");
  
  if (debug) {
    fprintf(stderr, "[I18N] LC_ALL: %s\n", lc_all ? lc_all : "(not set)");
    fprintf(stderr, "[I18N] LANG: %s\n", lang ? lang : "(not set)");
    fprintf(stderr, "[I18N] LC_MESSAGES: %s\n", lc_messages ? lc_messages : "(not set)");
    fprintf(stderr, "[I18N] LANGUAGE: %s\n", language ? language : "(not set)");
  }
  
  bool langFound = false;
  const char* detectFrom = NULL;
  
  if (lc_all && strlen(lc_all) >= 2) detectFrom = lc_all;
  else if (lang && strlen(lang) >= 2) detectFrom = lang;
  else if (lc_messages && strlen(lc_messages) >= 2) detectFrom = lc_messages;
  else if (language && strlen(language) >= 2) detectFrom = language;

  if (detectFrom) {
    char langCode[3];
    langCode[0] = detectFrom[0];
    langCode[1] = detectFrom[1];
    langCode[2] = '\0';
    
    if (debug) fprintf(stderr, "[I18N] Detected language code: %s (from %s)\n", langCode, detectFrom);
    
    // Check if it's one of our supported languages
    for (int i = 0; availableLanguages[i] != NULL; i++) {
      if (strcmp(langCode, availableLanguages[i]) == 0) {
        strncpy(currentLanguage, langCode, sizeof(currentLanguage) - 1);
        langFound = true;
        if (debug) fprintf(stderr, "[I18N] Language '%s' is supported\n", langCode);
        break;
      }
    }
    
    if (!langFound && debug) {
      fprintf(stderr, "[I18N] Language '%s' not supported, falling back to English\n", langCode);
    }
  }
  
  // Fallback to English if not found
  if (!langFound) {
    strncpy(currentLanguage, "en", sizeof(currentLanguage) - 1);
  }
  
  if (debug) fprintf(stderr, "[I18N] Current language set to: %s\n", currentLanguage);
  
  // Set the locale to the detected language
  char localeName[32];
  snprintf(localeName, sizeof(localeName), "%s_%s.UTF-8", 
           currentLanguage, 
           currentLanguage[0] == 'e' && currentLanguage[1] == 'n' ? "US" :
           currentLanguage[0] == 'e' && currentLanguage[1] == 's' ? "ES" :
           currentLanguage[0] == 'p' && currentLanguage[1] == 't' ? "BR" :
           currentLanguage[0] == 'f' && currentLanguage[1] == 'r' ? "FR" : "US");
  
  if (debug) fprintf(stderr, "[I18N] Setting locale to: %s\n", localeName);
  
  result = setlocale(LC_ALL, localeName);
  if (debug) fprintf(stderr, "[I18N] setlocale(LC_ALL) result: %s\n", result ? result : "(failed)");
  
  result = setlocale(LC_MESSAGES, localeName);
  if (debug) fprintf(stderr, "[I18N] setlocale(LC_MESSAGES) result: %s\n", result ? result : "(failed)");
  
  // IMPORTANT: Set LANGUAGE environment variable as it overrides LC_MESSAGES in GNU gettext
  // This ensures that even if LC_MESSAGES fails or is overridden, gettext knows what to use
  setenv("LANGUAGE", currentLanguage, 1);
  if (debug) fprintf(stderr, "[I18N] Set LANGUAGE environment variable to: %s\n", currentLanguage);

  // Bind text domain AFTER setting locale
  const char* localeDir = GetLocaleDir();
  bindtextdomain("blockout", localeDir);
  bind_textdomain_codeset("blockout", "ISO-8859-1"); // Use ISO-8859-1 for 8-bit font texture compatibility
  textdomain("blockout");
  
  if (debug) {
    fprintf(stderr, "[I18N] Locale directory: %s\n", localeDir);
    fprintf(stderr, "[I18N] Text domain: blockout\n");
    
    // Test translation
    const char* test = gettext("MAIN MENU");
    fprintf(stderr, "[I18N] Test translation of 'MAIN MENU': %s\n", test);
    
    fflush(stderr);
  }
#else
  fprintf(stderr, "[I18N] NLS support not enabled (ENABLE_NLS not defined)\n");
#endif
}

const char* GetLocalizedAsset(const char* assetName) {
  static char localizedPath[512];
  
  // If English or no language set, return original
  if (strcmp(currentLanguage, "en") == 0 || strlen(currentLanguage) == 0) {
    return assetName;
  }
  
  // Construct localized filename: path/name_lang.ext
  // e.g. images/font.png -> images/font_es.png
  char path[512];
  strncpy(path, assetName, sizeof(path)-1);
  
  char* dot = strrchr(path, '.');
  if (!dot) return assetName; // No extension, return original
  
  *dot = '\0'; // Cut extension
  const char* ext = strrchr(assetName, '.');
  
  snprintf(localizedPath, sizeof(localizedPath), "%s_%s%s", path, currentLanguage, ext);
  
  // Check if file exists using LID (Locate In Directory) logic or simple file check
  // Since we don't have easy access to LID here, we'll assume the caller will handle it
  // or we can check if the file exists relative to executable/BL2_HOME
  
  // For now, just return the localized path. The caller (RestoreDeviceObjects) will try to load it.
  // If we wanted to be safer, we could check for existence here, but that requires duplicating LID logic.
  // A better approach might be to return the localized path, and if loading fails, the caller falls back.
  // But existing code prints errors on failure.
  
  // Let's assume the localized file MUST exist if we are in that language.
  // Or we can try to check existence if we include Utils.h? No, circular dependency risk.
  
  // Let's rely on the fact that we will create these files.
  return localizedPath;
}

void SetLanguage(const char* lang) {
  if (!lang || strlen(lang) < 2) return;
  
  bool debug = (getenv("BLOCKOUT_DEBUG") != NULL);
  
  // Validate language is supported
  bool found = false;
  for (int i = 0; availableLanguages[i] != NULL; i++) {
    if (strcmp(lang, availableLanguages[i]) == 0) {
      found = true;
      break;
    }
  }
  
  if (!found) {
    if (debug) fprintf(stderr, "[I18N] SetLanguage: '%s' not supported\n", lang);
    return;
  }
  
  strncpy(currentLanguage, lang, sizeof(currentLanguage) - 1);
  currentLanguage[sizeof(currentLanguage) - 1] = '\0';
  
  if (debug) fprintf(stderr, "[I18N] SetLanguage: changing to '%s'\n", lang);
  
#ifdef ENABLE_NLS
  // Set LANGUAGE environment variable (most important for gettext)
  setenv("LANGUAGE", lang, 1);
  if (debug) fprintf(stderr, "[I18N] Set LANGUAGE environment variable to: %s\n", lang);
  
  // Set locale
  char localeName[32];
  snprintf(localeName, sizeof(localeName), "%s_%s.UTF-8", 
           lang, 
           strcmp(lang, "en") == 0 ? "US" :
           strcmp(lang, "es") == 0 ? "ES" :
           strcmp(lang, "pt") == 0 ? "BR" :
           strcmp(lang, "fr") == 0 ? "FR" :
           strcmp(lang, "it") == 0 ? "IT" :
           strcmp(lang, "de") == 0 ? "DE" :
           strcmp(lang, "pl") == 0 ? "PL" :
           strcmp(lang, "ro") == 0 ? "RO" :
           strcmp(lang, "zh") == 0 ? "CN" :
           strcmp(lang, "ja") == 0 ? "JP" : "US");
  
  if (debug) fprintf(stderr, "[I18N] Setting locale to: %s\n", localeName);
  setlocale(LC_ALL, localeName);
  setlocale(LC_MESSAGES, localeName);
  
  // Rebind text domain to refresh translations
  const char* localeDir = GetLocaleDir();
  bindtextdomain("blockout", localeDir);
  bind_textdomain_codeset("blockout", "ISO-8859-1");
  textdomain("blockout");
  
  if (debug) {
    fprintf(stderr, "[I18N] Text domain rebound\n");
    const char* test = gettext("MAIN MENU");
    fprintf(stderr, "[I18N] Test translation of 'MAIN MENU': %s\n", test);
    fflush(stderr);
  }
#endif
}

const char* GetCurrentLanguage() {
  return currentLanguage;
}

const char** GetAvailableLanguages(int* count) {
  if (count) {
    *count = 0;
    for (int i = 0; availableLanguages[i] != NULL; i++) {
      (*count)++;
    }
  }
  return availableLanguages;
}

const char* GetLanguageName() {
  // Find index of current language
  for (int i = 0; availableLanguages[i] != NULL; i++) {
    if (strcmp(currentLanguage, availableLanguages[i]) == 0) {
      return languageDisplayNames[i];
    }
  }
  return "English"; // Default
}

const char* GetLanguageDisplayName(const char* langCode) {
  if (!langCode) return "English";
  
  // Find index of language code
  for (int i = 0; availableLanguages[i] != NULL; i++) {
    if (strcmp(langCode, availableLanguages[i]) == 0) {
      return languageDisplayNames[i];
    }
  }
  return "English"; // Default
}
