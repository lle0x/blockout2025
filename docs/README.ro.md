# BlockOut II v2.5

![BlockOut II Gameplay](../gameplay-screenshot.png)

**Un joc de puzzle 3D stil Tetris**

BlockOut II este o adaptare OpenGL a jocului original BlockOut pentru DOS editat de California Dreams în 1989. BlockOut II are aceleași caracteristici ca jocul original, cu câteva îmbunătățiri grafice. Calculul scorului este, de asemenea, aproape similar cu jocul original. BlockOut II a fost conceput de un jucător dependent pentru jucători dependenți.

Distracție plăcută cu BlockOut II...

---

*Blockout® este o marcă înregistrată a Kadon Enterprises, Inc., utilizată cu permisiune. Această companie din SUA produce seturi practice de policuburi din 1980. [www.gamepuzzles.com](http://www.gamepuzzles.com)*

---

## 🌐 Pagina Oficială

**http://www.blockout.net/blockout2**

## 🌍 Limbi / Idiomas / Langues

- [English](../README.md)
- [Español](README.es.md)
- [Português](README.pt.md)
- [Français](README.fr.md)
- [Italiano](README.it.md)
- [Deutsch](README.de.md)
- [Polski](README.pl.md)
- [Română](README.ro.md) (acest fișier)
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
- [Afrikaans](README.af.md)
- [العربية](README.ar.md)

## 📦 Descărcări

Obțineți cea mai recentă versiune pentru platforma dvs. de pe [pagina de Lansări](https://github.com/lle0x/blockout2025/releases):

- **Windows**: `blockout-windows-*.zip` - Extrageți și rulați `Blockout.exe`
- **Linux (Generic)**: `blockout-linux-x64-*.tar.gz` - Extrageți și rulați `./blockout/blockout`
- **macOS**: `blockout-macos-*.tar.gz` - Extrageți și rulați binarul
- **Ubuntu/Debian**: `blockout_*.deb` - Instalați cu `sudo dpkg -i blockout_*.deb`
- **Fedora/RHEL**: `blockout-*.rpm` - Instalați cu `sudo dnf install blockout-*.rpm`
- **Arch Linux**: `blockout-*.pkg.tar.zst` - Instalați cu `sudo pacman -U blockout-*.pkg.tar.zst`

## 🎮 Cerințe de Sistem

### Windows
- Suport OpenGL

### Linux
**Runtime:**
- `libgl1-mesa`
- `libglu1-mesa`
- `libxext6`
- `libsdl1.2`
- `libsdl-mixer1.2`

**Dependențe de Compilare:**
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

## 📝 Istoric Versiuni

### 2.5
- Suport pe 64 de biți
- OpenGL este acum utilizat atât pe Linux, cât și pe Windows
- Mici îmbunătățiri grafice
- Îmbunătățiri ale modului de antrenament
- Mod demo îmbunătățit (jucătorul Bot joacă mai bine)
- Directorul de date locale mutat din directorul de instalare în directorul "AppData"

### 2.4
- Adăugat limitator de cadre
- Adăugat mod demo
- Adăugat mod de antrenament
- Corectat bug replay
- Corectat generator aleatoriu (set de blocuri FLAT)
- Corectat bug ecran complet (Linux)

### 2.3
- Adăugat nume jucător/rang la reluare
- Adăugate noi caractere de punctuație
- Efect mic când rotația este blocată
- Corectat "Nu se poate deschide blX.bl2replay pentru scriere"
- Stil nou (Marmură/Arcade)
- Corectat crash la apăsarea [Esc]
- Animație groapă când jocul s-a terminat
- Salt la pagina Detalii Scor după terminarea jocului
- Adăugat presetare sunet DOS blockout
- Randomizator nou

### 2.2
- Adăugat control taste NUMPAD
- Transparența blocurilor configurabilă cu glisor
- Anulare demo pornire meniu cu [Esc]
- Adăugată groapă goală (Flush) în detaliile scorului
- Bază de date scoruri on-line
- Replay
- Adăugată pagină credite
- Alte actualizări minore

### 2.1
- Corectat algoritm coborâre blocuri
- Timp de cădere crescut puțin
- Reglare îmbunătățită a vitezei de mișcare

### 2.0
- Versiune inițială

## 🔧 Compilare din Sursă

### Ubuntu/Debian

**Automat:**
```bash
sudo ./install-ubuntu-deps.sh
./build-and-run.sh
```

**Manual:**
```bash
# Instalați dependențe
sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev \
  libxext-dev libsdl1.2-dev libsdl-mixer1.2-dev libasound2-dev

# Compilați ImageLib
make -C ImageLib/src

# Compilați BlockOut
make -C BlockOut _linux64=1 _release=1

# Rulați
cd BlockOut
./blockout
```

### Windows

1. Instalați Microsoft Visual Studio 2022 (sau 2019/2017)
2. Instalați bibliotecile de dezvoltare SDL 1.2.15 de pe [libsdl.org](http://www.libsdl.org)
3. Instalați bibliotecile de dezvoltare SDL_mixer 1.2.12 de pe [libsdl.org](http://www.libsdl.org/projects/SDL_mixer/release-1.2.html)
4. Setați căile include și lib corespunzătoare în proprietățile proiectului
5. Compilați soluția

### macOS

```bash
# Instalați dependențe via Homebrew
brew install sdl12-compat pkg-config

# Compilați SDL_mixer 1.2 din sursă (vezi .github/workflows/build-macos-brew.yml)

# Compilați ImageLib
make -C ImageLib/src

# Compilați BlockOut
make -C BlockOut _macos=1

# Rulați
cd BlockOut
./blockout
```

## 🤖 GitHub Actions CI/CD

Acest depozit utilizează GitHub Actions pentru compilare și lansare automată pe toate platformele.

### Fluxuri de Lucru Disponibile

#### Fluxuri de Lucru de Compilare (Automate)

- **`build-windows.yml`** - Compilează binare Windows x64
- **`build-macos-brew.yml`** - Compilează binare macOS
- **`build-fedora-rpm.yml`** - Compilează pachete RPM
- **`build-arch-pkg.yml`** - Compilează pachete Arch Linux
- **`package-deb.yml`** - Compilează pachete Debian

#### Flux de Lucru de Lansare (Manual)

- **`create-release.yml`** - Creează o nouă lansare

### Proces de Lansare

1. Asigurați-vă că toate modificările sunt îmbinate în `development` și testate
2. Mergeți la GitHub Actions → Flux de lucru "Create Release"
3. Faceți clic pe "Run workflow"
4. Introduceți numărul versiunii (ex. `v2.5.0`)
5. Fluxul de lucru va îmbina, eticheta, compila și lansa

## 🎯 Caracteristici Joc

### Sistem de Replay
Pentru fiecare scor mare pe care îl faceți, se creează un fișier `.bl2replay` în directorul de reluări.

### Încărcare Scoruri
Încărcați scorurile mari în baza de date online din pagina Detalii Scor.

### Randomizator
BlockOut II folosește un randomizator sac care generează o secvență a tuturor pieselor posibile permutate aleatoriu.

### Limitator de Cadre
Pentru a sincroniza animațiile cu blanking-ul vertical al monitorului, selectați VSync în setările limitatorului de cadre.

## 📜 Licență

Acest program este software liber; îl puteți redistribui și/sau modifica în conformitate cu termenii Licenței Publice Generale GNU.

## 👤 Autor

Jean-Luc PONS (jlp_38@yahoo.com)

## 🔗 Link-uri

- [Site Oficial](http://www.blockout.net/blockout2)
- [Depozit GitHub](https://github.com/lle0x/blockout2025)
- [Kadon Enterprises](http://www.gamepuzzles.com)
