# BlockOut II v2.5

![BlockOut II Gameplay](../gameplay-screenshot.png)

**3D puzzle hra ve stylu Tetris**

BlockOut II je OpenGL adaptace původní hry BlockOut pro DOS vydané společností California Dreams v roce 1989. BlockOut II má stejné funkce jako původní hra s několika grafickými vylepšeními. Výpočet skóre je také téměř podobný původní hře. BlockOut II byl navržen závislým hráčem pro závislé hráče.

Bavte se s BlockOut II...

---

*Blockout® je registrovaná ochranná známka společnosti Kadon Enterprises, Inc., používaná se svolením. Tato americká společnost vyrábí praktické sady polykrychlí od roku 1980. [www.gamepuzzles.com](http://www.gamepuzzles.com)*

---

## 🌐 Oficiální Domovská Stránka

**http://www.blockout.net/blockout2**

## 🌍 Jazyky / Idiomas / Langues

- [English](../README.md)
- [Español](README.es.md)
- [Português](README.pt.md)
- [Français](README.fr.md)
- [Italiano](README.it.md)
- [Deutsch](README.de.md)
- [Polski](README.pl.md)
- [Română](README.ro.md)
- [中文](README.zh.md)
- [日本語](README.ja.md)
- [Gaeilge](README.ga.md)
- [Ελληνικά](README.el.md)
- [Nederlands](README.nl.md)
- [Dansk](README.da.md)
- [Català](README.ca.md)
- [Norsk](README.no.md)
- [Čeština](README.cs.md) (tento soubor)
- [Suomi](README.fi.md)
- [Svenska](README.sv.md)
- [Eesti](README.et.md)
- [Türkçe](README.tr.md)
- [Afrikaans](README.af.md)
- [العربية](README.ar.md)

## 📦 Stažení

Získejte nejnovější verzi pro vaši platformu ze [stránky Vydání](https://github.com/lle0x/blockout2025/releases):

- **Windows**: `blockout-windows-*.zip` - Rozbalte a spusťte `Blockout.exe`
- **Linux (Obecný)**: `blockout-linux-x64-*.tar.gz` - Rozbalte a spusťte `./blockout/blockout`
- **macOS**: `blockout-macos-*.tar.gz` - Rozbalte a spusťte binární soubor
- **Ubuntu/Debian**: `blockout_*.deb` - Nainstalujte pomocí `sudo dpkg -i blockout_*.deb`
- **Fedora/RHEL**: `blockout-*.rpm` - Nainstalujte pomocí `sudo dnf install blockout-*.rpm`
- **Arch Linux**: `blockout-*.pkg.tar.zst` - Nainstalujte pomocí `sudo pacman -U blockout-*.pkg.tar.zst`

## 🎮 Systémové Požadavky

### Windows
- Podpora OpenGL

### Linux
**Běhové prostředí:**
- `libgl1-mesa`
- `libglu1-mesa`
- `libxext6`
- `libsdl1.2`
- `libsdl-mixer1.2`

**Závislosti pro sestavení:**
- `build-essential`
- `libgl1-mesa-dev`
- `libglu1-mesa-dev`
- `libxext-dev`
- `libsdl1.2-dev`
- `libsdl-mixer1.2-dev`
- `libasound2-dev`

### macOS
- SDL 1.2 (přes sdl12-compat)
- SDL_mixer 1.2
- OpenGL

## 📝 Historie Verzí

### 2.5
- Podpora 64-bit
- OpenGL se nyní používá na Linuxu i Windows
- Malá grafická vylepšení
- Vylepšení režimu cvičení
- Vylepšený demo režim (Bot hráč hraje lépe)
- Místní datový adresář přesunut z instalačního adresáře do adresáře "AppData"

### 2.4
- Přidán omezovač snímků
- Přidán demo režim
- Přidán režim cvičení
- Opravena chyba přehrávání
- Opraven náhodný generátor (sada bloků FLAT)
- Opravena chyba celé obrazovky (Linux)

### 2.3
- Přidáno jméno hráče/pořadí při přehrávání
- Přidány nové interpunkční znaky
- Malý efekt při blokované rotaci
- Opraveno "Nelze otevřít blX.bl2replay pro zápis"
- Nový styl (Mramor/Arkáda)
- Opraven pád při stisknutí [Esc]
- Animace jámy po skončení hry
- Přechod na stránku Podrobnosti Skóre po skončení hry
- Přidána předvolba zvuku DOS blockout
- Nový randomizér

### 2.2
- Přidáno ovládání klávesami NUMPAD
- Průhlednost bloků konfigurovatelná posuvníkem
- Přerušení demo startu menu pomocí [Esc]
- Přidána prázdná jáma (Flush) v podrobnostech skóre
- Online databáze skóre
- Přehrávání
- Přidána stránka s titulky
- Další drobné aktualizace

### 2.1
- Opraven algoritmus sestupu bloků
- Mírně zvýšen čas pádu
- Vylepšeno ladění rychlosti pohybu

### 2.0
- Počáteční vydání

## 🔧 Sestavení ze Zdrojového Kódu

### Ubuntu/Debian

**Automatizované:**
```bash
sudo ./install-ubuntu-deps.sh
./build-and-run.sh
```

**Ruční:**
```bash
# Nainstalujte závislosti
sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev \
  libxext-dev libsdl1.2-dev libsdl-mixer1.2-dev libasound2-dev

# Sestavte ImageLib
make -C ImageLib/src

# Sestavte BlockOut
make -C BlockOut _linux64=1 _release=1

# Spusťte
cd BlockOut
./blockout
```

### Windows

1. Nainstalujte Microsoft Visual Studio 2022 (nebo 2019/2017)
2. Nainstalujte vývojové knihovny SDL 1.2.15 z [libsdl.org](http://www.libsdl.org)
3. Nainstalujte vývojové knihovny SDL_mixer 1.2.12 z [libsdl.org](http://www.libsdl.org/projects/SDL_mixer/release-1.2.html)
4. Nastavte příslušné cesty include a lib ve vlastnostech projektu
5. Sestavte řešení

### macOS

```bash
# Nainstalujte závislosti přes Homebrew
brew install sdl12-compat pkg-config

# Sestavte SDL_mixer 1.2 ze zdroje (viz .github/workflows/build-macos-brew.yml)

# Sestavte ImageLib
make -C ImageLib/src

# Sestavte BlockOut
make -C BlockOut _macos=1

# Spusťte
cd BlockOut
./blockout
```

## 🤖 GitHub Actions CI/CD

Toto úložiště používá GitHub Actions pro automatizované sestavování a vydávání na všech platformách.

### Dostupné Pracovní Postupy

#### Pracovní Postupy Sestavení (Automatizované)

- **`build-windows.yml`** - Sestavuje binární soubory Windows x64
- **`build-macos-brew.yml`** - Sestavuje binární soubory macOS
- **`build-fedora-rpm.yml`** - Sestavuje balíčky RPM
- **`build-arch-pkg.yml`** - Sestavuje balíčky Arch Linux
- **`package-deb.yml`** - Sestavuje balíčky Debian

#### Pracovní Postup Vydání (Ruční)

- **`create-release.yml`** - Vytváří nové vydání

### Proces Vydání

1. Ujistěte se, že všechny změny jsou sloučeny do `development` a otestovány
2. Přejděte na GitHub Actions → Pracovní postup "Create Release"
3. Klikněte na "Run workflow"
4. Zadejte číslo verze (např. `v2.5.0`)
5. Pracovní postup sloučí, označí, sestaví a vydá

## 🎯 Herní Funkce

### Systém Přehrávání
Pro každé vysoké skóre, které vytvoříte, se vytvoří soubor `.bl2replay` v adresáři přehrávání.

### Nahrávání Skóre
Nahrajte svá vysoká skóre do online databáze ze stránky Podrobnosti Skóre.

### Randomizér
BlockOut II používá pytlový randomizér, který generuje sekvenci všech možných dílů náhodně permutovaných.

### Omezovač Snímků
Pro synchronizaci animací s vertikálním blanking monitoru vyberte VSync v nastavení omezovače snímků.

## 📜 Licence

Tento program je svobodný software; můžete jej redistribuovat a/nebo upravovat podle podmínek GNU General Public License.

## 👤 Autor

Jean-Luc PONS (jlp_38@yahoo.com)

## 🔗 Odkazy

- [Oficiální Webová Stránka](http://www.blockout.net/blockout2)
- [GitHub Úložiště](https://github.com/lle0x/blockout2025)
- [Kadon Enterprises](http://www.gamepuzzles.com)
