# BlockOut II v2.5

![BlockOut II Gameplay](../gameplay-screenshot.png)

**3D Tetris tarzı bir bulmaca oyunu**

BlockOut II, 1989 yılında California Dreams tarafından yayınlanan orijinal BlockOut DOS oyununun OpenGL uyarlamasıdır. BlockOut II, birkaç grafik iyileştirmesiyle orijinal oyunla aynı özelliklere sahiptir. Puan hesaplama da orijinal oyuna neredeyse benzerdir. BlockOut II, bağımlı bir oyuncu tarafından bağımlı oyuncular için tasarlanmıştır.

BlockOut II ile eğlenin...

---

*Blockout®, Kadon Enterprises, Inc.'in izniyle kullanılan tescilli ticari markasıdır. Bu ABD şirketi 1980'den beri pratik poliküp setleri üretmektedir. [www.gamepuzzles.com](http://www.gamepuzzles.com)*

---

## 🌐 Resmi Ana Sayfa

**http://www.blockout.net/blockout2**

## 🌍 Diller / Idiomas / Langues

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
- [Türkçe](README.tr.md) (bu dosya)
- [Afrikaans](README.af.md)
- [العربية](README.ar.md)

## 📦 İndirmeler

Platformunuz için en son sürümü [Sürümler sayfasından](https://github.com/lle0x/blockout2025/releases) edinin:

- **Windows**: `blockout-windows-*.zip` - Çıkartın ve `Blockout.exe` dosyasını çalıştırın
- **Linux (Genel)**: `blockout-linux-x64-*.tar.gz` - Çıkartın ve `./blockout/blockout` dosyasını çalıştırın
- **macOS**: `blockout-macos-*.tar.gz` - Çıkartın ve ikili dosyayı çalıştırın
- **Ubuntu/Debian**: `blockout_*.deb` - `sudo dpkg -i blockout_*.deb` ile kurun
- **Fedora/RHEL**: `blockout-*.rpm` - `sudo dnf install blockout-*.rpm` ile kurun
- **Arch Linux**: `blockout-*.pkg.tar.zst` - `sudo pacman -U blockout-*.pkg.tar.zst` ile kurun

## 🎮 Sistem Gereksinimleri

### Windows
- OpenGL desteği

### Linux
**Çalışma zamanı:**
- `libgl1-mesa`
- `libglu1-mesa`
- `libxext6`
- `libsdl1.2`
- `libsdl-mixer1.2`

**Derleme Bağımlılıkları:**
- `build-essential`
- `libgl1-mesa-dev`
- `libglu1-mesa-dev`
- `libxext-dev`
- `libsdl1.2-dev`
- `libsdl-mixer1.2-dev`
- `libasound2-dev`

### macOS
- SDL 1.2 (sdl12-compat üzerinden)
- SDL_mixer 1.2
- OpenGL

## 📝 Sürüm Geçmişi

### 2.5
- 64-bit desteği
- OpenGL artık hem Linux hem de Windows'ta kullanılıyor
- Küçük grafik iyileştirmeleri
- Pratik modu iyileştirmeleri
- Geliştirilmiş demo modu (Bot oyuncu daha iyi oynuyor)
- Yerel veri dizini kurulum dizininden "AppData" dizinine taşındı

### 2.4
- Kare sınırlayıcı eklendi
- Demo modu eklendi
- Pratik modu eklendi
- Tekrar oynatma hatası düzeltildi
- Rastgele oluşturucu düzeltildi (FLAT blok seti)
- Tam ekran hatası düzeltildi (Linux)

### 2.3
- Tekrar oynatmada oyuncu/sıralama adı eklendi
- Yeni noktalama işaretleri eklendi
- Döndürme engellendiğinde küçük efekt
- "blX.bl2replay yazma için açılamıyor" düzeltildi
- Yeni stil (Mermer/Arcade)
- [Esc] tuşuna basıldığında çökme düzeltildi
- Oyun bittiğinde çukur animasyonu
- Oyun bitiminden sonra Puan Detayları sayfasına atla
- DOS blockout ses ön ayarı eklendi
- Yeni rastgele oluşturucu

### 2.2
- NUMPAD tuş kontrolü eklendi
- Blok şeffaflığı kaydırıcı ile yapılandırılabilir
- Menü başlangıç demosunu [Esc] ile iptal et
- Puan detaylarına boş çukur (Flush) eklendi
- Çevrimiçi puan veritabanı
- Tekrar oynatma
- Jenerik sayfası eklendi
- Diğer küçük güncellemeler

### 2.1
- Blok iniş algoritması düzeltildi
- Düşme süresi biraz artırıldı
- Hareket hızı ayarı iyileştirildi

### 2.0
- İlk sürüm

## 🔧 Kaynak Koddan Derleme

### Ubuntu/Debian

**Otomatik:**
```bash
sudo ./install-ubuntu-deps.sh
./build-and-run.sh
```

**Manuel:**
```bash
# Bağımlılıkları yükle
sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev \
  libxext-dev libsdl1.2-dev libsdl-mixer1.2-dev libasound2-dev

# ImageLib'i derle
make -C ImageLib/src

# BlockOut'u derle
make -C BlockOut _linux64=1 _release=1

# Çalıştır
cd BlockOut
./blockout
```

### Windows

1. Microsoft Visual Studio 2022'yi (veya 2019/2017) yükleyin
2. [libsdl.org](http://www.libsdl.org)'dan SDL 1.2.15 geliştirme kütüphanelerini yükleyin
3. [libsdl.org](http://www.libsdl.org/projects/SDL_mixer/release-1.2.html)'dan SDL_mixer 1.2.12 geliştirme kütüphanelerini yükleyin
4. Proje özelliklerinde uygun include ve lib yollarını ayarlayın
5. Çözümü derleyin

### macOS

```bash
# Homebrew üzerinden bağımlılıkları yükle
brew install sdl12-compat pkg-config

# SDL_mixer 1.2'yi kaynaktan derle (bkz. .github/workflows/build-macos-brew.yml)

# ImageLib'i derle
make -C ImageLib/src

# BlockOut'u derle
make -C BlockOut _macos=1

# Çalıştır
cd BlockOut
./blockout
```

## 🤖 GitHub Actions CI/CD

Bu depo, tüm platformlarda otomatik derleme ve yayınlama için GitHub Actions kullanır.

### Mevcut İş Akışları

#### Derleme İş Akışları (Otomatik)

- **`build-windows.yml`** - Windows x64 ikili dosyalarını derler
- **`build-macos-brew.yml`** - macOS ikili dosyalarını derler
- **`build-fedora-rpm.yml`** - RPM paketlerini derler
- **`build-arch-pkg.yml`** - Arch Linux paketlerini derler
- **`package-deb.yml`** - Debian paketlerini derler

#### Yayın İş Akışı (Manuel)

- **`create-release.yml`** - Yeni bir sürüm oluşturur

### Yayın Süreci

1. Tüm değişikliklerin `development`'a birleştirildiğinden ve test edildiğinden emin olun
2. GitHub Actions → "Create Release" iş akışına gidin
3. "Run workflow"'a tıklayın
4. Sürüm numarasını girin (ör. `v2.5.0`)
5. İş akışı birleştirecek, etiketleyecek, derleyecek ve yayınlayacak

## 🎯 Oyun Özellikleri

### Tekrar Oynatma Sistemi
Yaptığınız her yüksek puan için tekrar oynatma dizininde bir `.bl2replay` dosyası oluşturulur.

### Puan Yükleme
Yüksek puanlarınızı Puan Detayları sayfasından çevrimiçi veritabanına yükleyin.

### Rastgele Oluşturucu
BlockOut II, tüm olası parçaların rastgele permütasyonlu bir dizisini üreten bir torba rastgele oluşturucu kullanır.

### Kare Sınırlayıcı
Animasyonları monitörünüzün dikey boşaltmasıyla senkronize etmek için kare sınırlayıcı ayarlarında VSync'i seçin.

## 📜 Lisans

Bu program özgür yazılımdır; GNU Genel Kamu Lisansı koşulları altında yeniden dağıtabilir ve/veya değiştirebilirsiniz.

## 👤 Yazar

Jean-Luc PONS (jlp_38@yahoo.com)

## 🔗 Bağlantılar

- [Resmi Web Sitesi](http://www.blockout.net/blockout2)
- [GitHub Deposu](https://github.com/lle0x/blockout2025)
- [Kadon Enterprises](http://www.gamepuzzles.com)
