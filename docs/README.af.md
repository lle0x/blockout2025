# BlockOut II v2.5

![BlockOut II Gameplay](../gameplay-screenshot.png)

**'n 3D Tetris-styl legkaartspel**

BlockOut II is 'n OpenGL-aanpassing van die oorspronklike BlockOut DOS-spel wat in 1989 deur California Dreams uitgegee is. BlockOut II het dieselfde kenmerke as die oorspronklike spel met 'n paar grafiese verbeterings. Puntberekening is ook byna soortgelyk aan die oorspronklike spel. BlockOut II is ontwerp deur 'n verslaafde speler vir verslaafde spelers.

Geniet BlockOut II...

---

*Blockout® is 'n geregistreerde handelsmerk van Kadon Enterprises, Inc., gebruik met toestemming. Hierdie Amerikaanse maatskappy produseer praktiese stelle polikubusse sedert 1980. [www.gamepuzzles.com](http://www.gamepuzzles.com)*

---

## 🌐 Amptelike Tuisblad

**http://www.blockout.net/blockout2**

## 🌍 Tale / Idiomas / Langues

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
- [Svenska](README.sv.md)
- [Eesti](README.et.md)
- [Türkçe](README.tr.md)
- [Afrikaans](README.af.md) (hierdie lêer)
- [العربية](README.ar.md)

## 📦 Aflaaie

