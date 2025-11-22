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
  "es",  // Spanish
  "pt",  // Portuguese
  "fr",  // French
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
  // Bind text domain first
  const char* localeDir = GetLocaleDir();
  bindtextdomain("blockout", localeDir);
  textdomain("blockout");
  
  fprintf(stderr, "[I18N] Locale directory: %s\n", localeDir);
  fprintf(stderr, "[I18N] Text domain: blockout\n");
  
  // Try to detect system language from LANG, fallback to English
  const char* lang = getenv("LANG");
  fprintf(stderr, "[I18N] LANG environment variable: %s\n", lang ? lang : "(not set)");
  
  bool langFound = false;
  
  if (lang && strlen(lang) >= 2) {
    char langCode[3];
    langCode[0] = lang[0];
    langCode[1] = lang[1];
    langCode[2] = '\0';
    
    fprintf(stderr, "[I18N] Detected language code: %s\n", langCode);
    
    // Check if it's one of our supported languages
    for (int i = 0; availableLanguages[i] != NULL; i++) {
      if (strcmp(langCode, availableLanguages[i]) == 0) {
        strncpy(currentLanguage, langCode, sizeof(currentLanguage) - 1);
        langFound = true;
        fprintf(stderr, "[I18N] Language '%s' is supported\n", langCode);
        break;
      }
    }
    
    if (!langFound) {
      fprintf(stderr, "[I18N] Language '%s' not supported, falling back to English\n", langCode);
    }
  }
  
  // Fallback to English if LANG not set or unsupported
  if (!langFound) {
    strncpy(currentLanguage, "en", sizeof(currentLanguage) - 1);
  }
  
  fprintf(stderr, "[I18N] Current language set to: %s\n", currentLanguage);
  
  // Set the locale to the detected language
  char localeName[32];
  snprintf(localeName, sizeof(localeName), "%s_%s.UTF-8", 
           currentLanguage, 
           currentLanguage[0] == 'e' && currentLanguage[1] == 'n' ? "US" :
           currentLanguage[0] == 'e' && currentLanguage[1] == 's' ? "ES" :
           currentLanguage[0] == 'p' && currentLanguage[1] == 't' ? "BR" :
           currentLanguage[0] == 'f' && currentLanguage[1] == 'r' ? "FR" : "US");
  
  fprintf(stderr, "[I18N] Setting locale to: %s\n", localeName);
  
  char* result = setlocale(LC_ALL, localeName);
  fprintf(stderr, "[I18N] setlocale(LC_ALL) result: %s\n", result ? result : "(failed)");
  
  result = setlocale(LC_MESSAGES, localeName);
  fprintf(stderr, "[I18N] setlocale(LC_MESSAGES) result: %s\n", result ? result : "(failed)");
  
  // Test translation
  const char* test = gettext("MAIN MENU");
  fprintf(stderr, "[I18N] Test translation of 'MAIN MENU': %s\n", test);
  
  fflush(stderr);
#else
  fprintf(stderr, "[I18N] NLS support not enabled (ENABLE_NLS not defined)\n");
#endif
}

void SetLanguage(const char* lang) {
  if (!lang || strlen(lang) < 2) return;
  
  // Validate language is supported
  bool found = false;
  for (int i = 0; availableLanguages[i] != NULL; i++) {
    if (strcmp(lang, availableLanguages[i]) == 0) {
      found = true;
      break;
    }
  }
  
  if (!found) return;
  
  strncpy(currentLanguage, lang, sizeof(currentLanguage) - 1);
  currentLanguage[sizeof(currentLanguage) - 1] = '\0';
  
#ifdef ENABLE_NLS
  // Set locale
  char locale[16];
  snprintf(locale, sizeof(locale), "%s_%.2s.UTF-8", lang, lang);
  setlocale(LC_ALL, locale);
  
  // Rebind text domain
  const char* localeDir = GetLocaleDir();
  bindtextdomain("blockout", localeDir);
  textdomain("blockout");
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
