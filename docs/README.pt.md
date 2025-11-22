# BlockOut II v2.5

![BlockOut II Gameplay](../gameplay-screenshot.png)

**Um jogo de quebra-cabeça estilo Tetris 3D**

BlockOut II é uma adaptação OpenGL do jogo original BlockOut para DOS editado pela California Dreams em 1989. BlockOut II tem as mesmas características do jogo original com algumas melhorias gráficas. O cálculo de pontuação também é muito similar ao jogo original. BlockOut II foi projetado por um jogador viciado para jogadores viciados.

Divirta-se com BlockOut II...

---

*Blockout® é uma marca registrada da Kadon Enterprises, Inc., usada com permissão. Esta empresa americana produz conjuntos de policubos desde 1980. [www.gamepuzzles.com](http://www.gamepuzzles.com)*

---

## 🌐 Página Oficial

**http://www.blockout.net/blockout2**

## 🌍 Idiomas / Languages / Langues

- [English](../README.md)
- [Español](README.es.md)
- [Português](README.pt.md) (este arquivo)
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
- [Türkçe](README.tr.md)
- [Afrikaans](README.af.md)
- [العربية](README.ar.md)

## 📦 Downloads

Obtenha a versão mais recente para sua plataforma na [página de Releases](https://github.com/lle0x/blockout2025/releases):

- **Windows**: `blockout-windows-*.zip` - Extraia e execute `Blockout.exe`
- **Linux (Genérico)**: `blockout-linux-x64-*.tar.gz` - Extraia e execute `./blockout/blockout`
- **macOS**: `blockout-macos-*.tar.gz` - Extraia e execute o binário
- **Ubuntu/Debian**: `blockout_*.deb` - Instale com `sudo dpkg -i blockout_*.deb`
- **Fedora/RHEL**: `blockout-*.rpm` - Instale com `sudo dnf install blockout-*.rpm`
- **Arch Linux**: `blockout-*.pkg.tar.zst` - Instale com `sudo pacman -U blockout-*.pkg.tar.zst`

## 🎮 Requisitos do Sistema

### Windows
- Suporte OpenGL

### Linux
**Tempo de execução:**
- `libgl1-mesa`
- `libglu1-mesa`
- `libxext6`
- `libsdl1.2`
- `libsdl-mixer1.2`

**Dependências de compilação:**
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

## 📝 Histórico de Versões

### 2.5
- Suporte de 64 bits
- OpenGL agora é usado tanto no Linux quanto no Windows
- Pequenas melhorias gráficas
- Melhorias no modo de prática
- Modo demonstração melhorado (o jogador Bot joga melhor)
- Diretório de dados local movido do diretório de instalação para o diretório "AppData"

### 2.4
- Adicionado limitador de quadros
- Adicionado modo demonstração
- Adicionado modo de prática
- Corrigido erro de repetição
- Corrigido gerador aleatório (conjunto de blocos FLAT)
- Corrigido erro de tela cheia (Linux)

### 2.3
- Adicionado nome de jogador/classificação ao reproduzir
- Novos caracteres de pontuação adicionados
- Pequeno efeito quando a rotação está bloqueada
- Corrigido "Não é possível abrir blX.bl2replay para escrita"
- Novo estilo (Mármore/Arcade)
- Corrigido travamento ao pressionar [Esc]
- Animação do poço quando o jogo termina
- Pular para a página de Detalhes de Pontuação após o fim do jogo
- Adicionado preset de som do DOS blockout
- Novo randomizador

### 2.2
- Adicionado controle de teclas do teclado numérico
- Transparência de blocos configurável com controle deslizante
- Abortar demonstração de início do menu com [Esc]
- Poço vazio (Flush) adicionado em detalhes de pontuação
- Banco de dados de pontuações online
- Repetição
- Página de créditos adicionada
- Outras atualizações menores

### 2.1
- Corrigido algoritmo de descida de blocos
- Aumentado ligeiramente o tempo de queda
- Melhorado o ajuste da velocidade de movimento

### 2.0
- Lançamento inicial

## 🔧 Compilar do Código Fonte

### Ubuntu/Debian

**Automatizado:**
```bash
sudo ./install-ubuntu-deps.sh
./build-and-run.sh
```

**Manual:**
```bash
# Instalar dependências
sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev \
  libxext-dev libsdl1.2-dev libsdl-mixer1.2-dev libasound2-dev

# Compilar ImageLib
make -C ImageLib/src

# Compilar BlockOut
make -C BlockOut _linux64=1 _release=1

# Executar
cd BlockOut
./blockout
```

### Windows

1. Instale o Microsoft Visual Studio 2022 (ou 2019/2017)
2. Instale as bibliotecas de desenvolvimento SDL 1.2.15 de [libsdl.org](http://www.libsdl.org)
3. Instale as bibliotecas de desenvolvimento SDL_mixer 1.2.12 de [libsdl.org](http://www.libsdl.org/projects/SDL_mixer/release-1.2.html)
4. Configure os caminhos de inclusão e bibliotecas apropriados nas propriedades do projeto
5. Compile a solução

### macOS

```bash
# Instalar dependências via Homebrew
brew install sdl12-compat pkg-config

# Compilar SDL_mixer 1.2 do código fonte (veja .github/workflows/build-macos-brew.yml)

# Compilar ImageLib
make -C ImageLib/src

# Compilar BlockOut
make -C BlockOut _macos=1

# Executar
cd BlockOut
./blockout
```

## 🤖 GitHub Actions CI/CD

Este repositório usa GitHub Actions para compilação e lançamento automatizados em todas as plataformas. Os fluxos de trabalho são acionados em pushes para as branches `main` e `development`.

### Fluxos de Trabalho Disponíveis

#### Fluxos de Trabalho de Compilação (Automatizados)

- **`build-windows.yml`** - Compila binários Windows x64 e cria um pacote zip
  - Compila com Visual Studio 2022 (conjunto de ferramentas v143)
  - Inclui DLLs de tempo de execução SDL e recursos do jogo
  - Saída: `blockout-windows-*.zip`

- **`build-macos-brew.yml`** - Compila binários macOS usando dependências do Homebrew
  - Usa `sdl12-compat` para compatibilidade com API SDL 1.2
  - Compila SDL_mixer 1.2 do código fonte
  - Saída: `blockout-macos-*.tar.gz`

- **`build-fedora-rpm.yml`** - Compila pacotes RPM para Fedora/RHEL
  - Compila em contêiner Fedora
  - Saída: `blockout-*.rpm`

- **`build-arch-pkg.yml`** - Compila pacotes Arch Linux
  - Usa `makepkg` em contêiner Arch
  - Saída: `blockout-*.pkg.tar.zst`

- **`package-deb.yml`** - Compila pacotes Debian para múltiplas versões do Ubuntu
  - Compila para Ubuntu 24.04, 25.04 e 25.10
  - Saída: `blockout-*-ubuntu*.deb`

#### Fluxo de Trabalho de Lançamento (Manual)

- **`create-release.yml`** - Cria um novo lançamento (apenas acionamento manual)
  - Mescla `development` em `main`
  - Cria uma tag de versão
  - Compila um tarball genérico Linux x64
  - Aguarda a conclusão de todas as compilações de plataforma
  - Cria um Release do GitHub com todos os pacotes de plataforma
  - **Uso**: Vá para Actions → "Create Release" → Run workflow → Digite a versão (ex., `v2.5.0`)

### Acionar Compilações

Todos os fluxos de trabalho de compilação são acionados automaticamente com:
- Push para as branches `main` ou `development`
- Alterações em arquivos fonte (`BlockOut/**`, `ImageLib/**`)
- Alterações no próprio arquivo de fluxo de trabalho

Você também pode acionar manualmente qualquer fluxo de trabalho na aba GitHub Actions.

### Processo de Lançamento

1. Certifique-se de que todas as alterações estejam mescladas em `development` e testadas
2. Vá para GitHub Actions → fluxo de trabalho "Create Release"
3. Clique em "Run workflow"
4. Digite o número da versão (ex., `v2.5.0`)
5. O fluxo de trabalho irá:
   - Mesclar `development` → `main`
   - Criar e enviar a tag de versão
   - Compilar todos os pacotes de plataforma
   - Criar um Release do GitHub com todos os artefatos

## 🎯 Recursos do Jogo

### Sistema de Repetição
Para cada pontuação alta que você fizer, um arquivo `.bl2replay` é criado no diretório de repetições. Esses arquivos contêm dados de repetição necessários para enviar pontuações ao banco de dados online. Uma repetição só pode ser enviada uma vez após o registro bem-sucedido.

### Envio de Pontuações
Envie suas pontuações altas para o banco de dados online na página de Detalhes de Pontuação. Apenas pontuações da versão 2.2+ podem ser enviadas (arquivo de repetição necessário).

### Randomizador
BlockOut II usa um randomizador de saco que gera uma sequência de todas as peças possíveis (dependendo da dimensão do poço e conjunto de blocos) permutadas aleatoriamente. Ele distribui todas as peças antes de gerar outro saco, evitando obter a mesma peça 3 vezes seguidas.

### Limitador de Quadros
Para sincronizar as animações com o blanking vertical do seu monitor, selecione VSync nas configurações do limitador de quadros, salve e reinicie a aplicação.

## 📜 Licença

Este programa é software livre; você pode redistribuí-lo e/ou modificá-lo sob os termos da Licença Pública Geral GNU publicada pela Free Software Foundation; seja a versão 2 da Licença, ou (a seu critério) qualquer versão posterior.

Este programa é distribuído na esperança de que seja útil, mas SEM QUALQUER GARANTIA; sem mesmo a garantia implícita de COMERCIALIZAÇÃO ou ADEQUAÇÃO A UM PROPÓSITO ESPECÍFICO. Consulte a Licença Pública Geral GNU para mais detalhes.

Você deve ter recebido uma cópia da Licença Pública Geral GNU junto com este programa; caso contrário, escreva para a Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

## 👤 Autor

Jean-Luc PONS (jlp_38@yahoo.com)

## 🔗 Links

- [Site Oficial](http://www.blockout.net/blockout2)
- [Repositório GitHub](https://github.com/lle0x/blockout2025)
- [Kadon Enterprises](http://www.gamepuzzles.com)
