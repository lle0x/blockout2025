# BlockOut II v2.5

![BlockOut II Gameplay](../gameplay-screenshot.png)

**Trójwymiarowa gra logiczna w stylu Tetris**

BlockOut II to adaptacja OpenGL oryginalnej gry BlockOut dla systemu DOS, wydanej przez California Dreams w 1989 roku. BlockOut II posiada te same funkcje co oryginalna gra, z kilkoma ulepszeniami graficznymi. Obliczanie wyniku jest również prawie identyczne jak w oryginalnej grze. BlockOut II został zaprojektowany przez uzależnionego gracza dla uzależnionych graczy.

Baw się dobrze z BlockOut II...

---

*Blockout® jest zarejestrowanym znakiem towarowym Kadon Enterprises, Inc., używanym za zgodą. Ta amerykańska firma produkuje zestawy polikubów od 1980 roku. [www.gamepuzzles.com](http://www.gamepuzzles.com)*

---

## 🌐 Oficjalna Strona Główna

**http://www.blockout.net/blockout2**

## 🌍 Języki / Idiomas / Langues

- [English](../README.md)
- [Español](README.es.md)
- [Português](README.pt.md)
- [Français](README.fr.md)
- [Italiano](README.it.md)
- [Deutsch](README.de.md)
- [Polski](README.pl.md) (ten plik)
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

## 📦 Pobieranie

Pobierz najnowszą wersję dla swojej platformy ze [strony wydań](https://github.com/lle0x/blockout2025/releases):

- **Windows**: `blockout-windows-*.zip` - Rozpakuj i uruchom `Blockout.exe`
- **Linux (Ogólny)**: `blockout-linux-x64-*.tar.gz` - Rozpakuj i uruchom `./blockout/blockout`
- **macOS**: `blockout-macos-*.tar.gz` - Rozpakuj i uruchom plik binarny
- **Ubuntu/Debian**: `blockout_*.deb` - Zainstaluj za pomocą `sudo dpkg -i blockout_*.deb`
- **Fedora/RHEL**: `blockout-*.rpm` - Zainstaluj za pomocą `sudo dnf install blockout-*.rpm`
- **Arch Linux**: `blockout-*.pkg.tar.zst` - Zainstaluj za pomocą `sudo pacman -U blockout-*.pkg.tar.zst`

## 🎮 Wymagania Systemowe

### Windows
- Obsługa OpenGL

### Linux
**Uruchomienie:**
- `libgl1-mesa`
- `libglu1-mesa`
- `libxext6`
- `libsdl1.2`
- `libsdl-mixer1.2`

**Zależności Kompilacji:**
- `build-essential`
- `libgl1-mesa-dev`
- `libglu1-mesa-dev`
- `libxext-dev`
- `libsdl1.2-dev`
- `libsdl-mixer1.2-dev`
- `libasound2-dev`

### macOS
- SDL 1.2 (przez sdl12-compat)
- SDL_mixer 1.2
- OpenGL

## 📝 Historia Wersji

### 2.5
- Obsługa 64-bitowa
- OpenGL jest teraz używany zarówno w systemie Linux, jak i Windows
- Drobne ulepszenia graficzne
- Ulepszenia trybu treningowego
- Ulepszony tryb demo (gracz Bot gra lepiej)
- Lokalny katalog danych przeniesiony z katalogu instalacyjnego do katalogu "AppData"

### 2.4
- Dodano ogranicznik klatek
- Dodano tryb demo
- Dodano tryb treningowy
- Naprawiono błąd powtórki
- Naprawiono generator losowy (zestaw klocków FLAT)
- Naprawiono błąd pełnego ekranu (Linux)

### 2.3
- Dodano nazwę gracza/rangę podczas powtórki
- Dodano nowe znaki interpunkcyjne
- Mały efekt, gdy obrót jest zablokowany
- Naprawiono "Nie można otworzyć blX.bl2replay do zapisu"
- Nowy styl (Marmur/Arcade)
- Naprawiono awarię po naciśnięciu [Esc]
- Animacja studni po zakończeniu gry
- Przejdź do strony Szczegóły Wyniku po zakończeniu gry
- Dodano preset dźwiękowy DOS blockout
- Nowy randomizer

### 2.2
- Dodano sterowanie klawiaturą numeryczną
- Przezroczystość klocków konfigurowalna suwakiem
- Przerwij demo startowe menu za pomocą [Esc]
- Dodano pustą studnię (Flush) w szczegółach wyniku
- Baza wyników on-line
- Powtórka
- Dodano stronę z podziękowaniami
- Inne drobne aktualizacje

### 2.1
- Naprawiono algorytm opadania klocków
- Nieznacznie zwiększono czas opadania
- Ulepszono dostrajanie prędkości ruchu

### 2.0
- Pierwsze wydanie

## 🔧 Kompilacja ze Źródła

### Ubuntu/Debian

**Automatycznie:**
```bash
sudo ./install-ubuntu-deps.sh
./build-and-run.sh
```

**Ręcznie:**
```bash
# Zainstaluj zależności
sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev \
  libxext-dev libsdl1.2-dev libsdl-mixer1.2-dev libasound2-dev

# Zbuduj ImageLib
make -C ImageLib/src

# Zbuduj BlockOut
make -C BlockOut _linux64=1 _release=1

# Uruchom
cd BlockOut
./blockout
```

### Windows

1. Zainstaluj Microsoft Visual Studio 2022 (lub 2019/2017)
2. Zainstaluj biblioteki programistyczne SDL 1.2.15 z [libsdl.org](http://www.libsdl.org)
3. Zainstaluj biblioteki programistyczne SDL_mixer 1.2.12 z [libsdl.org](http://www.libsdl.org/projects/SDL_mixer/release-1.2.html)
4. Ustaw odpowiednie ścieżki include i lib we właściwościach projektu
5. Zbuduj rozwiązanie

### macOS

```bash
# Zainstaluj zależności przez Homebrew
brew install sdl12-compat pkg-config

# Zbuduj SDL_mixer 1.2 ze źródła (zobacz .github/workflows/build-macos-brew.yml)

# Zbuduj ImageLib
make -C ImageLib/src

# Zbuduj BlockOut
make -C BlockOut _macos=1

# Uruchom
cd BlockOut
./blockout
```

## 🤖 GitHub Actions CI/CD

To repozytorium wykorzystuje GitHub Actions do automatycznego budowania i wydawania na wszystkich platformach.

### Dostępne Przepływy Pracy

#### Przepływy Budowania (Automatyczne)

- **`build-windows.yml`** - Buduje pliki binarne Windows x64
- **`build-macos-brew.yml`** - Buduje pliki binarne macOS
- **`build-fedora-rpm.yml`** - Buduje pakiety RPM
- **`build-arch-pkg.yml`** - Buduje pakiety Arch Linux
- **`package-deb.yml`** - Buduje pakiety Debian

#### Przepływ Wydania (Ręczny)

- **`create-release.yml`** - Tworzy nowe wydanie

### Proces Wydania

1. Upewnij się, że wszystkie zmiany są scalone z `development` i przetestowane
2. Przejdź do GitHub Actions → Przepływ pracy "Create Release"
3. Kliknij "Run workflow"
4. Wprowadź numer wersji (np. `v2.5.0`)
5. Przepływ pracy scali, otaguje, zbuduje i wyda

## 🎯 Cechy Gry

### System Powtórek
Dla każdego wysokiego wyniku tworzony jest plik `.bl2replay` w katalogu powtórek.

### Przesyłanie Wyników
Prześlij swoje wysokie wyniki do bazy danych online ze strony Szczegóły Wyniku.

### Randomizer
BlockOut II używa randomizera workowego, który generuje sekwencję wszystkich możliwych elementów losowo permutowanych.

### Ogranicznik Klatek
Aby zsynchronizować animacje z wygaszaniem pionowym monitora, wybierz VSync w ustawieniach ogranicznika klatek.

## 📜 Licencja

Ten program jest wolnym oprogramowaniem; możesz go rozpowszechniać i/lub modyfikować zgodnie z warunkami Powszechnej Licencji Publicznej GNU.

## 👤 Autor

Jean-Luc PONS (jlp_38@yahoo.com)

## 🔗 Linki

- [Oficjalna Strona](http://www.blockout.net/blockout2)
- [Repozytorium GitHub](https://github.com/lle0x/blockout2025)
- [Kadon Enterprises](http://www.gamepuzzles.com)
