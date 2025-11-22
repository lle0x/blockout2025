# BlockOut II v2.5

![BlockOut II Gameplay](../gameplay-screenshot.png)

**Ένα παιχνίδι παζλ τύπου Tetris 3D**

Το BlockOut II είναι μια προσαρμογή OpenGL του αρχικού παιχνιδιού BlockOut για DOS που εκδόθηκε από την California Dreams το 1989. Το BlockOut II έχει τα ίδια χαρακτηριστικά με το αρχικό παιχνίδι με μερικές γραφικές βελτιώσεις. Ο υπολογισμός της βαθμολογίας είναι επίσης σχεδόν παρόμοιος με το αρχικό παιχνίδι. Το BlockOut II σχεδιάστηκε από έναν εθισμένο παίκτη για εθισμένους παίκτες.

Διασκεδάστε με το BlockOut II...

---

*Το Blockout® είναι καταχωρημένο εμπορικό σήμα της Kadon Enterprises, Inc., που χρησιμοποιείται με άδεια. Αυτή η αμερικανική εταιρεία παράγει πρακτικά σετ πολυκύβων από το 1980. [www.gamepuzzles.com](http://www.gamepuzzles.com)*

---

## 🌐 Επίσημη Αρχική Σελίδα

**http://www.blockout.net/blockout2**

## 🌍 Γλώσσες / Idiomas / Langues

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
- [Ελληνικά](README.el.md) (αυτό το αρχείο)
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

## 📦 Λήψεις

Αποκτήστε την τελευταία έκδοση για την πλατφόρμα σας από τη [σελίδα Εκδόσεων](https://github.com/lle0x/blockout2025/releases):

- **Windows**: `blockout-windows-*.zip` - Εξαγωγή και εκτέλεση `Blockout.exe`
- **Linux (Γενικό)**: `blockout-linux-x64-*.tar.gz` - Εξαγωγή και εκτέλεση `./blockout/blockout`
- **macOS**: `blockout-macos-*.tar.gz` - Εξαγωγή και εκτέλεση του δυαδικού
- **Ubuntu/Debian**: `blockout_*.deb` - Εγκατάσταση με `sudo dpkg -i blockout_*.deb`
- **Fedora/RHEL**: `blockout-*.rpm` - Εγκατάσταση με `sudo dnf install blockout-*.rpm`
- **Arch Linux**: `blockout-*.pkg.tar.zst` - Εγκατάσταση με `sudo pacman -U blockout-*.pkg.tar.zst`

## 🎮 Απαιτήσεις Συστήματος

### Windows
- Υποστήριξη OpenGL

### Linux
**Χρόνος εκτέλεσης:**
- `libgl1-mesa`
- `libglu1-mesa`
- `libxext6`
- `libsdl1.2`
- `libsdl-mixer1.2`

**Εξαρτήσεις Κατασκευής:**
- `build-essential`
- `libgl1-mesa-dev`
- `libglu1-mesa-dev`
- `libxext-dev`
- `libsdl1.2-dev`
- `libsdl-mixer1.2-dev`
- `libasound2-dev`

### macOS
- SDL 1.2 (μέσω sdl12-compat)
- SDL_mixer 1.2
- OpenGL

## 📝 Ιστορικό Εκδόσεων

### 2.5
- Υποστήριξη 64-bit
- Το OpenGL χρησιμοποιείται τώρα τόσο σε Linux όσο και σε Windows
- Μικρές γραφικές βελτιώσεις
- Βελτιώσεις λειτουργίας εξάσκησης
- Βελτιωμένη λειτουργία επίδειξης (ο παίκτης Bot παίζει καλύτερα)
- Ο τοπικός κατάλογος δεδομένων μετακινήθηκε από τον κατάλογο εγκατάστασης στον κατάλογο "AppData"

### 2.4
- Προστέθηκε περιοριστής καρέ
- Προστέθηκε λειτουργία επίδειξης
- Προστέθηκε λειτουργία εξάσκησης
- Διορθώθηκε σφάλμα επανάληψης
- Διορθώθηκε γεννήτρια τυχαίων (σετ μπλοκ FLAT)
- Διορθώθηκε σφάλμα πλήρους οθόνης (Linux)

### 2.3
- Προστέθηκε όνομα παίκτη/κατάταξης κατά την επανάληψη
- Προστέθηκαν νέοι χαρακτήρες στίξης
- Μικρό εφέ όταν η περιστροφή είναι αποκλεισμένη
- Διορθώθηκε "Δεν είναι δυνατό το άνοιγμα του blX.bl2replay για εγγραφή"
- Νέο στυλ (Μάρμαρο/Arcade)
- Διορθώθηκε κατάρρευση κατά το πάτημα [Esc]
- Κινούμενα σχέδια λάκκου όταν το παιχνίδι τελειώνει
- Μετάβαση στη σελίδα Λεπτομέρειες Βαθμολογίας μετά το τέλος του παιχνιδιού
- Προστέθηκε προεπιλογή ήχου DOS blockout
- Νέα γεννήτρια τυχαίων

### 2.2
- Προστέθηκε έλεγχος πλήκτρων NUMPAD
- Διαφάνεια μπλοκ ρυθμιζόμενη με ρυθμιστικό
- Ακύρωση επίδειξης εκκίνησης μενού με [Esc]
- Προστέθηκε κενός λάκκος (Flush) στις λεπτομέρειες βαθμολογίας
- Βάση δεδομένων βαθμολογίας σε σύνδεση
- Επανάληψη
- Προστέθηκε σελίδα πιστώσεων
- Άλλες μικρές ενημερώσεις

### 2.1
- Διορθώθηκε αλγόριθμος κάθοδου μπλοκ
- Αυξήθηκε ελαφρώς ο χρόνος πτώσης
- Βελτιωμένη ρύθμιση ταχύτητας κίνησης

### 2.0
- Αρχική έκδοση

## 🔧 Κατασκευή από Πηγή

### Ubuntu/Debian

**Αυτοματοποιημένο:**
```bash
sudo ./install-ubuntu-deps.sh
./build-and-run.sh
```

**Χειροκίνητο:**
```bash
# Εγκατάσταση εξαρτήσεων
sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev \
  libxext-dev libsdl1.2-dev libsdl-mixer1.2-dev libasound2-dev

# Κατασκευή ImageLib
make -C ImageLib/src

# Κατασκευή BlockOut
make -C BlockOut _linux64=1 _release=1

# Εκτέλεση
cd BlockOut
./blockout
```

### Windows

1. Εγκαταστήστε το Microsoft Visual Studio 2022 (ή 2019/2017)
2. Εγκαταστήστε βιβλιοθήκες ανάπτυξης SDL 1.2.15 από το [libsdl.org](http://www.libsdl.org)
3. Εγκαταστήστε βιβλιοθήκες ανάπτυξης SDL_mixer 1.2.12 από το [libsdl.org](http://www.libsdl.org/projects/SDL_mixer/release-1.2.html)
4. Ορίστε κατάλληλες διαδρομές include και lib στις ιδιότητες του έργου
5. Κατασκευάστε τη λύση

### macOS

```bash
# Εγκατάσταση εξαρτήσεων μέσω Homebrew
brew install sdl12-compat pkg-config

# Κατασκευή SDL_mixer 1.2 από πηγή (δείτε .github/workflows/build-macos-brew.yml)

# Κατασκευή ImageLib
make -C ImageLib/src

# Κατασκευή BlockOut
make -C BlockOut _macos=1

# Εκτέλεση
cd BlockOut
./blockout
```

## 🤖 GitHub Actions CI/CD

Αυτό το αποθετήριο χρησιμοποιεί GitHub Actions για αυτοματοποιημένη κατασκευή και έκδοση σε όλες τις πλατφόρμες.

### Διαθέσιμες Ροές Εργασίας

#### Ροές Εργασίας Κατασκευής (Αυτοματοποιημένες)

- **`build-windows.yml`** - Κατασκευάζει δυαδικά Windows x64
- **`build-macos-brew.yml`** - Κατασκευάζει δυαδικά macOS
- **`build-fedora-rpm.yml`** - Κατασκευάζει πακέτα RPM
- **`build-arch-pkg.yml`** - Κατασκευάζει πακέτα Arch Linux
- **`package-deb.yml`** - Κατασκευάζει πακέτα Debian

#### Ροή Εργασίας Έκδοσης (Χειροκίνητη)

- **`create-release.yml`** - Δημιουργεί νέα έκδοση

### Διαδικασία Έκδοσης

1. Βεβαιωθείτε ότι όλες οι αλλαγές έχουν συγχωνευθεί στο `development` και δοκιμαστεί
2. Μεταβείτε στο GitHub Actions → Ροή εργασίας "Create Release"
3. Κάντε κλικ στο "Run workflow"
4. Εισαγάγετε τον αριθμό έκδοσης (π.χ. `v2.5.0`)
5. Η ροή εργασίας θα συγχωνεύσει, θα επισημάνει, θα κατασκευάσει και θα εκδώσει

## 🎯 Χαρακτηριστικά Παιχνιδιού

### Σύστημα Επανάληψης
Για κάθε υψηλή βαθμολογία που κάνετε, δημιουργείται ένα αρχείο `.bl2replay` στον κατάλογο επανάληψης.

### Μεταφόρτωση Βαθμολογιών
Μεταφορτώστε τις υψηλές βαθμολογίες σας στη βάση δεδομένων σε σύνδεση από τη σελίδα Λεπτομέρειες Βαθμολογίας.

### Γεννήτρια Τυχαίων
Το BlockOut II χρησιμοποιεί μια γεννήτρια τυχαίων σάκου που δημιουργεί μια ακολουθία όλων των πιθανών κομματιών τυχαία αναδιατεταγμένων.

### Περιοριστής Καρέ
Για να συγχρονίσετε τα κινούμενα σχέδια με την κάθετη απόσβεση της οθόνης σας, επιλέξτε VSync στις ρυθμίσεις περιοριστή καρέ.

## 📜 Άδεια

Αυτό το πρόγραμμα είναι ελεύθερο λογισμικό· μπορείτε να το αναδιανείμετε και/ή να το τροποποιήσετε σύμφωνα με τους όρους της Γενικής Δημόσιας Άδειας GNU.

## 👤 Συγγραφέας

Jean-Luc PONS (jlp_38@yahoo.com)

## 🔗 Σύνδεσμοι

- [Επίσημος Ιστότοπος](http://www.blockout.net/blockout2)
- [Αποθετήριο GitHub](https://github.com/lle0x/blockout2025)
- [Kadon Enterprises](http://www.gamepuzzles.com)
