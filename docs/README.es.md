# BlockOut II v2.5

![BlockOut II Gameplay](../gameplay-screenshot.png)

**Un juego de puzles estilo Tetris 3D**

BlockOut II es una adaptación OpenGL del juego original BlockOut para DOS editado por California Dreams en 1989. BlockOut II tiene las mismas características que el juego original con algunas mejoras gráficas. El cálculo de puntuación es también muy similar al juego original. BlockOut II ha sido diseñado por un jugador adicto para jugadores adictos.

Diviértete con BlockOut II...

---

*Blockout® es una marca registrada de Kadon Enterprises, Inc., usada con permiso. Esta compañía estadounidense produce conjuntos de policubos desde 1980. [www.gamepuzzles.com](http://www.gamepuzzles.com)*

---

## 🌐 Página Oficial

**http://www.blockout.net/blockout2**

## 🌍 Idiomas / Languages / Langues

- [English](../README.md)
- [Español](README.es.md) (este archivo)
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
- [Türkçe](README.tr.md)
- [Afrikaans](README.af.md)
- [العربية](README.ar.md)

## 📦 Descargas

Obtén la última versión para tu plataforma desde la [página de Releases](https://github.com/lle0x/blockout2025/releases):

- **Windows**: `blockout-windows-*.zip` - Extrae y ejecuta `Blockout.exe`
- **Linux (Genérico)**: `blockout-linux-x64-*.tar.gz` - Extrae y ejecuta `./blockout/blockout`
- **macOS**: `blockout-macos-*.tar.gz` - Extrae y ejecuta el binario
- **Ubuntu/Debian**: `blockout_*.deb` - Instala con `sudo dpkg -i blockout_*.deb`
- **Fedora/RHEL**: `blockout-*.rpm` - Instala con `sudo dnf install blockout-*.rpm`
- **Arch Linux**: `blockout-*.pkg.tar.zst` - Instala con `sudo pacman -U blockout-*.pkg.tar.zst`

## 🎮 Requisitos del Sistema

### Windows
- Soporte OpenGL

### Linux
**Tiempo de ejecución:**
- `libgl1-mesa`
- `libglu1-mesa`
- `libxext6`
- `libsdl1.2`
- `libsdl-mixer1.2`

**Dependencias de compilación:**
- `build-essential`
- `libgl1-mesa-dev`
- `libglu1-mesa-dev`
- `libxext-dev`
- `libsdl1.2-dev`
- `libsdl-mixer1.2-dev`
- `libasound2-dev`

### macOS
- SDL 1.2 (vía sdl12-compat)
- SDL_mixer 1.2
- OpenGL

## 📝 Historial de Versiones

### 2.5
- Soporte de 64 bits
- OpenGL ahora se usa tanto en Linux como en Windows
- Pequeñas mejoras gráficas
- Mejoras en el modo de práctica
- Modo demostración mejorado (el jugador Bot juega mejor)
- Directorio de datos local movido del directorio de instalación al directorio "AppData"

### 2.4
- Añadido limitador de fotogramas
- Añadido modo demostración
- Añadido modo de práctica
- Corregido error de repetición
- Corregido generador aleatorio (conjunto de bloques FLAT)
- Corregido error de pantalla completa (Linux)

### 2.3
- Añadido nombre de jugador/rango al reproducir
- Nuevos caracteres de puntuación añadidos
- Pequeño efecto cuando la rotación está bloqueada
- Corregido "No se puede abrir blX.bl2replay para escritura"
- Nuevo estilo (Mármol/Arcade)
- Corregido bloqueo al presionar [Esc]
- Animación del pozo cuando el juego termina
- Saltar a la página de Detalles de Puntuación después del fin del juego
- Añadido preset de sonido de DOS blockout
- Nuevo aleatorizador

### 2.2
- Añadido control de teclas del teclado numérico
- Transparencia de bloques configurable con deslizador
- Abortar demostración de inicio del menú con [Esc]
- Pozo vacío (Flush) añadido en detalles de puntuación
- Base de datos de puntuaciones en línea
- Repetición
- Página de créditos añadida
- Otras actualizaciones menores

### 2.1
- Corregido algoritmo de descenso de bloques
- Aumentado ligeramente el tiempo de caída
- Mejorado el ajuste de la velocidad de movimiento

### 2.0
- Lanzamiento inicial

## 🔧 Compilar desde el Código Fuente

### Ubuntu/Debian

**Automatizado:**
```bash
sudo ./install-ubuntu-deps.sh
./build-and-run.sh
```

**Manual:**
```bash
# Instalar dependencias
sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev \
  libxext-dev libsdl1.2-dev libsdl-mixer1.2-dev libasound2-dev

# Compilar ImageLib
make -C ImageLib/src

# Compilar BlockOut
make -C BlockOut _linux64=1 _release=1

# Ejecutar
cd BlockOut
./blockout
```

### Windows

1. Instala Microsoft Visual Studio 2022 (o 2019/2017)
2. Instala las bibliotecas de desarrollo SDL 1.2.15 desde [libsdl.org](http://www.libsdl.org)
3. Instala las bibliotecas de desarrollo SDL_mixer 1.2.12 desde [libsdl.org](http://www.libsdl.org/projects/SDL_mixer/release-1.2.html)
4. Configura las rutas de inclusión y bibliotecas apropiadas en las propiedades del proyecto
5. Compila la solución

### macOS

```bash
# Instalar dependencias vía Homebrew
brew install sdl12-compat pkg-config

# Compilar SDL_mixer 1.2 desde el código fuente (ver .github/workflows/build-macos-brew.yml)

# Compilar ImageLib
make -C ImageLib/src

# Compilar BlockOut
make -C BlockOut _macos=1

# Ejecutar
cd BlockOut
./blockout
```

## 🤖 GitHub Actions CI/CD

Este repositorio usa GitHub Actions para compilación y lanzamiento automatizados en todas las plataformas. Los flujos de trabajo se activan con pushes a las ramas `main` y `development`.

### Flujos de Trabajo Disponibles

#### Flujos de Trabajo de Compilación (Automatizados)

- **`build-windows.yml`** - Compila binarios Windows x64 y crea un paquete zip
  - Compila con Visual Studio 2022 (conjunto de herramientas v143)
  - Incluye DLLs de tiempo de ejecución SDL y recursos del juego
  - Salida: `blockout-windows-*.zip`

- **`build-macos-brew.yml`** - Compila binarios macOS usando dependencias de Homebrew
  - Usa `sdl12-compat` para compatibilidad con API SDL 1.2
  - Compila SDL_mixer 1.2 desde el código fuente
  - Salida: `blockout-macos-*.tar.gz`

- **`build-fedora-rpm.yml`** - Compila paquetes RPM para Fedora/RHEL
  - Compila en contenedor Fedora
  - Salida: `blockout-*.rpm`

- **`build-arch-pkg.yml`** - Compila paquetes Arch Linux
  - Usa `makepkg` en contenedor Arch
  - Salida: `blockout-*.pkg.tar.zst`

- **`package-deb.yml`** - Compila paquetes Debian para múltiples versiones de Ubuntu
  - Compila para Ubuntu 24.04, 25.04 y 25.10
  - Salida: `blockout-*-ubuntu*.deb`

#### Flujo de Trabajo de Lanzamiento (Manual)

- **`create-release.yml`** - Crea un nuevo lanzamiento (solo activación manual)
  - Fusiona `development` en `main`
  - Crea una etiqueta de versión
  - Compila un tarball genérico Linux x64
  - Espera a que se completen todas las compilaciones de plataforma
  - Crea un Release de GitHub con todos los paquetes de plataforma
  - **Uso**: Ve a Actions → "Create Release" → Run workflow → Ingresa versión (ej., `v2.5.0`)

### Activar Compilaciones

Todos los flujos de trabajo de compilación se activan automáticamente con:
- Push a las ramas `main` o `development`
- Cambios en archivos fuente (`BlockOut/**`, `ImageLib/**`)
- Cambios en el propio archivo de flujo de trabajo

También puedes activar manualmente cualquier flujo de trabajo desde la pestaña GitHub Actions.

### Proceso de Lanzamiento

1. Asegúrate de que todos los cambios estén fusionados en `development` y probados
2. Ve a GitHub Actions → flujo de trabajo "Create Release"
3. Haz clic en "Run workflow"
4. Ingresa el número de versión (ej., `v2.5.0`)
5. El flujo de trabajo:
   - Fusionará `development` → `main`
   - Creará y empujará la etiqueta de versión
   - Compilará todos los paquetes de plataforma
   - Creará un Release de GitHub con todos los artefactos

## 🎯 Características del Juego

### Sistema de Repetición
Por cada puntuación alta que hagas, se crea un archivo `.bl2replay` en el directorio de repeticiones. Estos archivos contienen datos de repetición necesarios para subir puntuaciones a la base de datos en línea. Una repetición solo puede subirse una vez después del registro exitoso.

### Subida de Puntuaciones
Sube tus puntuaciones altas a la base de datos en línea desde la página de Detalles de Puntuación. Solo las puntuaciones de la versión 2.2+ pueden subirse (se requiere archivo de repetición).

### Aleatorizador
BlockOut II usa un aleatorizador de bolsa que genera una secuencia de todas las piezas posibles (dependiendo de la dimensión del pozo y conjunto de bloques) permutadas aleatoriamente. Reparte todas las piezas antes de generar otra bolsa, evitando obtener la misma pieza 3 veces seguidas.

### Limitador de Fotogramas
Para sincronizar las animaciones con el blanqueo vertical de tu monitor, selecciona VSync en la configuración del limitador de fotogramas, guarda y reinicia la aplicación.

## 📜 Licencia

Este programa es software libre; puedes redistribuirlo y/o modificarlo bajo los términos de la Licencia Pública General de GNU publicada por la Free Software Foundation; ya sea la versión 2 de la Licencia, o (a tu elección) cualquier versión posterior.

Este programa se distribuye con la esperanza de que sea útil, pero SIN NINGUNA GARANTÍA; sin siquiera la garantía implícita de COMERCIABILIDAD o IDONEIDAD PARA UN PROPÓSITO PARTICULAR. Consulta la Licencia Pública General de GNU para más detalles.

Deberías haber recibido una copia de la Licencia Pública General de GNU junto con este programa; si no, escribe a la Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

## 👤 Autor

Jean-Luc PONS (jlp_38@yahoo.com)

## 🔗 Enlaces

- [Sitio Web Oficial](http://www.blockout.net/blockout2)
- [Repositorio GitHub](https://github.com/lle0x/blockout2025)
- [Kadon Enterprises](http://www.gamepuzzles.com)
