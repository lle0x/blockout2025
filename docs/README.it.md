# BlockOut II v2.5

![BlockOut II Gameplay](../gameplay-screenshot.png)

**Un gioco di puzzle in stile Tetris 3D**

BlockOut II è un adattamento OpenGL del gioco originale BlockOut per DOS pubblicato da California Dreams nel 1989. BlockOut II ha le stesse caratteristiche del gioco originale con alcuni miglioramenti grafici. Anche il calcolo del punteggio è quasi simile al gioco originale. BlockOut II è stato progettato da un giocatore dipendente per giocatori dipendenti.

Buon divertimento con BlockOut II...

---

*Blockout® è un marchio registrato di Kadon Enterprises, Inc., utilizzato su autorizzazione. Questa azienda statunitense produce set pratici di policubi dal 1980. [www.gamepuzzles.com](http://www.gamepuzzles.com)*

---

## 🌐 Home Page Ufficiale

**http://www.blockout.net/blockout2**

## 🌍 Lingue / Idiomas / Langues

- [English](../README.md)
- [Español](README.es.md)
- [Português](README.pt.md)
- [Français](README.fr.md)
- [Italiano](README.it.md) (questo file)
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
- [Afrikaans](README.af.md)
- [العربية](README.ar.md)

## 📦 Download

Ottieni l'ultima versione per la tua piattaforma dalla [pagina delle Release](https://github.com/lle0x/blockout2025/releases):

- **Windows**: `blockout-windows-*.zip` - Estrai ed esegui `Blockout.exe`
- **Linux (Generico)**: `blockout-linux-x64-*.tar.gz` - Estrai ed esegui `./blockout/blockout`
- **macOS**: `blockout-macos-*.tar.gz` - Estrai ed esegui il binario
- **Ubuntu/Debian**: `blockout_*.deb` - Installa con `sudo dpkg -i blockout_*.deb`
- **Fedora/RHEL**: `blockout-*.rpm` - Installa con `sudo dnf install blockout-*.rpm`
- **Arch Linux**: `blockout-*.pkg.tar.zst` - Installa con `sudo pacman -U blockout-*.pkg.tar.zst`

## 🎮 Requisiti di Sistema

### Windows
- Supporto OpenGL

### Linux
**Runtime:**
- `libgl1-mesa`
- `libglu1-mesa`
- `libxext6`
- `libsdl1.2`
- `libsdl-mixer1.2`

**Dipendenze di Compilazione:**
- `build-essential`
- `libgl1-mesa-dev`
- `libglu1-mesa-dev`
- `libxext-dev`
- `libsdl1.2-dev`
- `libsdl-mixer1.2-dev`
- `libasound2-dev`

### macOS
- SDL 1.2 (tramite sdl12-compat)
- SDL_mixer 1.2
- OpenGL

## 📝 Cronologia Versioni

### 2.5
- Supporto a 64 bit
- OpenGL è ora utilizzato sia su Linux che su Windows
- Piccoli miglioramenti grafici
- Miglioramenti alla modalità pratica
- Migliorata la modalità demo (il giocatore Bot gioca meglio)
- Directory dei dati locali spostata dalla directory di installazione alla directory "AppData"

### 2.4
- Aggiunto limitatore di frame
- Aggiunta modalità demo
- Aggiunta modalità pratica
- Risolto bug replay
- Risolto generatore casuale (set di blocchi FLAT)
- Risolto bug a schermo intero (Linux)

### 2.3
- Aggiunto nome giocatore/rango durante il replay
- Aggiunti nuovi caratteri di punteggiatura
- Piccolo effetto quando la rotazione è bloccata
- Risolto "Impossibile aprire blX.bl2replay per la scrittura"
- Nuovo stile (Marmo/Arcade)
- Risolto crash premendo [Esc]
- Animazione del pozzo quando il gioco è finito
- Salta alla pagina Dettagli Punteggio dopo la fine del gioco
- Aggiunto preset audio DOS blockout
- Nuovo randomizzatore

### 2.2
- Aggiunto controllo tasti tastierino numerico
- Trasparenza dei blocchi configurabile con cursore
- Interrompi demo avvio menu con [Esc]
- Aggiunto pozzo vuoto (Flush) nei dettagli del punteggio
- Database punteggi on-line
- Replay
- Aggiunta pagina crediti
- Altri aggiornamenti minori

### 2.1
- Risolto algoritmo discesa blocchi
- Aumentato leggermente il tempo di caduta
- Migliorata la regolazione della velocità di movimento

### 2.0
- Rilascio iniziale

## 🔧 Compilazione dal Codice Sorgente

### Ubuntu/Debian

**Automatizzato:**
```bash
sudo ./install-ubuntu-deps.sh
./build-and-run.sh
```

**Manuale:**
```bash
# Installa dipendenze
sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev \
  libxext-dev libsdl1.2-dev libsdl-mixer1.2-dev libasound2-dev

# Compila ImageLib
make -C ImageLib/src

# Compila BlockOut
make -C BlockOut _linux64=1 _release=1

# Esegui
cd BlockOut
./blockout
```

### Windows

1. Installa Microsoft Visual Studio 2022 (o 2019/2017)
2. Installa le librerie di sviluppo SDL 1.2.15 da [libsdl.org](http://www.libsdl.org)
3. Installa le librerie di sviluppo SDL_mixer 1.2.12 da [libsdl.org](http://www.libsdl.org/projects/SDL_mixer/release-1.2.html)
4. Imposta i percorsi include e lib appropriati nelle proprietà del progetto
5. Compila la soluzione

### macOS

```bash
# Installa dipendenze tramite Homebrew
brew install sdl12-compat pkg-config

# Compila SDL_mixer 1.2 dal sorgente (vedi .github/workflows/build-macos-brew.yml)

# Compila ImageLib
make -C ImageLib/src

# Compila BlockOut
make -C BlockOut _macos=1

# Esegui
cd BlockOut
./blockout
```

## 🤖 GitHub Actions CI/CD

Questo repository utilizza GitHub Actions per la compilazione e il rilascio automatizzati su tutte le piattaforme. I flussi di lavoro vengono attivati sui push ai branch `main` e `development`.

### Flussi di Lavoro Disponibili

#### Flussi di Lavoro di Compilazione (Automatizzati)

- **`build-windows.yml`** - Compila binari Windows x64 e crea un pacchetto zip
- **`build-macos-brew.yml`** - Compila binari macOS utilizzando le dipendenze Homebrew
- **`build-fedora-rpm.yml`** - Compila pacchetti RPM per Fedora/RHEL
- **`build-arch-pkg.yml`** - Compila pacchetti Arch Linux
- **`package-deb.yml`** - Compila pacchetti Debian per più versioni di Ubuntu

#### Flusso di Lavoro di Rilascio (Manuale)

- **`create-release.yml`** - Crea una nuova release (solo attivazione manuale)

### Processo di Rilascio

1. Assicurati che tutte le modifiche siano unite a `development` e testate
2. Vai a GitHub Actions → Flusso di lavoro "Create Release"
3. Clicca "Run workflow"
4. Inserisci il numero di versione (es. `v2.5.0`)
5. Il flusso di lavoro unirà, taggherà, compilerà e rilascerà

## 🎯 Caratteristiche del Gioco

### Sistema di Replay
Per ogni punteggio alto che fai, viene creato un file `.bl2replay` nella directory replay. Questi file contengono i dati di replay necessari per caricare i punteggi nel database online.

### Caricamento Punteggi
Carica i tuoi punteggi alti nel database online dalla pagina Dettagli Punteggio.

### Randomizzatore
BlockOut II utilizza un randomizzatore a sacchetto che genera una sequenza di tutti i pezzi possibili permutati casualmente.

### Limitatore di Frame
Per sincronizzare le animazioni con l'oscuramento verticale del monitor, seleziona VSync nelle impostazioni del limitatore di frame.

## 📜 Licenza

Questo programma è software libero; puoi ridistribuirlo e/o modificarlo secondo i termini della GNU General Public License.

## 👤 Autore

Jean-Luc PONS (jlp_38@yahoo.com)

## 🔗 Link

- [Sito Ufficiale](http://www.blockout.net/blockout2)
- [Repository GitHub](https://github.com/lle0x/blockout2025)
- [Kadon Enterprises](http://www.gamepuzzles.com)
