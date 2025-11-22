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
  if (bl2Home) {
    static char localeDir[512];
    snprintf(localeDir, sizeof(localeDir), "%s/locale", bl2Home);
    return localeDir;
  }
  // Try current directory
  return "./locale";
#endif
}

void InitI18n() {
#ifdef ENABLE_NLS
  // Set locale from environment
  setlocale(LC_ALL, "");
  
  // Bind text domain
  const char* localeDir = GetLocaleDir();
  bindtextdomain("blockout", localeDir);
  textdomain("blockout");
  
  // Try to detect system language
  const char* lang = getenv("LANG");
  if (lang && strlen(lang) >= 2) {
    char langCode[3];
    langCode[0] = lang[0];
    langCode[1] = lang[1];
    langCode[2] = '\0';
    
    // Check if it's one of our supported languages
    for (int i = 0; availableLanguages[i] != NULL; i++) {
      if (strcmp(langCode, availableLanguages[i]) == 0) {
        strncpy(currentLanguage, langCode, sizeof(currentLanguage) - 1);
        break;
      }
    }
  }
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
