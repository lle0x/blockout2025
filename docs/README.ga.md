# BlockOut II v2.5

![BlockOut II Gameplay](../gameplay-screenshot.png)

**Cluiche puzail stíl Tetris 3D**

Is oiriúnú OpenGL é BlockOut II den chluiche bunaidh BlockOut DOS a d'eisigh California Dreams in 1989. Tá na gnéithe céanna ag BlockOut II leis an gcluiche bunaidh le roinnt feabhsuithe grafaice. Tá ríomh scór beagnach cosúil leis an gcluiche bunaidh freisin. Dearadh BlockOut II ag imreoir andúileach d'imreoirí andúileacha.

Bain sult as BlockOut II...

---

*Is trádmharc cláraithe de chuid Kadon Enterprises, Inc. é Blockout®, a úsáidtear le cead. Táirgeann an chuideachta Meiriceánach seo sraitheanna polacúb ó 1980. [www.gamepuzzles.com](http://www.gamepuzzles.com)*

---

## 🌐 Leathanach Baile Oifigiúil

**http://www.blockout.net/blockout2**

## 🌍 Teangacha / Idiomas / Langues

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
- [Gaeilge](README.ga.md) (an comhad seo)
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

## 📦 Íoslódálacha

Faigh an leagan is déanaí do d'ardán ón [leathanach Eisiúintí](https://github.com/lle0x/blockout2025/releases):

- **Windows**: `blockout-windows-*.zip` - Bain amach agus rith `Blockout.exe`
- **Linux (Ginearálta)**: `blockout-linux-x64-*.tar.gz` - Bain amach agus rith `./blockout/blockout`
- **macOS**: `blockout-macos-*.tar.gz` - Bain amach agus rith an dénártha
- **Ubuntu/Debian**: `blockout_*.deb` - Suiteáil le `sudo dpkg -i blockout_*.deb`
- **Fedora/RHEL**: `blockout-*.rpm` - Suiteáil le `sudo dnf install blockout-*.rpm`
- **Arch Linux**: `blockout-*.pkg.tar.zst` - Suiteáil le `sudo pacman -U blockout-*.pkg.tar.zst`

## 🎮 Riachtanais Córais

### Windows
- Tacaíocht OpenGL

### Linux
**Am Rite:**
- `libgl1-mesa`
- `libglu1-mesa`
- `libxext6`
- `libsdl1.2`
- `libsdl-mixer1.2`

**Spleáchais Tógála:**
- `build-essential`
- `libgl1-mesa-dev`
- `libglu1-mesa-dev`
- `libxext-dev`
- `libsdl1.2-dev`
- `libsdl-mixer1.2-dev`
- `libasound2-dev`

### macOS
- SDL 1.2 (trí sdl12-compat)
- SDL_mixer 1.2
- OpenGL

## 📝 Stair Leaganacha

### 2.5
- Tacaíocht 64-giotán
- Úsáidtear OpenGL anois ar Linux agus Windows araon
- Feabhsuithe grafaice beaga
- Feabhsuithe ar mhód cleachtaidh
- Mód taispeána feabhsaithe (imríonn imreoir Bot níos fearr)
- Eolaire sonraí áitiúil bogtha ó eolaire suiteála go dtí eolaire "AppData"

### 2.4
- Teorantóir fráma curtha leis
- Mód taispeána curtha leis
- Mód cleachtaidh curtha leis
- Fabht athsheinm deisithe
- Gineadóir randamach deisithe (tacar bloc FLAT)
- Fabht lánscáileán deisithe (Linux)

### 2.3
- Ainm imreora/ranga curtha leis agus athsheinm ar siúl
- Carachtair poncaíochta nua curtha leis
- Éifeacht bheag nuair a bhíonn rothlú blocáilte
- "Ní féidir blX.bl2replay a oscailt le haghaidh scríofa" deisithe
- Stíl nua (Marmar/Arcade)
- Tuairt nuair a bhrúitear [Esc] deisithe
- Beochan poll nuair a bhíonn an cluiche thart
- Léim go dtí leathanach Sonraí Scór tar éis deireadh cluiche
- Réamhshocrú fuaime DOS blockout curtha leis
- Randamóir nua

### 2.2
- Rialú eochracha NUMPAD curtha leis
- Trédhearcacht bloc inchumraithe le sleamhnán
- Cuir deireadh le taispeántas tosaithe roghchláir le [Esc]
- Poll folamh (Flush) i sonraí scór curtha leis
- Bunachar sonraí scór ar líne
- Athsheinm
- Leathanach creidmheasanna curtha leis
- Nuashonruithe beaga eile

### 2.1
- Algartam tuirlingthe bloc deisithe
- Am titim méadaithe beagán
- Tiúnáil feabhsaithe ar luas gluaisne

### 2.0
- Eisiúint tosaigh

## 🔧 Tógáil ó Fhoinse

### Ubuntu/Debian

**Uathoibrithe:**
```bash
sudo ./install-ubuntu-deps.sh
./build-and-run.sh
```

**Láimhe:**
```bash
# Suiteáil spleáchais
sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev \
  libxext-dev libsdl1.2-dev libsdl-mixer1.2-dev libasound2-dev

# Tóg ImageLib
make -C ImageLib/src

# Tóg BlockOut
make -C BlockOut _linux64=1 _release=1

# Rith
cd BlockOut
./blockout
```

### Windows

1. Suiteáil Microsoft Visual Studio 2022 (nó 2019/2017)
2. Suiteáil leabharlanna forbartha SDL 1.2.15 ó [libsdl.org](http://www.libsdl.org)
3. Suiteáil leabharlanna forbartha SDL_mixer 1.2.12 ó [libsdl.org](http://www.libsdl.org/projects/SDL_mixer/release-1.2.html)
4. Socraigh cosáin cuí include agus lib i maoine tionscadail
5. Tóg an réiteach

### macOS

```bash
# Suiteáil spleáchais trí Homebrew
brew install sdl12-compat pkg-config

# Tóg SDL_mixer 1.2 ó fhoinse (féach .github/workflows/build-macos-brew.yml)

# Tóg ImageLib
make -C ImageLib/src

# Tóg BlockOut
make -C BlockOut _macos=1

# Rith
cd BlockOut
./blockout
```

## 🤖 GitHub Actions CI/CD

Úsáideann an stóras seo GitHub Actions le haghaidh tógála agus eisiúna uathoibríoch ar gach ardán.

### Sreafaí Oibre ar Fáil

#### Sreafaí Oibre Tógála (Uathoibríoch)

- **`build-windows.yml`** - Tógann dénárthaí Windows x64
- **`build-macos-brew.yml`** - Tógann dénárthaí macOS
- **`build-fedora-rpm.yml`** - Tógann pacáistí RPM
- **`build-arch-pkg.yml`** - Tógann pacáistí Arch Linux
- **`package-deb.yml`** - Tógann pacáistí Debian

#### Sreabhadh Oibre Eisiúna (Láimhe)

- **`create-release.yml`** - Cruthaíonn eisiúint nua

### Próiseas Eisiúna

1. Cinntigh go bhfuil gach athrú cumaisc le `development` agus tástáilte
2. Téigh go GitHub Actions → Sreabhadh oibre "Create Release"
3. Cliceáil "Run workflow"
4. Cuir isteach uimhir leagain (m.sh. `v2.5.0`)
5. Déanfaidh an sreabhadh oibre cumascadh, clibeáil, tógáil agus eisiúint

## 🎯 Gnéithe Cluiche

### Córas Athsheinm
Do gach ardscór a dhéanann tú, cruthaítear comhad `.bl2replay` san eolaire athsheinm.

### Uaslódáil Scóir
Uaslódáil d'ardscóir chuig an mbunachar sonraí ar líne ón leathanach Sonraí Scór.

### Randamóir
Úsáideann BlockOut II randamóir mála a ghineann seicheamh de na píosaí uile is féidir permuted go randamach.

### Teorantóir Fráma
Chun beochaintí a shioncronú le blanking ingearach do mhonatóir, roghnaigh VSync i socruithe an theorantóra fráma.

## 📜 Ceadúnas

Is bogearraí saor in aisce é an clár seo; is féidir leat é a athdháileadh agus/nó a mhodhnú faoi théarmaí an GNU General Public License.

## 👤 Údar

Jean-Luc PONS (jlp_38@yahoo.com)

## 🔗 Naisc

- [Suíomh Oifigiúil](http://www.blockout.net/blockout2)
- [Stóras GitHub](https://github.com/lle0x/blockout2025)
- [Kadon Enterprises](http://www.gamepuzzles.com)
