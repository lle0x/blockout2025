# BlockOut II v2.5

![BlockOut II Gameplay](../gameplay-screenshot.png)

**Un jeu de puzzle de style Tetris 3D**

BlockOut II est une adaptation OpenGL du jeu original BlockOut DOS édité par California Dreams en 1989. BlockOut II possède les mêmes fonctionnalités que le jeu original avec quelques améliorations graphiques. Le calcul des scores est également très similaire au jeu original. BlockOut II a été conçu par un joueur accro pour des joueurs accros.

Amusez-vous bien avec BlockOut II...

---

*Blockout® est une marque déposée de Kadon Enterprises, Inc., utilisée avec permission. Cette société américaine produit des ensembles de polycubes depuis 1980. [www.gamepuzzles.com](http://www.gamepuzzles.com)*

---

## 🌐 Page Officielle

**http://www.blockout.net/blockout2**

## 📦 Téléchargements

Obtenez la dernière version pour votre plateforme depuis la [page des Releases](https://github.com/lle0x/blockout2025/releases):

- **Windows**: `blockout-windows-*.zip` - Extrayez et exécutez `Blockout.exe`
- **Linux (Générique)**: `blockout-linux-x64-*.tar.gz` - Extrayez et exécutez `./blockout/blockout`
- **macOS**: `blockout-macos-*.tar.gz` - Extrayez et exécutez le binaire
- **Ubuntu/Debian**: `blockout_*.deb` - Installez avec `sudo dpkg -i blockout_*.deb`
- **Fedora/RHEL**: `blockout-*.rpm` - Installez avec `sudo dnf install blockout-*.rpm`
- **Arch Linux**: `blockout-*.pkg.tar.zst` - Installez avec `sudo pacman -U blockout-*.pkg.tar.zst`

## 🎮 Configuration Système Requise

### Windows
- Support OpenGL

### Linux
**Exécution:**
- `libgl1-mesa`
- `libglu1-mesa`
- `libxext6`
- `libsdl1.2`
- `libsdl-mixer1.2`

**Dépendances de compilation:**
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

## 📝 Historique des Versions

### 2.5
- Support 64 bits
- OpenGL est maintenant utilisé sur Linux et Windows
- Petites améliorations graphiques
- Améliorations du mode pratique
- Mode démo amélioré (le joueur Bot joue mieux)
- Répertoire de données local déplacé du répertoire d'installation vers le répertoire "AppData"

### 2.4
- Ajout du limiteur de fréquence d'images
- Ajout du mode démo
- Ajout du mode pratique
- Correction du bug de relecture
- Correction du générateur aléatoire (ensemble de blocs FLAT)
- Correction du bug plein écran (Linux)

### 2.3
- Ajout du nom du joueur/rang lors de la relecture
- Nouveaux caractères de ponctuation ajoutés
- Petit effet lorsque la rotation est bloquée
- Correction de "Impossible d'ouvrir blX.bl2replay en écriture"
- Nouveau style (Marbre/Arcade)
- Correction du plantage lors de l'appui sur [Esc]
- Animation du puits lorsque le jeu est terminé
- Passage à la page Détails du Score après la fin du jeu
- Ajout du préréglage sonore DOS blockout
- Nouveau randomiseur

### 2.2
- Ajout du contrôle par touches du pavé numérique
- Transparence des blocs configurable avec curseur
- Annuler la démo de démarrage du menu avec [Esc]
- Puits vide (Flush) ajouté dans les détails du score
- Base de données de scores en ligne
- Relecture
- Page de crédits ajoutée
- Autres mises à jour mineures

### 2.1
- Correction de l'algorithme de descente des blocs
- Augmentation légère du temps de chute
- Amélioration du réglage de la vitesse de mouvement

### 2.0
- Version initiale

## 🔧 Compiler depuis les Sources

### Ubuntu/Debian

**Automatisé:**
```bash
sudo ./install-ubuntu-deps.sh
./build-and-run.sh
```

**Manuel:**
```bash
# Installer les dépendances
sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev \
  libxext-dev libsdl1.2-dev libsdl-mixer1.2-dev libasound2-dev

# Compiler ImageLib
make -C ImageLib/src

# Compiler BlockOut
make -C BlockOut _linux64=1 _release=1

# Exécuter
cd BlockOut
./blockout
```

### Windows

1. Installez Microsoft Visual Studio 2022 (ou 2019/2017)
2. Installez les bibliothèques de développement SDL 1.2.15 depuis [libsdl.org](http://www.libsdl.org)
3. Installez les bibliothèques de développement SDL_mixer 1.2.12 depuis [libsdl.org](http://www.libsdl.org/projects/SDL_mixer/release-1.2.html)
4. Configurez les chemins d'inclusion et de bibliothèques appropriés dans les propriétés du projet
5. Compilez la solution

### macOS

```bash
# Installer les dépendances via Homebrew
brew install sdl12-compat pkg-config

# Compiler SDL_mixer 1.2 depuis les sources (voir .github/workflows/build-macos-brew.yml)

# Compiler ImageLib
make -C ImageLib/src

# Compiler BlockOut
make -C BlockOut _macos=1

# Exécuter
cd BlockOut
./blockout
```

## 🤖 GitHub Actions CI/CD

Ce dépôt utilise GitHub Actions pour la compilation et la publication automatisées sur toutes les plateformes. Les workflows sont déclenchés lors des pushes vers les branches `main` et `development`.

### Workflows Disponibles

#### Workflows de Compilation (Automatisés)

- **`build-windows.yml`** - Compile les binaires Windows x64 et crée un package zip
  - Compile avec Visual Studio 2022 (ensemble d'outils v143)
  - Inclut les DLL d'exécution SDL et les ressources du jeu
  - Sortie: `blockout-windows-*.zip`

- **`build-macos-brew.yml`** - Compile les binaires macOS en utilisant les dépendances Homebrew
  - Utilise `sdl12-compat` pour la compatibilité API SDL 1.2
  - Compile SDL_mixer 1.2 depuis les sources
  - Sortie: `blockout-macos-*.tar.gz`

- **`build-fedora-rpm.yml`** - Compile les packages RPM pour Fedora/RHEL
  - Compile dans un conteneur Fedora
  - Sortie: `blockout-*.rpm`

- **`build-arch-pkg.yml`** - Compile les packages Arch Linux
  - Utilise `makepkg` dans un conteneur Arch
  - Sortie: `blockout-*.pkg.tar.zst`

- **`package-deb.yml`** - Compile les packages Debian pour plusieurs versions d'Ubuntu
  - Compile pour Ubuntu 24.04, 25.04 et 25.10
  - Sortie: `blockout-*-ubuntu*.deb`

#### Workflow de Publication (Manuel)

- **`create-release.yml`** - Crée une nouvelle version (déclenchement manuel uniquement)
  - Fusionne `development` dans `main`
  - Crée un tag de version
  - Compile un tarball générique Linux x64
  - Attend que toutes les compilations de plateforme se terminent
  - Crée une Release GitHub avec tous les packages de plateforme
  - **Utilisation**: Allez dans Actions → "Create Release" → Run workflow → Entrez la version (ex., `v2.5.0`)

### Déclencher les Compilations

Tous les workflows de compilation se déclenchent automatiquement lors de:
- Push vers les branches `main` ou `development`
- Modifications des fichiers sources (`BlockOut/**`, `ImageLib/**`)
- Modifications du fichier de workflow lui-même

Vous pouvez également déclencher manuellement n'importe quel workflow depuis l'onglet GitHub Actions.

### Processus de Publication

1. Assurez-vous que toutes les modifications sont fusionnées dans `development` et testées
2. Allez dans GitHub Actions → workflow "Create Release"
3. Cliquez sur "Run workflow"
4. Entrez le numéro de version (ex., `v2.5.0`)
5. Le workflow va:
   - Fusionner `development` → `main`
   - Créer et pousser le tag de version
   - Compiler tous les packages de plateforme
   - Créer une Release GitHub avec tous les artefacts

## 🎯 Fonctionnalités du Jeu

### Système de Relecture
Pour chaque meilleur score que vous réalisez, un fichier `.bl2replay` est créé dans le répertoire de relecture. Ces fichiers contiennent les données de relecture nécessaires pour télécharger les scores vers la base de données en ligne. Une relecture ne peut être téléchargée qu'une seule fois après un enregistrement réussi.

### Téléchargement des Scores
Téléchargez vos meilleurs scores vers la base de données en ligne depuis la page Détails du Score. Seuls les scores de la version 2.2+ peuvent être téléchargés (fichier de relecture requis).

### Randomiseur
BlockOut II utilise un randomiseur de sac qui génère une séquence de toutes les pièces possibles (selon la dimension du puits et l'ensemble de blocs) permutées aléatoirement. Il distribue toutes les pièces avant de générer un autre sac, empêchant d'obtenir la même pièce 3 fois de suite.

### Limiteur de Fréquence d'Images
Pour synchroniser les animations avec le blanking vertical de votre moniteur, sélectionnez VSync dans les paramètres du limiteur de fréquence d'images, enregistrez et redémarrez l'application.

## 📜 Licence

Ce programme est un logiciel libre; vous pouvez le redistribuer et/ou le modifier selon les termes de la Licence Publique Générale GNU publiée par la Free Software Foundation; soit la version 2 de la Licence, soit (à votre choix) toute version ultérieure.

Ce programme est distribué dans l'espoir qu'il sera utile, mais SANS AUCUNE GARANTIE; sans même la garantie implicite de QUALITÉ MARCHANDE ou d'ADÉQUATION À UN USAGE PARTICULIER. Voir la Licence Publique Générale GNU pour plus de détails.

Vous devriez avoir reçu une copie de la Licence Publique Générale GNU avec ce programme; sinon, écrivez à la Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

## 👤 Auteur

Jean-Luc PONS (jlp_38@yahoo.com)

## 🔗 Liens

- [Site Web Officiel](http://www.blockout.net/blockout2)
- [Dépôt GitHub](https://github.com/lle0x/blockout2025)
- [Kadon Enterprises](http://www.gamepuzzles.com)
