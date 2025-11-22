# BlockOut II v2.5

![BlockOut II Gameplay](../gameplay-screenshot.png)

**Ett 3D Tetris-liknande pusselspel**

BlockOut II är en OpenGL-anpassning av det ursprungliga BlockOut DOS-spelet som gavs ut av California Dreams 1989. BlockOut II har samma funktioner som originalspelet med några grafiska förbättringar. Poängberäkningen är också nästan identisk med originalspelet. BlockOut II har designats av en beroende spelare för beroende spelare.

Ha kul med BlockOut II...

---

*Blockout® är ett registrerat varumärke som tillhör Kadon Enterprises, Inc., använt med tillstånd. Detta amerikanska företag producerar praktiska uppsättningar av polykuber sedan 1980. [www.gamepuzzles.com](http://www.gamepuzzles.com)*

---

## 🌐 Officiell Hemsida

**http://www.blockout.net/blockout2**

## 🌍 Språk / Idiomas / Langues

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
- [Čeština](README.cs.md)
- [Suomi](README.fi.md)
- [Svenska](README.sv.md) (denna fil)
- [Eesti](README.et.md)
- [Türkçe](README.tr.md)
- [Afrikaans](README.af.md)
- [العربية](README.ar.md)

## 📦 Nedladdningar

Hämta den senaste versionen för din plattform från [Releases-sidan](https://github.com/lle0x/blockout2025/releases):

- **Windows**: `blockout-windows-*.zip` - Packa upp och kör `Blockout.exe`
- **Linux (Generisk)**: `blockout-linux-x64-*.tar.gz` - Packa upp och kör `./blockout/blockout`
- **macOS**: `blockout-macos-*.tar.gz` - Packa upp och kör binärfilen
- **Ubuntu/Debian**: `blockout_*.deb` - Installera med `sudo dpkg -i blockout_*.deb`
- **Fedora/RHEL**: `blockout-*.rpm` - Installera med `sudo dnf install blockout-*.rpm`
- **Arch Linux**: `blockout-*.pkg.tar.zst` - Installera med `sudo pacman -U blockout-*.pkg.tar.zst`

## 🎮 Systemkrav

### Windows
- OpenGL-stöd

### Linux
**Körtid:**
- `libgl1-mesa`
- `libglu1-mesa`
- `libxext6`
- `libsdl1.2`
- `libsdl-mixer1.2`

**Byggberoenden:**
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

## 📝 Versionshistorik

### 2.5
- 64-bitars stöd
- OpenGL används nu på både Linux och Windows
- Små grafiska förbättringar
- Förbättringar av övningsläge
- Förbättrat demoläge (Bot-spelaren spelar bättre)
- Lokal datakatalog flyttad från installationskatalog till "AppData"-katalog

### 2.4
- Lagt till bildhastighets begränsare
- Lagt till demoläge
- Lagt till övningsläge
- Fixat uppspelningsfel
- Fixat slumpgenerator (FLAT-blockuppsättning)
- Fixat helskärmsfel (Linux)

### 2.3
- Lagt till spelar-/rankingnamn vid uppspelning
- Nya interpunktionstecken tillagda
- Liten effekt när rotation är blockerad
- Fixat "Kan inte öppna blX.bl2replay för skrivning"
- Ny stil (Marmor/Arkad)
- Fixat krasch vid tryck på [Esc]
- Gropanimation när spelet är över
- Hoppa till Poängdetaljer-sida efter spelets slut
- Lagt till DOS blockout ljudförinställning
- Ny slumpgenerator

### 2.2
- NUMPAD-tangentkontroll tillagd
- Blocktransparens konfigurerbar med skjutreglage
- Avbryt menystart-demo med [Esc]
- Tom grop (Flush) i poängdetaljer tillagd
- Online-poängdatabas
- Uppspelning
- Credits-sida tillagd
- Andra mindre uppdateringar

### 2.1
- Fixat blockfallsalgoritm
- Ökat falltid något
- Förbättrad justering av rörelsehastighet

### 2.0
- Första utgåvan

## 🔧 Bygga från Källkod

### Ubuntu/Debian

**Automatiserat:**
```bash
sudo ./install-ubuntu-deps.sh
./build-and-run.sh
```

**Manuellt:**
```bash
# Installera beroenden
sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev \
  libxext-dev libsdl1.2-dev libsdl-mixer1.2-dev libasound2-dev

# Bygg ImageLib
make -C ImageLib/src

# Bygg BlockOut
make -C BlockOut _linux64=1 _release=1

# Kör
cd BlockOut
./blockout
```

### Windows

1. Installera Microsoft Visual Studio 2022 (eller 2019/2017)
2. Installera SDL 1.2.15 utvecklingsbibliotek från [libsdl.org](http://www.libsdl.org)
3. Installera SDL_mixer 1.2.12 utvecklingsbibliotek från [libsdl.org](http://www.libsdl.org/projects/SDL_mixer/release-1.2.html)
4. Ange lämpliga include- och lib-sökvägar i projektegenskaper
5. Bygg lösningen

### macOS

```bash
# Installera beroenden via Homebrew
brew install sdl12-compat pkg-config

# Bygg SDL_mixer 1.2 från källkod (se .github/workflows/build-macos-brew.yml)

# Bygg ImageLib
make -C ImageLib/src

# Bygg BlockOut
make -C BlockOut _macos=1

# Kör
cd BlockOut
./blockout
```

## 🤖 GitHub Actions CI/CD

Detta arkiv använder GitHub Actions för automatiserad byggning och utgivning på alla plattformar.

### Tillgängliga Arbetsflöden

#### Byggarbetsflöden (Automatiserade)

- **`build-windows.yml`** - Bygger Windows x64-binärer
- **`build-macos-brew.yml`** - Bygger macOS-binärer
- **`build-fedora-rpm.yml`** - Bygger RPM-paket
- **`build-arch-pkg.yml`** - Bygger Arch Linux-paket
- **`package-deb.yml`** - Bygger Debian-paket

#### Utgivningsarbetsflöde (Manuellt)

- **`create-release.yml`** - Skapar en ny utgåva

### Utgivningsprocess

1. Se till att alla ändringar är sammanslagna till `development` och testade
2. Gå till GitHub Actions → "Create Release"-arbetsflöde
3. Klicka på "Run workflow"
4. Ange versionsnummer (t.ex. `v2.5.0`)
5. Arbetsflödet kommer att sammanslå, tagga, bygga och ge ut

## 🎯 Spelfunktioner

### Uppspelningssystem
För varje högt poäng du gör skapas en `.bl2replay`-fil i uppspelningskatalogen.

### Poänguppladdning
Ladda upp dina höga poäng till online-databasen från Poängdetaljer-sidan.

### Slumpgenerator
BlockOut II använder en påse-slumpgenerator som genererar en sekvens av alla möjliga bitar slumpmässigt permuterade.

### Bildhastighets Begränsare
För att synkronisera animationer med din monitors vertikala blankning, välj VSync i bildhastighets begränsarens inställningar.

## 📜 Licens

Detta program är fri programvara; du kan omfördela det och/eller modifiera det enligt villkoren i GNU General Public License.

## 👤 Författare

Jean-Luc PONS (jlp_38@yahoo.com)

## 🔗 Länkar

- [Officiell Webbplats](http://www.blockout.net/blockout2)
- [GitHub-arkiv](https://github.com/lle0x/blockout2025)
- [Kadon Enterprises](http://www.gamepuzzles.com)
