# BlockOut II v2.5

![BlockOut II Gameplay](../gameplay-screenshot.png)

**Een 3D Tetris-achtig puzzelspel**

BlockOut II is een OpenGL-aanpassing van het originele BlockOut DOS-spel uitgegeven door California Dreams in 1989. BlockOut II heeft dezelfde functies als het originele spel met enkele grafische verbeteringen. De scoreberekening is ook bijna vergelijkbaar met het originele spel. BlockOut II is ontworpen door een verslaafde speler voor verslaafde spelers.

Veel plezier met BlockOut II...

---

*Blockout® is een geregistreerd handelsmerk van Kadon Enterprises, Inc., gebruikt met toestemming. Dit Amerikaanse bedrijf produceert sinds 1980 praktische sets polycubes. [www.gamepuzzles.com](http://www.gamepuzzles.com)*

---

## 🌐 Officiële Homepage

**http://www.blockout.net/blockout2**

## 🌍 Talen / Idiomas / Langues

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
- [Nederlands](README.nl.md) (dit bestand)
- [Dansk](README.da.md)
- [Català](README.ca.md)
- [Norsk](README.no.md)
- [Čeština](README.cs.md)
- [Suomi](README.fi.md)
- [Svenska](README.sv.md)
- [Eesti](README.et.md)
- [Türkçe](README.tr.md)
- [Afrikaans](README.af.md)
- [العربية](README.ar.md)

## 📦 Downloads

Download de nieuwste versie voor uw platform van de [Releases-pagina](https://github.com/lle0x/blockout2025/releases):

- **Windows**: `blockout-windows-*.zip` - Uitpakken en `Blockout.exe` uitvoeren
- **Linux (Algemeen)**: `blockout-linux-x64-*.tar.gz` - Uitpakken en `./blockout/blockout` uitvoeren
- **macOS**: `blockout-macos-*.tar.gz` - Uitpakken en het binaire bestand uitvoeren
- **Ubuntu/Debian**: `blockout_*.deb` - Installeren met `sudo dpkg -i blockout_*.deb`
- **Fedora/RHEL**: `blockout-*.rpm` - Installeren met `sudo dnf install blockout-*.rpm`
- **Arch Linux**: `blockout-*.pkg.tar.zst` - Installeren met `sudo pacman -U blockout-*.pkg.tar.zst`

## 🎮 Systeemvereisten

### Windows
- OpenGL-ondersteuning

### Linux
**Runtime:**
- `libgl1-mesa`
- `libglu1-mesa`
- `libxext6`
- `libsdl1.2`
- `libsdl-mixer1.2`

**Build-afhankelijkheden:**
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

## 📝 Versiegeschiedenis

### 2.5
- 64-bit ondersteuning
- OpenGL wordt nu gebruikt op zowel Linux als Windows
- Kleine grafische verbeteringen
- Verbeteringen in de oefenmodus
- Verbeterde demomodus (Bot-speler speelt beter)
- Lokale gegevensmap verplaatst van installatiemap naar "AppData"-map

### 2.4
- Frame limiter toegevoegd
- Demomodus toegevoegd
- Oefenmodus toegevoegd
- Replay-bug opgelost
- Willekeurige generator opgelost (FLAT-blokset)
- Volledig scherm bug opgelost (Linux)

### 2.3
- Speler/rangnaam toegevoegd bij herhaling
- Nieuwe leestekens toegevoegd
- Klein effect wanneer rotatie geblokkeerd is
- "Kan blX.bl2replay niet openen voor schrijven" opgelost
- Nieuwe stijl (Marmer/Arcade)
- Crash bij drukken op [Esc] opgelost
- Put-animatie wanneer het spel voorbij is
- Spring naar Score Details-pagina na einde van het spel
- DOS blockout geluidsvoorinstelling toegevoegd
- Nieuwe randomizer

### 2.2
- NUMPAD-toetsenbediening toegevoegd
- Bloktransparantie configureerbaar met schuifregelaar
- Menu-startdemo afbreken met [Esc]
- Lege put (Flush) in scoredetails toegevoegd
- Online scoredatabase
- Herhaling
- Credits-pagina toegevoegd
- Andere kleine updates

### 2.1
- Blokdalingsalgoritme opgelost
- Valtijd iets verhoogd
- Verbeterde afstemming van bewegingssnelheid

### 2.0
- Eerste release

## 🔧 Bouwen vanuit Bron

### Ubuntu/Debian

**Geautomatiseerd:**
```bash
sudo ./install-ubuntu-deps.sh
./build-and-run.sh
```

**Handmatig:**
```bash
# Installeer afhankelijkheden
sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev \
  libxext-dev libsdl1.2-dev libsdl-mixer1.2-dev libasound2-dev

# Bouw ImageLib
make -C ImageLib/src

# Bouw BlockOut
make -C BlockOut _linux64=1 _release=1

# Uitvoeren
cd BlockOut
./blockout
```

### Windows

1. Installeer Microsoft Visual Studio 2022 (of 2019/2017)
2. Installeer SDL 1.2.15 ontwikkelingsbibliotheken van [libsdl.org](http://www.libsdl.org)
3. Installeer SDL_mixer 1.2.12 ontwikkelingsbibliotheken van [libsdl.org](http://www.libsdl.org/projects/SDL_mixer/release-1.2.html)
4. Stel geschikte include- en lib-paden in projecteigenschappen in
5. Bouw de oplossing

### macOS

```bash
# Installeer afhankelijkheden via Homebrew
brew install sdl12-compat pkg-config

# Bouw SDL_mixer 1.2 vanuit bron (zie .github/workflows/build-macos-brew.yml)

# Bouw ImageLib
make -C ImageLib/src

# Bouw BlockOut
make -C BlockOut _macos=1

# Uitvoeren
cd BlockOut
./blockout
```

## 🤖 GitHub Actions CI/CD

Deze repository gebruikt GitHub Actions voor geautomatiseerd bouwen en uitbrengen op alle platforms.

### Beschikbare Workflows

#### Build Workflows (Geautomatiseerd)

- **`build-windows.yml`** - Bouwt Windows x64 binaries
- **`build-macos-brew.yml`** - Bouwt macOS binaries
- **`build-fedora-rpm.yml`** - Bouwt RPM-pakketten
- **`build-arch-pkg.yml`** - Bouwt Arch Linux-pakketten
- **`package-deb.yml`** - Bouwt Debian-pakketten

#### Release Workflow (Handmatig)

- **`create-release.yml`** - Maakt een nieuwe release

### Release Proces

1. Zorg ervoor dat alle wijzigingen zijn samengevoegd met `development` en getest
2. Ga naar GitHub Actions → "Create Release" workflow
3. Klik op "Run workflow"
4. Voer het versienummer in (bijv. `v2.5.0`)
5. De workflow zal samenvoegen, taggen, bouwen en uitbrengen

## 🎯 Spelfuncties

### Replay Systeem
Voor elke hoge score die je maakt, wordt een `.bl2replay`-bestand aangemaakt in de replay-map.

### Score Uploaden
Upload je hoge scores naar de online database vanaf de Score Details-pagina.

### Randomizer
BlockOut II gebruikt een zak-randomizer die een reeks van alle mogelijke stukken willekeurig gepermuteerd genereert.

### Frame Limiter
Om animaties te synchroniseren met de verticale blanking van je monitor, selecteer VSync in de frame limiter-instellingen.

## 📜 Licentie

Dit programma is vrije software; u kunt het herdistribueren en/of wijzigen onder de voorwaarden van de GNU General Public License.

## 👤 Auteur

Jean-Luc PONS (jlp_38@yahoo.com)

## 🔗 Links

- [Officiële Website](http://www.blockout.net/blockout2)
- [GitHub Repository](https://github.com/lle0x/blockout2025)
- [Kadon Enterprises](http://www.gamepuzzles.com)
