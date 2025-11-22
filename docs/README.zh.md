# BlockOut II v2.5

![BlockOut II Gameplay](../gameplay-screenshot.png)

**一个3D俄罗斯方块风格的益智游戏**

BlockOut II 是原版 BlockOut DOS 游戏的 OpenGL 改编版，原版游戏由 California Dreams 于 1989 年发行。BlockOut II 拥有与原版游戏相同的功能，并进行了一些图形改进。分数计算也与原版游戏几乎相似。BlockOut II 是由一位沉迷其中的玩家为其他沉迷其中的玩家设计的。

尽情享受 BlockOut II...

---

*Blockout® 是 Kadon Enterprises, Inc. 的注册商标，经许可使用。这家美国公司自 1980 年以来一直生产实用的多立方体套装。[www.gamepuzzles.com](http://www.gamepuzzles.com)*

---

## 🌐 官方主页

**http://www.blockout.net/blockout2**

## 🌍 语言 / Idiomas / Langues

- [English](../README.md)
- [Español](README.es.md)
- [Português](README.pt.md)
- [Français](README.fr.md)
- [Italiano](README.it.md)
- [Deutsch](README.de.md)
- [Polski](README.pl.md)
- [Română](README.ro.md)
- [中文](README.zh.md) (此文件)
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

## 📦 下载

从 [发布页面](https://github.com/lle0x/blockout2025/releases) 获取适用于您平台的最新版本：

- **Windows**: `blockout-windows-*.zip` - 解压并运行 `Blockout.exe`
- **Linux (通用)**: `blockout-linux-x64-*.tar.gz` - 解压并运行 `./blockout/blockout`
- **macOS**: `blockout-macos-*.tar.gz` - 解压并运行二进制文件
- **Ubuntu/Debian**: `blockout_*.deb` - 使用 `sudo dpkg -i blockout_*.deb` 安装
- **Fedora/RHEL**: `blockout-*.rpm` - 使用 `sudo dnf install blockout-*.rpm` 安装
- **Arch Linux**: `blockout-*.pkg.tar.zst` - 使用 `sudo pacman -U blockout-*.pkg.tar.zst` 安装

## 🎮 系统要求

### Windows
- OpenGL 支持

### Linux
**运行时:**
- `libgl1-mesa`
- `libglu1-mesa`
- `libxext6`
- `libsdl1.2`
- `libsdl-mixer1.2`

**构建依赖:**
- `build-essential`
- `libgl1-mesa-dev`
- `libglu1-mesa-dev`
- `libxext-dev`
- `libsdl1.2-dev`
- `libsdl-mixer1.2-dev`
- `libasound2-dev`

### macOS
- SDL 1.2 (通过 sdl12-compat)
- SDL_mixer 1.2
- OpenGL

## 📝 版本历史

### 2.5
- 64位支持
- OpenGL 现在在 Linux 和 Windows 上都使用
- 小的图形改进
- 练习模式改进
- 改进的演示模式（Bot 玩家玩得更好）
- 本地数据目录从安装目录移动到 "AppData" 目录

### 2.4
- 添加了帧限制器
- 添加了演示模式
- 添加了练习模式
- 修复了回放错误
- 修复了随机生成器（FLAT 块集）
- 修复了全屏错误（Linux）

### 2.3
- 回放时添加了玩家/排名名称
- 添加了新的标点符号
- 旋转被阻止时的小效果
- 修复了 "无法打开 blX.bl2replay 进行写入"
- 新风格（大理石/街机）
- 修复了按 [Esc] 时的崩溃
- 游戏结束时的深坑动画
- 游戏结束后跳转到分数详情页面
- 添加了 DOS blockout 声音预设
- 新的随机生成器

### 2.2
- 添加了数字键盘控制
- 块透明度可通过滑块配置
- 使用 [Esc] 中止菜单启动演示
- 在分数详情中添加了空坑（Flush）
- 在线分数数据库
- 回放
- 添加了致谢页面
- 其他小更新

### 2.1
- 修复了块下降算法
- 稍微增加了下降时间
- 改进了运动速度的调整

### 2.0
- 初始版本

## 🔧 从源码编译

### Ubuntu/Debian

**自动:**
```bash
sudo ./install-ubuntu-deps.sh
./build-and-run.sh
```

**手动:**
```bash
# 安装依赖
sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev \
  libxext-dev libsdl1.2-dev libsdl-mixer1.2-dev libasound2-dev

# 构建 ImageLib
make -C ImageLib/src

# 构建 BlockOut
make -C BlockOut _linux64=1 _release=1

# 运行
cd BlockOut
./blockout
```

### Windows

1. 安装 Microsoft Visual Studio 2022 (或 2019/2017)
2. 从 [libsdl.org](http://www.libsdl.org) 安装 SDL 1.2.15 开发库
3. 从 [libsdl.org](http://www.libsdl.org/projects/SDL_mixer/release-1.2.html) 安装 SDL_mixer 1.2.12 开发库
4. 在项目属性中设置适当的包含和库路径
5. 构建解决方案

### macOS

```bash
# 通过 Homebrew 安装依赖
brew install sdl12-compat pkg-config

# 从源码构建 SDL_mixer 1.2 (参见 .github/workflows/build-macos-brew.yml)

# 构建 ImageLib
make -C ImageLib/src

# 构建 BlockOut
make -C BlockOut _macos=1

# 运行
cd BlockOut
./blockout
```

## 🤖 GitHub Actions CI/CD

此存储库使用 GitHub Actions 在所有平台上进行自动构建和发布。

### 可用的工作流

#### 构建工作流（自动）

- **`build-windows.yml`** - 构建 Windows x64 二进制文件
- **`build-macos-brew.yml`** - 构建 macOS 二进制文件
- **`build-fedora-rpm.yml`** - 构建 RPM 包
- **`build-arch-pkg.yml`** - 构建 Arch Linux 包
- **`package-deb.yml`** - 构建 Debian 包

#### 发布工作流（手动）

- **`create-release.yml`** - 创建新版本

### 发布流程

1. 确保所有更改都已合并到 `development` 并经过测试
2. 转到 GitHub Actions → "Create Release" 工作流
3. 点击 "Run workflow"
4. 输入版本号（例如 `v2.5.0`）
5. 工作流将合并、标记、构建和发布

## 🎯 游戏特色

### 回放系统
对于您取得的每个高分，都会在回放目录中创建一个 `.bl2replay` 文件。

### 分数上传
从分数详情页面将您的高分上传到在线数据库。

### 随机生成器
BlockOut II 使用袋式随机生成器，生成随机排列的所有可能块的序列。

### 帧限制器
要将动画与显示器的垂直消隐同步，请在帧限制器设置中选择 VSync。

## 📜 许可证

此程序是自由软件；您可以根据 GNU 通用公共许可证的条款重新分发和/或修改它。

## 👤 作者

Jean-Luc PONS (jlp_38@yahoo.com)

## 🔗 链接

- [官方网站](http://www.blockout.net/blockout2)
- [GitHub 存储库](https://github.com/lle0x/blockout2025)
- [Kadon Enterprises](http://www.gamepuzzles.com)
