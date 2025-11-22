# BlockOut II v2.5

![BlockOut II Gameplay](../gameplay-screenshot.png)

**Ein 3D-Tetris-artiges Puzzlespiel**

BlockOut II ist eine OpenGL-Adaption des ursprünglichen BlockOut-DOS-Spiels, das 1989 von California Dreams herausgegeben wurde. BlockOut II hat die gleichen Funktionen wie das Originalspiel mit einigen grafischen Verbesserungen. Die Punkteberechnung ist auch fast identisch mit dem Originalspiel. BlockOut II wurde von einem süchtigen Spieler für süchtige Spieler entwickelt.

Viel Spaß mit BlockOut II...

---

*Blockout® ist eine eingetragene Marke von Kadon Enterprises, Inc., die mit Genehmigung verwendet wird. Dieses US-Unternehmen stellt seit 1980 praktische Sets von Polywürfeln her. [www.gamepuzzles.com](http://www.gamepuzzles.com)*

---

## 🌐 Offizielle Homepage

**http://www.blockout.net/blockout2**

## 🌍 Sprachen / Idiomas / Langues

- [English](../README.md)
- [Español](README.es.md)
- [Português](README.pt.md)
- [Français](README.fr.md)
- [Italiano](README.it.md)
- [Deutsch](README.de.md) (diese Datei)
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
- [Afrikaans](README.af.md)
- [العربية](README.ar.md)

## 📦 Downloads

Holen Sie sich die neueste Version für Ihre Plattform von der [Releases-Seite](https://github.com/lle0x/blockout2025/releases):

- **Windows**: `blockout-windows-*.zip` - Extrahieren und `Blockout.exe` ausführen
- **Linux (Generisch)**: `blockout-linux-x64-*.tar.gz` - Extrahieren und `./blockout/blockout` ausführen
- **macOS**: `blockout-macos-*.tar.gz` - Extrahieren und die Binärdatei ausführen
- **Ubuntu/Debian**: `blockout_*.deb` - Installieren mit `sudo dpkg -i blockout_*.deb`
- **Fedora/RHEL**: `blockout-*.rpm` - Installieren mit `sudo dnf install blockout-*.rpm`
- **Arch Linux**: `blockout-*.pkg.tar.zst` - Installieren mit `sudo pacman -U blockout-*.pkg.tar.zst`

## 🎮 Systemanforderungen

### Windows
- OpenGL-Unterstützung

### Linux
**Laufzeit:**
- `libgl1-mesa`
- `libglu1-mesa`
- `libxext6`
- `libsdl1.2`
- `libsdl-mixer1.2`

**Build-Abhängigkeiten:**
- `build-essential`
- `libgl1-mesa-dev`
- `libglu1-mesa-dev`
- `libxext-dev`
- `libsdl1.2-dev`
- `libsdl-mixer1.2-dev`
- `libasound2-dev`

### macOS
- SDL 1.2 (über sdl12-compat)
- SDL_mixer 1.2
- OpenGL

## 📝 Versionsgeschichte

### 2.5
- 64-Bit-Unterstützung
- OpenGL wird jetzt sowohl unter Linux als auch unter Windows verwendet
- Kleine grafische Verbesserungen
- Verbesserungen im Übungsmodus
- Verbesserter Demo-Modus (Bot-Spieler spielt besser)
- Lokales Datenverzeichnis vom Installationsverzeichnis in das "AppData"-Verzeichnis verschoben

### 2.4
- Frame-Limiter hinzugefügt
- Demo-Modus hinzugefügt
- Übungsmodus hinzugefügt
- Replay-Fehler behoben
- Zufallsgenerator behoben (FLAT-Blocksatz)
- Vollbildfehler behoben (Linux)

### 2.3
- Spieler-/Rangname beim Wiederholen hinzugefügt
- Neue Satzzeichen hinzugefügt
- Kleiner Effekt, wenn die Drehung blockiert ist
- "Kann blX.bl2replay nicht zum Schreiben öffnen" behoben
- Neuer Stil (Marmor/Arcade)
- Absturz beim Drücken von [Esc] behoben
- Grubenanimation, wenn das Spiel vorbei ist
- Springe zur Seite mit den Punktedetails nach Spielende
- DOS-Blockout-Sound-Preset hinzugefügt
- Neuer Randomizer

### 2.2
- NUMPAD-Tastensteuerung hinzugefügt
- Blocktransparenz mit Schieberegler konfigurierbar
- Menü-Startdemo mit [Esc] abbrechen
- Leere Grube (Flush) in den Punktedetails hinzugefügt
- Online-Punktedatenbank
- Replay
- Credits-Seite hinzugefügt
- Andere kleinere Updates

### 2.1
- Blockabstiegsalgorithmus behoben
- Fallzeit ein wenig erhöht
- Verbesserte Abstimmung der Bewegungsgeschwindigkeit

### 2.0
- Erstveröffentlichung

## 🔧 Kompilieren aus dem Quellcode

### Ubuntu/Debian

**Automatisiert:**
```bash
sudo ./install-ubuntu-deps.sh
./build-and-run.sh
```

**Manuell:**
```bash
# Abhängigkeiten installieren
sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev \
  libxext-dev libsdl1.2-dev libsdl-mixer1.2-dev libasound2-dev

# ImageLib bauen
make -C ImageLib/src

# BlockOut bauen
make -C BlockOut _linux64=1 _release=1

# Ausführen
cd BlockOut
./blockout
```

### Windows

1. Installieren Sie Microsoft Visual Studio 2022 (oder 2019/2017)
2. Installieren Sie SDL 1.2.15 Entwicklungsbibliotheken von [libsdl.org](http://www.libsdl.org)
3. Installieren Sie SDL_mixer 1.2.12 Entwicklungsbibliotheken von [libsdl.org](http://www.libsdl.org/projects/SDL_mixer/release-1.2.html)
4. Legen Sie die entsprechenden Include- und Lib-Pfade in den Projekteigenschaften fest
5. Erstellen Sie die Lösung

### macOS

```bash
# Abhängigkeiten über Homebrew installieren
brew install sdl12-compat pkg-config

# SDL_mixer 1.2 aus dem Quellcode bauen (siehe .github/workflows/build-macos-brew.yml)

# ImageLib bauen
make -C ImageLib/src

# BlockOut bauen
make -C BlockOut _macos=1

# Ausführen
cd BlockOut
./blockout
```

## 🤖 GitHub Actions CI/CD

Dieses Repository verwendet GitHub Actions für das automatisierte Erstellen und Veröffentlichen auf allen Plattformen.

### Verfügbare Workflows

#### Build-Workflows (Automatisiert)

- **`build-windows.yml`** - Erstellt Windows x64-Binärdateien
- **`build-macos-brew.yml`** - Erstellt macOS-Binärdateien
- **`build-fedora-rpm.yml`** - Erstellt RPM-Pakete
- **`build-arch-pkg.yml`** - Erstellt Arch Linux-Pakete
- **`package-deb.yml`** - Erstellt Debian-Pakete

#### Release-Workflow (Manuell)

- **`create-release.yml`** - Erstellt ein neues Release

### Release-Prozess

1. Stellen Sie sicher, dass alle Änderungen in `development` zusammengeführt und getestet sind
2. Gehen Sie zu GitHub Actions → "Create Release" Workflow
3. Klicken Sie auf "Run workflow"
4. Geben Sie die Versionsnummer ein (z. B. `v2.5.0`)
5. Der Workflow wird zusammenführen, taggen, bauen und veröffentlichen

## 🎯 Spiel-Features

### Replay-System
Für jeden Highscore, den Sie erzielen, wird eine `.bl2replay`-Datei im Replay-Verzeichnis erstellt.

### Punkte-Upload
Laden Sie Ihre Highscores von der Seite mit den Punktedetails in die Online-Datenbank hoch.

### Randomizer
BlockOut II verwendet einen Beutel-Randomizer, der eine Folge aller möglichen Teile zufällig permutiert generiert.

### Frame-Limiter
Um Animationen mit der vertikalen Austastung Ihres Monitors zu synchronisieren, wählen Sie VSync in den Frame-Limiter-Einstellungen.

## 📜 Lizenz

Dieses Programm ist freie Software; Sie können es unter den Bedingungen der GNU General Public License weitergeben und/oder ändern.

## 👤 Autor

Jean-Luc PONS (jlp_38@yahoo.com)

## 🔗 Links

- [Offizielle Website](http://www.blockout.net/blockout2)
- [GitHub Repository](https://github.com/lle0x/blockout2025)
- [Kadon Enterprises](http://www.gamepuzzles.com)
