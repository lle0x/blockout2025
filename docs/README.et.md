# BlockOut II v2.5

![BlockOut II Gameplay](../gameplay-screenshot.png)

**3D Tetrise-laadne mõistatuste mäng**

BlockOut II on OpenGL-i kohandus originaalsest BlockOut DOS-mängust, mille andis välja California Dreams 1989. aastal. BlockOut II-l on samad funktsioonid kui originaalil mängul koos mõningate graafiliste täiustustega. Punktide arvutamine on samuti peaaegu sarnane originaalmänguga. BlockOut II on loodud sõltuvuse all oleva mängija poolt sõltuvuse all olevatele mängijatele.

Lõbutse BlockOut II-ga...

---

*Blockout® on Kadon Enterprises, Inc. registreeritud kaubamärk, mida kasutatakse loaga. See USA ettevõte toodab polükuubikute praktilisi komplekte alates 1980. aastast. [www.gamepuzzles.com](http://www.gamepuzzles.com)*

---

## 🌐 Ametlik Koduleht

**http://www.blockout.net/blockout2**

## 🌍 Keeled / Idiomas / Langues

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
- [Eesti](README.et.md) (see fail)
- [Türkçe](README.tr.md)
- [Afrikaans](README.af.md)
- [العربية](README.ar.md)

## 📦 Allalaadimised

Hankige oma platvormile uusim versioon [Väljalasete lehelt](https://github.com/lle0x/blockout2025/releases):

- **Windows**: `blockout-windows-*.zip` - Pakkige lahti ja käivitage `Blockout.exe`
- **Linux (Üldine)**: `blockout-linux-x64-*.tar.gz` - Pakkige lahti ja käivitage `./blockout/blockout`
- **macOS**: `blockout-macos-*.tar.gz` - Pakkige lahti ja käivitage binaarfail
- **Ubuntu/Debian**: `blockout_*.deb` - Installige käsuga `sudo dpkg -i blockout_*.deb`
- **Fedora/RHEL**: `blockout-*.rpm` - Installige käsuga `sudo dnf install blockout-*.rpm`
- **Arch Linux**: `blockout-*.pkg.tar.zst` - Installige käsuga `sudo pacman -U blockout-*.pkg.tar.zst`

## 🎮 Süsteeminõuded

### Windows
- OpenGL tugi

### Linux
**Käitusaeg:**
- `libgl1-mesa`
- `libglu1-mesa`
- `libxext6`
- `libsdl1.2`
- `libsdl-mixer1.2`

**Ehitussõltuvused:**
- `build-essential`
- `libgl1-mesa-dev`
- `libglu1-mesa-dev`
- `libxext-dev`
- `libsdl1.2-dev`
- `libsdl-mixer1.2-dev`
- `libasound2-dev`

### macOS
- SDL 1.2 (sdl12-compat kaudu)
- SDL_mixer 1.2
- OpenGL

## 📝 Versiooniajalugu

### 2.5
- 64-bitine tugi
- OpenGL-i kasutatakse nüüd nii Linuxis kui ka Windowsis
- Väikesed graafilised täiustused
- Harjutusrežiimi täiustused
- Täiustatud demo režiim (Bot mängija mängib paremini)
- Kohalik andmekataloog teisaldatud installimiskataloogist "AppData" kataloogi

### 2.4
- Lisatud kaadrisageduse piirang
- Lisatud demo režiim
- Lisatud harjutusrežiim
- Parandatud taasesituse viga
- Parandatud juhuslik generaator (FLAT plokkide komplekt)
- Parandatud täisekraani viga (Linux)

### 2.3
- Lisatud mängija/reitingu nimi taasesitamisel
- Lisatud uued kirjavahemärgid
- Väike efekt, kui pööramine on blokeeritud
- Parandatud "Ei saa avada blX.bl2replay kirjutamiseks"
- Uus stiil (Marmor/Arkaad)
- Parandatud krahh [Esc] vajutamisel
- Augu animatsioon, kui mäng on läbi
- Hüppa Punktide Üksikasjad lehele pärast mängu lõppu
- Lisatud DOS blockout heli eelseadistus
- Uus juhuslikustaja

### 2.2
- Lisatud NUMPAD klahvide juhtimine
- Plokkide läbipaistvus seadistatav liuguriga
- Katkesta menüü käivitamise demo [Esc]-ga
- Lisatud tühi auk (Flush) punktide üksikasjadesse
- Veebipõhine punktide andmebaas
- Taasesitus
- Lisatud autorite leht
- Muud väiksemad uuendused

### 2.1
- Parandatud plokkide languse algoritm
- Veidi suurendatud languse aega
- Täiustatud liikumiskiiruse häälestamine

### 2.0
- Esialgne väljalase

## 🔧 Ehitamine Lähtekoodist

### Ubuntu/Debian

**Automatiseeritud:**
```bash
sudo ./install-ubuntu-deps.sh
./build-and-run.sh
```

**Käsitsi:**
```bash
# Installige sõltuvused
sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev \
  libxext-dev libsdl1.2-dev libsdl-mixer1.2-dev libasound2-dev

# Ehitage ImageLib
make -C ImageLib/src

# Ehitage BlockOut
make -C BlockOut _linux64=1 _release=1

# Käivitage
cd BlockOut
./blockout
```

### Windows

1. Installige Microsoft Visual Studio 2022 (või 2019/2017)
2. Installige SDL 1.2.15 arendusteegid [libsdl.org](http://www.libsdl.org)
3. Installige SDL_mixer 1.2.12 arendusteegid [libsdl.org](http://www.libsdl.org/projects/SDL_mixer/release-1.2.html)
4. Määrake sobivad include ja lib teed projekti omadustes
5. Ehitage lahendus

### macOS

```bash
# Installige sõltuvused Homebrew kaudu
brew install sdl12-compat pkg-config

# Ehitage SDL_mixer 1.2 lähtekoodist (vt .github/workflows/build-macos-brew.yml)

# Ehitage ImageLib
make -C ImageLib/src

# Ehitage BlockOut
make -C BlockOut _macos=1

# Käivitage
cd BlockOut
./blockout
```

## 🤖 GitHub Actions CI/CD

See hoidla kasutab GitHub Actionsi automatiseeritud ehitamiseks ja väljalaskmiseks kõigil platvormidel.

### Saadaolevad Töövood

#### Ehitustöövood (Automatiseeritud)

- **`build-windows.yml`** - Ehitab Windows x64 binaarfailid
- **`build-macos-brew.yml`** - Ehitab macOS binaarfailid
- **`build-fedora-rpm.yml`** - Ehitab RPM paketid
- **`build-arch-pkg.yml`** - Ehitab Arch Linux paketid
- **`package-deb.yml`** - Ehitab Debian paketid

#### Väljalasketöövoog (Käsitsi)

- **`create-release.yml`** - Loob uue väljalaskeandmise

### Väljalaskeprotsess

1. Veenduge, et kõik muudatused on ühendatud `development`-ga ja testitud
2. Minge GitHub Actions → "Create Release" töövoog
3. Klõpsake "Run workflow"
4. Sisestage versiooninumber (nt `v2.5.0`)
5. Töövoog ühendab, märgistab, ehitab ja laseb välja

## 🎯 Mängu Funktsioonid

### Taasesitussüsteem
Iga kõrge punktisumma kohta luuakse taasesituskataloogi `.bl2replay` fail.

### Punktide Üleslaadimine
Laadige oma kõrged punktisummad veebipõhisesse andmebaasi Punktide Üksikasjad lehelt.

### Juhuslikustaja
BlockOut II kasutab koti juhuslikustajat, mis genereerib kõigi võimalike tükkide juhuslikult permuteeritud järjestuse.

### Kaadrisageduse Piirang
Animatsioonide sünkroniseerimiseks monitori vertikaalse kustutamisega valige VSync kaadrisageduse piirangu seadetes.

## 📜 Litsents

See programm on vaba tarkvara; saate seda levitada ja/või muuta GNU General Public License tingimuste kohaselt.

## 👤 Autor

Jean-Luc PONS (jlp_38@yahoo.com)

## 🔗 Lingid

- [Ametlik Veebisait](http://www.blockout.net/blockout2)
- [GitHub Hoidla](https://github.com/lle0x/blockout2025)
- [Kadon Enterprises](http://www.gamepuzzles.com)
