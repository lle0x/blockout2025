# BlockOut II v2.5

![BlockOut II Gameplay](../gameplay-screenshot.png)

**Et 3D Tetris-lignende puslespill**

BlockOut II er en OpenGL-tilpasning av det originale BlockOut DOS-spillet utgitt av California Dreams i 1989. BlockOut II har de samme funksjonene som det originale spillet med noen grafiske forbedringer. Poengberegning er også nesten lik det originale spillet. BlockOut II er designet av en avhengig spiller for avhengige spillere.

Ha det gøy med BlockOut II...

---

*Blockout® er et registrert varemerke tilhørende Kadon Enterprises, Inc., brukt med tillatelse. Dette amerikanske selskapet produserer praktiske sett med polycubes siden 1980. [www.gamepuzzles.com](http://www.gamepuzzles.com)*

---

## 🌐 Offisiell Hjemmeside

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
- [Norsk](README.no.md) (denne filen)
- [Čeština](README.cs.md)
- [Suomi](README.fi.md)
- [Svenska](README.sv.md)
- [Eesti](README.et.md)
- [Türkçe](README.tr.md)
- [Afrikaans](README.af.md)
- [العربية](README.ar.md)

## 📦 Nedlastinger

Få den nyeste versjonen for plattformen din fra [Releases-siden](https://github.com/lle0x/blockout2025/releases):

- **Windows**: `blockout-windows-*.zip` - Pakk ut og kjør `Blockout.exe`
- **Linux (Generisk)**: `blockout-linux-x64-*.tar.gz` - Pakk ut og kjør `./blockout/blockout`
- **macOS**: `blockout-macos-*.tar.gz` - Pakk ut og kjør binærfilen
- **Ubuntu/Debian**: `blockout_*.deb` - Installer med `sudo dpkg -i blockout_*.deb`
- **Fedora/RHEL**: `blockout-*.rpm` - Installer med `sudo dnf install blockout-*.rpm`
- **Arch Linux**: `blockout-*.pkg.tar.zst` - Installer med `sudo pacman -U blockout-*.pkg.tar.zst`

## 🎮 Systemkrav

### Windows
- OpenGL-støtte

### Linux
**Kjøretid:**
- `libgl1-mesa`
- `libglu1-mesa`
- `libxext6`
- `libsdl1.2`
- `libsdl-mixer1.2`

**Byggeavhengigheter:**
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

## 📝 Versjonshistorikk

### 2.5
- 64-bits støtte
- OpenGL brukes nå på både Linux og Windows
- Små grafiske forbedringer
- Forbedringer av øvingsmodus
- Forbedret demomodus (Bot-spiller spiller bedre)
- Lokal datamappe flyttet fra installasjonsmappe til "AppData"-mappe

### 2.4
- Lagt til rammebegrenser
- Lagt til demomodus
- Lagt til øvingsmodus
- Rettet avspillingsfeil
- Rettet tilfeldig generator (FLAT-blokksett)
- Rettet fullskjermsfeil (Linux)

### 2.3
- Lagt til spiller/rangnavn ved avspilling
- Nye tegnsettingstegn lagt til
- Liten effekt når rotasjon er blokkert
- Rettet "Kan ikke åpne blX.bl2replay for skriving"
- Ny stil (Marmor/Arkade)
- Rettet krasj ved trykking på [Esc]
- Hull-animasjon når spillet er over
- Hopp til Poengdetaljer-side etter spillets slutt
- Lagt til DOS blockout lydforhåndsinnstilling
- Ny randomizer

### 2.2
- NUMPAD-tastkontroll lagt til
- Blokkgjennomsiktighet konfigurerbar med glidebryter
- Avbryt menystart-demo med [Esc]
- Tomt hull (Flush) i poengdetaljer lagt til
- Online poengdatabase
- Avspilling
- Credits-side lagt til
- Andre mindre oppdateringer

### 2.1
- Rettet blokkfallsalgoritme
- Økt falltid litt
- Forbedret justering av bevegelseshastighet

### 2.0
- Første utgivelse

## 🔧 Bygging fra Kilde

### Ubuntu/Debian

**Automatisert:**
```bash
sudo ./install-ubuntu-deps.sh
./build-and-run.sh
```

**Manuell:**
```bash
# Installer avhengigheter
sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev \
  libxext-dev libsdl1.2-dev libsdl-mixer1.2-dev libasound2-dev

# Bygg ImageLib
make -C ImageLib/src

# Bygg BlockOut
make -C BlockOut _linux64=1 _release=1

# Kjør
cd BlockOut
./blockout
```

### Windows

1. Installer Microsoft Visual Studio 2022 (eller 2019/2017)
2. Installer SDL 1.2.15 utviklingsbiblioteker fra [libsdl.org](http://www.libsdl.org)
3. Installer SDL_mixer 1.2.12 utviklingsbiblioteker fra [libsdl.org](http://www.libsdl.org/projects/SDL_mixer/release-1.2.html)
4. Angi passende include- og lib-stier i prosjektegenskaper
5. Bygg løsningen

### macOS

```bash
# Installer avhengigheter via Homebrew
brew install sdl12-compat pkg-config

# Bygg SDL_mixer 1.2 fra kilde (se .github/workflows/build-macos-brew.yml)

# Bygg ImageLib
make -C ImageLib/src

# Bygg BlockOut
make -C BlockOut _macos=1

# Kjør
cd BlockOut
./blockout
```

## 🤖 GitHub Actions CI/CD

Dette repositoriet bruker GitHub Actions for automatisert bygging og utgivelse på alle plattformer.

### Tilgjengelige Arbeidsflyter

#### Bygge-arbeidsflyter (Automatisert)

- **`build-windows.yml`** - Bygger Windows x64 binærfiler
- **`build-macos-brew.yml`** - Bygger macOS binærfiler
- **`build-fedora-rpm.yml`** - Bygger RPM-pakker
- **`build-arch-pkg.yml`** - Bygger Arch Linux-pakker
- **`package-deb.yml`** - Bygger Debian-pakker

#### Utgivelsesarbeidsflyt (Manuell)

- **`create-release.yml`** - Oppretter en ny utgivelse

### Utgivelsesprosess

1. Sørg for at alle endringer er slått sammen til `development` og testet
2. Gå til GitHub Actions → "Create Release" arbeidsflyt
3. Klikk på "Run workflow"
4. Skriv inn versjonsnummer (f.eks. `v2.5.0`)
5. Arbeidsflyten vil slå sammen, tagge, bygge og gi ut

## 🎯 Spillfunksjoner

### Avspillingssystem
For hver høy poengsum du lager, opprettes en `.bl2replay`-fil i avspillingsmappen.

### Poengopplasting
Last opp dine høye poengsummer til online-databasen fra Poengdetaljer-siden.

### Randomizer
BlockOut II bruker en pose-randomizer som genererer en sekvens av alle mulige brikker tilfeldig permutert.

### Rammebegrenser
For å synkronisere animasjoner med monitorens vertikale blanking, velg VSync i rammebegrenser-innstillingene.

## 📜 Lisens

Dette programmet er fri programvare; du kan redistribuere det og/eller modifisere det under vilkårene i GNU General Public License.

## 👤 Forfatter

Jean-Luc PONS (jlp_38@yahoo.com)

## 🔗 Lenker

- [Offisiell Nettside](http://www.blockout.net/blockout2)
- [GitHub Repository](https://github.com/lle0x/blockout2025)
- [Kadon Enterprises](http://www.gamepuzzles.com)
