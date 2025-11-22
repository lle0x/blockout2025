# BlockOut II v2.5

![BlockOut II Gameplay](../gameplay-screenshot.png)

**3Dテトリススタイルのパズルゲーム**

BlockOut IIは、1989年にCalifornia Dreamsによって編集されたオリジナルのBlockOut DOSゲームのOpenGL適応版です。BlockOut IIは、いくつかのグラフィックの改善を除いて、オリジナルゲームと同じ機能を備えています。スコア計算もオリジナルゲームとほぼ同じです。BlockOut IIは、中毒プレイヤーのために中毒プレイヤーによって設計されました。

BlockOut IIをお楽しみください...

---

*Blockout®は、Kadon Enterprises, Inc.の登録商標であり、許可を得て使用されています。この米国企業は、1980年からポリキューブの実践セットを製造しています。[www.gamepuzzles.com](http://www.gamepuzzles.com)*

---

## 🌐 公式ホームページ

**http://www.blockout.net/blockout2**

## 🌍 言語 / Idiomas / Langues

- [English](../README.md)
- [Español](README.es.md)
- [Português](README.pt.md)
- [Français](README.fr.md)
- [Italiano](README.it.md)
- [Deutsch](README.de.md)
- [Polski](README.pl.md)
- [Română](README.ro.md)
- [中文](README.zh.md)
- [日本語](README.ja.md) (このファイル)
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

## 📦 ダウンロード

[リリースページ](https://github.com/lle0x/blockout2025/releases)からプラットフォーム用の最新リリースを入手してください：

- **Windows**: `blockout-windows-*.zip` - 展開して `Blockout.exe` を実行
- **Linux (汎用)**: `blockout-linux-x64-*.tar.gz` - 展開して `./blockout/blockout` を実行
- **macOS**: `blockout-macos-*.tar.gz` - 展開してバイナリを実行
- **Ubuntu/Debian**: `blockout_*.deb` - `sudo dpkg -i blockout_*.deb` でインストール
- **Fedora/RHEL**: `blockout-*.rpm` - `sudo dnf install blockout-*.rpm` でインストール
- **Arch Linux**: `blockout-*.pkg.tar.zst` - `sudo pacman -U blockout-*.pkg.tar.zst` でインストール

## 🎮 システム要件

### Windows
- OpenGLサポート

### Linux
**ランタイム:**
- `libgl1-mesa`
- `libglu1-mesa`
- `libxext6`
- `libsdl1.2`
- `libsdl-mixer1.2`

**ビルド依存関係:**
- `build-essential`
- `libgl1-mesa-dev`
- `libglu1-mesa-dev`
- `libxext-dev`
- `libsdl1.2-dev`
- `libsdl-mixer1.2-dev`
- `libasound2-dev`

### macOS
- SDL 1.2 (sdl12-compat経由)
- SDL_mixer 1.2
- OpenGL

## 📝 バージョン履歴

### 2.5
- 64ビットサポート
- OpenGLはLinuxとWindowsの両方で使用されるようになりました
- 小さなグラフィックの改善
- 練習モードの改善
- デモモードの改善（ボットプレイヤーがより良くプレイします）
- ローカルデータディレクトリをインストールディレクトリから「AppData」ディレクトリに移動

### 2.4
- フレームリミッターを追加
- デモモードを追加
- 練習モードを追加
- リプレイのバグを修正
- ランダムジェネレーターを修正（FLATブロックセット）
- フルスクリーンバグを修正（Linux）

### 2.3
- リプレイ時にプレイヤー/ランク名を追加
- 新しい句読点を追加
- 回転がブロックされたときの小さな効果
- 「書き込み用にblX.bl2replayを開けません」を修正
- 新しいスタイル（マーブル/アーケード）
- [Esc]を押したときのクラッシュを修正
- ゲームオーバー時のピットアニメーション
- ゲーム終了後にスコア詳細ページにジャンプ
- DOS blockoutサウンドプリセットを追加
- 新しいランダマイザー

### 2.2
- テンキー操作を追加
- スライダーで設定可能なブロックの透明度
- [Esc]でメニュー起動デモを中止
- スコア詳細に空のピット（フラッシュ）を追加
- オンラインスコアデータベース
- リプレイ
- クレジットページを追加
- その他のマイナーな更新

### 2.1
- ブロック降下アルゴリズムを修正
- 落下時間を少し増やしました
- 移動速度の調整を改善

### 2.0
- 初期リリース

## 🔧 ソースからのビルド

### Ubuntu/Debian

**自動:**
```bash
sudo ./install-ubuntu-deps.sh
./build-and-run.sh
```

**手動:**
```bash
# 依存関係をインストール
sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev \
  libxext-dev libsdl1.2-dev libsdl-mixer1.2-dev libasound2-dev

# ImageLibをビルド
make -C ImageLib/src

# BlockOutをビルド
make -C BlockOut _linux64=1 _release=1

# 実行
cd BlockOut
./blockout
```

### Windows

1. Microsoft Visual Studio 2022 (または 2019/2017) をインストール
2. [libsdl.org](http://www.libsdl.org) から SDL 1.2.15 開発ライブラリをインストール
3. [libsdl.org](http://www.libsdl.org/projects/SDL_mixer/release-1.2.html) から SDL_mixer 1.2.12 開発ライブラリをインストール
4. プロジェクトのプロパティで適切なインクルードパスとライブラリパスを設定
5. ソリューションをビルド

### macOS

```bash
# Homebrew経由で依存関係をインストール
brew install sdl12-compat pkg-config

# ソースからSDL_mixer 1.2をビルド (.github/workflows/build-macos-brew.ymlを参照)

# ImageLibをビルド
make -C ImageLib/src

# BlockOutをビルド
make -C BlockOut _macos=1

# 実行
cd BlockOut
./blockout
```

## 🤖 GitHub Actions CI/CD

このリポジトリは、すべてのプラットフォームでの自動ビルドとリリースにGitHub Actionsを使用しています。

### 利用可能なワークフロー

#### ビルドワークフロー（自動）

- **`build-windows.yml`** - Windows x64バイナリをビルド
- **`build-macos-brew.yml`** - macOSバイナリをビルド
- **`build-fedora-rpm.yml`** - RPMパッケージをビルド
- **`build-arch-pkg.yml`** - Arch Linuxパッケージをビルド
- **`package-deb.yml`** - Debianパッケージをビルド

#### リリースワークフロー（手動）

- **`create-release.yml`** - 新しいリリースを作成

### リリースプロセス

1. すべての変更が `development` にマージされ、テストされていることを確認します
2. GitHub Actions → "Create Release" ワークフローに移動します
3. "Run workflow" をクリックします
4. バージョン番号を入力します（例：`v2.5.0`）
5. ワークフローはマージ、タグ付け、ビルド、リリースを行います

## 🎯 ゲーム機能

### リプレイシステム
ハイスコアを出すたびに、リプレイディレクトリに `.bl2replay` ファイルが作成されます。

### スコアアップロード
スコア詳細ページからオンラインデータベースにハイスコアをアップロードします。

### ランダマイザー
BlockOut IIは、ランダムに並べ替えられたすべての可能なピースのシーケンスを生成するバッグランダマイザーを使用します。

### フレームリミッター
アニメーションをモニターの垂直ブランキングと同期させるには、フレームリミッター設定でVSyncを選択します。

## 📜 ライセンス

このプログラムはフリーソフトウェアです。GNU General Public Licenseの条件の下で再配布および/または変更することができます。

## 👤 著者

Jean-Luc PONS (jlp_38@yahoo.com)

## 🔗 リンク

- [公式サイト](http://www.blockout.net/blockout2)
- [GitHub リポジトリ](https://github.com/lle0x/blockout2025)
- [Kadon Enterprises](http://www.gamepuzzles.com)
