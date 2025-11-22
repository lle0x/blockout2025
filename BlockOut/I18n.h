/*
   File:        I18n.h
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

#ifndef _I18NH_
#define _I18NH_

#ifdef ENABLE_NLS
  #include <libintl.h>
  #include <locale.h>
  #define _(String) gettext(String)
  #define N_(String) String
#else
  #define _(String) (String)
  #define N_(String) String
  #define textdomain(Domain)
  #define bindtextdomain(Package, Directory)
#endif

// Initialize internationalization
void InitI18n();

// Set language (e.g., "es", "pt", "fr", "en")
void SetLanguage(const char* lang);

// Get current language code
const char* GetCurrentLanguage();

// Get list of available languages
const char** GetAvailableLanguages(int* count);

// Get current language display name
const char* GetLanguageName();

// Get display name for a language code
const char* GetLanguageDisplayName(const char* langCode);

// Get localized asset path
const char* GetLocalizedAsset(const char* assetName);

#endif