Kry die nuutste weergawe vir jou platform vanaf die [Vrystellings-bladsy](https://github.com/lle0x/blockout2025/releases):

- **Windows**: `blockout-windows-*.zip` - Pak uit en hardloop `Blockout.exe`
- **Linux (Generies)**: `blockout-linux-x64-*.tar.gz` - Pak uit en hardloop `./blockout/blockout`
- **macOS**: `blockout-macos-*.tar.gz` - Pak uit en hardloop die binêre lêer
- **Ubuntu/Debian**: `blockout_*.deb` - Installeer met `sudo dpkg -i blockout_*.deb`
- **Fedora/RHEL**: `blockout-*.rpm` - Installeer met `sudo dnf install blockout-*.rpm`
- **Arch Linux**: `blockout-*.pkg.tar.zst` - Installeer met `sudo pacman -U blockout-*.pkg.tar.zst`

## 🎮 Stelselvereistes

### Windows
- OpenGL-ondersteuning

### Linux
**Looptyd:**
- `libgl1-mesa`
- `libglu1-mesa`
- `libxext6`
- `libsdl1.2`
- `libsdl-mixer1.2`

**Bou-afhanklikhede:**
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

## 📝 Weergawegeskiedenis

### 2.5
- 64-bis ondersteuning
- OpenGL word nou op beide Linux en Windows gebruik
- Klein grafiese verbeterings
- Oefenmodus verbeterings
- Verbeterde demo-modus (Bot-speler speel beter)
- Plaaslike datagids verskuif van installasiegids na "AppData"-gids

### 2.4
- Raambeperkaar bygevoeg
- Demo-modus bygevoeg
- Oefenmodus bygevoeg
- Herspeel-fout reggemaak
- Ewekansige generator reggemaak (FLAT-blokstel)
- Volskerm-fout reggemaak (Linux)

### 2.3
- Speler/rangorde naam bygevoeg tydens herspeel
- Nuwe leestekens bygevoeg
- Klein effek wanneer rotasie geblokkeer is
- "Kan nie blX.bl2replay oopmaak vir skryf nie" reggemaak
- Nuwe styl (Marmer/Arcade)
- Ineenstorting by druk van [Esc] reggemaak
- Put-animasie wanneer die spel verby is
- Spring na Puntbesonderhede-bladsy na einde van spel
- DOS blockout klankvoorinstelling bygevoeg
- Nuwe ewekansigmaker

### 2.2
- NUMPAD-sleutelbeheer bygevoeg
- Blok-deursigtigheid instelbaar met skuifbalk
- Kanselleer kieslys-begin demo met [Esc]
- Leë put (Flush) in puntbesonderhede bygevoeg
- Aanlyn puntedatabasis
- Herspeel
- Krediete-bladsy bygevoeg
- Ander klein opdaterings

### 2.1
- Blokdaal-algoritme reggemaak
- Valtyd effens verhoog
- Verbeterde instelling van bewegingspoed

### 2.0
- Aanvanklike vrystelling

## 🔧 Bou vanaf Bronkode

### Ubuntu/Debian

**Outomaties:**
```bash
sudo ./install-ubuntu-deps.sh
./build-and-run.sh
```

**Handmatig:**
```bash
# Installeer afhanklikhede
sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev \
  libxext-dev libsdl1.2-dev libsdl-mixer1.2-dev libasound2-dev

# Bou ImageLib
make -C ImageLib/src

# Bou BlockOut
make -C BlockOut _linux64=1 _release=1

# Hardloop
cd BlockOut
./blockout
```

### Windows

1. Installeer Microsoft Visual Studio 2022 (of 2019/2017)
2. Installeer SDL 1.2.15 ontwikkelingsbiblioteke vanaf [libsdl.org](http://www.libsdl.org)
3. Installeer SDL_mixer 1.2.12 ontwikkelingsbiblioteke vanaf [libsdl.org](http://www.libsdl.org/projects/SDL_mixer/release-1.2.html)
4. Stel toepaslike include- en lib-paaie in projekeienskappe in
5. Bou die oplossing

### macOS

```bash
# Installeer afhanklikhede via Homebrew
brew install sdl12-compat pkg-config

# Bou SDL_mixer 1.2 vanaf bron (sien .github/workflows/build-macos-brew.yml)

# Bou ImageLib
make -C ImageLib/src

# Bou BlockOut
make -C BlockOut _macos=1

# Hardloop
cd BlockOut
./blockout
```

## 🤖 GitHub Actions CI/CD

Hierdie bewaarplek gebruik GitHub Actions vir outomatiese bou en vrystelling op alle platforms.

### Beskikbare Werkvloeie

#### Bou-werkvloeie (Outomaties)

- **`build-windows.yml`** - Bou Windows x64-binêre lêers
- **`build-macos-brew.yml`** - Bou macOS-binêre lêers
- **`build-fedora-rpm.yml`** - Bou RPM-pakkette
- **`build-arch-pkg.yml`** - Bou Arch Linux-pakkette
- **`package-deb.yml`** - Bou Debian-pakkette

#### Vrystellingswerkvloei (Handmatig)

- **`create-release.yml`** - Skep 'n nuwe vrystelling

### Vrystellingsproses

1. Maak seker alle veranderinge is saamgevoeg na `development` en getoets
2. Gaan na GitHub Actions → "Create Release"-werkvloei
3. Klik op "Run workflow"
4. Voer die weergawenommer in (bv. `v2.5.0`)
5. Die werkvloei sal saamvoeg, merk, bou en vrystel

## 🎯 Spelkenmerke

### Herspeelstelsel
Vir elke hoë telling wat jy maak, word 'n `.bl2replay`-lêer in die herspeel-gids geskep.

### Puntoplaai
Laai jou hoë tellings op na die aanlyn databasis vanaf die Puntbesonderhede-bladsy.

### Ewekansigmaker
BlockOut II gebruik 'n sak-ewekansigmaker wat 'n reeks van alle moontlike stukke ewekansig gepermuteer genereer.

### Raambeperkaar
Om animasies te sinkroniseer met jou monitor se vertikale uitwissing, kies VSync in die raambeperkaar-instellings.

## 📜 Lisensie

Hierdie program is gratis sagteware; jy kan dit herversprei en/of wysig onder die terme van die GNU General Public License.

## 👤 Outeur

Jean-Luc PONS (jlp_38@yahoo.com)

## 🔗 Skakels

- [Amptelike Webwerf](http://www.blockout.net/blockout2)
- [GitHub-bewaarplek](https://github.com/lle0x/blockout2025)
- [Kadon Enterprises](http://www.gamepuzzles.com)
