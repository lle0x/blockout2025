# 🚀 BlockOut II - Roadmap de Funcionalidades

Este documento contiene propuestas de funcionalidades que pueden agregarse al juego BlockOut II para mejorar la experiencia de juego y expandir sus capacidades.

---

## 🏆 Sistema de Logros y Achievements

Agregar un sistema de logros desbloqueables para aumentar la rejugabilidad y motivación del jugador.

### Características Propuestas:
- **Logros desbloqueables**: 
  - "Maestro de Líneas" - Completar 100 líneas
  - "Veterano" - Llegar al nivel 10
  - "Perfeccionista" - Hacer un tetris perfecto (pit completamente vacío)
  - "Maratonista" - Jugar durante 1 hora continua
  - "Velocista" - Completar 10 líneas en menos de 1 minuto
- **Sistema de medallas**: Bronce, Plata, Oro, Platino
- **Estadísticas detalladas del jugador**: 
  - Bloques totales colocados
  - Tiempo total jugado
  - Líneas completadas por tipo
  - Mejores rachas
- **Progreso visual** en el menú principal

### Dificultad de Implementación: 🟢 Media
### Archivos a Modificar:
- Crear: `BlockOut/Achievements.h`, `BlockOut/Achievements.cpp`
- Modificar: `BlockOut/Game.cpp`, `BlockOut/Menu.cpp`

---

## 🎯 Nuevos Modos de Juego

El juego actualmente tiene: Normal, Demo y Practice. Expandir con nuevos modos para diferentes estilos de juego.

### Modos Propuestos:

#### 1. **Modo Contra Reloj** ⏱️
Completa objetivos específicos en un tiempo límite.
- Completar 20 líneas en 5 minutos
- Alcanzar cierto puntaje antes de que termine el tiempo
- **Dificultad**: 🟢 Fácil

#### 2. **Modo Zen** 🧘
Sin límite de tiempo, enfocado en relajación y estrategia.
- Sin incremento de velocidad
- Música relajante
- Colores suaves y efectos visuales calmados
- **Dificultad**: 🟢 Fácil

#### 3. **Modo Desafío Diario** 📅
Un setup específico cada día con tabla de clasificación global.
- Semilla aleatoria diaria compartida globalmente
- Todos los jugadores tienen las mismas piezas
- Ranking mundial diario
- **Dificultad**: 🟡 Media

#### 4. **Modo Endless** ∞
Sin aumento de velocidad, solo para practicar y relajarse.
- Velocidad constante configurable
- Enfoque en puntajes altos sin presión de tiempo
- **Dificultad**: 🟢 Fácil

#### 5. **Modo Sprint** 🏃
Completar X líneas lo más rápido posible.
- Sprint de 20, 40 o 100 líneas
- Cronómetro y comparación con mejores tiempos
- **Dificultad**: 🟢 Fácil

#### 6. **Modo Supervivencia** 💀
La velocidad aumenta constantemente cada cierto tiempo.
- Velocidad incrementa cada 30 segundos
- Ver cuánto tiempo puedes sobrevivir
- **Dificultad**: 🟢 Fácil

### Archivos a Modificar:
- Modificar: `BlockOut/Game.h`, `BlockOut/Game.cpp`
- Modificar: `BlockOut/Menu.cpp` (para selección de modo)

---

## 💪 Power-ups y Habilidades

Sistema de power-ups que aparecen aleatoriamente o se ganan completando objetivos.

### Power-ups Propuestos:

1. **💣 Bomba**: Elimina bloques aleatorios del pit (configurable: 5-10 bloques)
2. **👻 Modo Fantasma**: Muestra preview de dónde caerá exactamente la pieza
3. **⏸️ Pausa de Tiempo**: Congela la caída por 5-10 segundos
4. **🔄 Rotación Libre**: Permite una rotación extra sin restricciones
5. **⬇️ Reducir Nivel**: Baja temporalmente la velocidad un nivel
6. **🌟 Línea Dorada**: La próxima línea completada vale el doble
7. **🔍 Visión de Rayos X**: Ver a través de bloques para planificar mejor

### Mecánicas:
- Power-ups aparecen cada X líneas completadas
- Se acumulan en un inventario (máximo 3)
- Activación con teclas configurables
- Efectos visuales distintivos al activarse

### Dificultad de Implementación: 🟡 Media-Alta
### Archivos a Modificar:
- Crear: `BlockOut/PowerUp.h`, `BlockOut/PowerUp.cpp`
- Modificar: `BlockOut/Game.cpp`, `BlockOut/Pit.cpp`

---

## 👥 Sistema Multijugador

Agregar capacidades multijugador tanto local como potencialmente online.

### Funcionalidades Propuestas:

#### **Multijugador Local (Pantalla Dividida)** 🎮
- 2 jugadores en la misma máquina
- Dos pits lado a lado
- Opciones competitivas:
  - Enviar "basura" al oponente al completar múltiples líneas
  - Primer jugador en completar X líneas gana
  - Mayor puntaje en tiempo determinado
- **Dificultad**: 🟡 Media

#### **Modo Cooperativo** 🤝
- Dos jugadores controlan piezas en el mismo pit
- Trabajar juntos para sobrevivir
- Requiere coordinación y comunicación
- **Dificultad**: 🟡 Media-Alta

#### **Multijugador Online** 🌐
- Matchmaking entre jugadores
- Salas privadas con códigos
- Sistema de ranking/ELO
- Sincronización de estado del juego
- **Dificultad**: 🔴 Alta

### Archivos a Modificar:
- Crear: `BlockOut/Multiplayer.h`, `BlockOut/Multiplayer.cpp`
- Modificar: `BlockOut/Game.cpp`, `BlockOut/Render.cpp`
- Para online: Integrar con servidor (posiblemente WebSocket)

---

## 🎨 Personalización Visual Avanzada

El juego ya tiene temas Marble/Arcade. Expandir con más opciones de personalización.

### Temas Visuales Nuevos:

1. **🌟 Neón**: Colores brillantes, efectos de brillo, estética synthwave
2. **📼 Retro**: Estilo pixelado, colores de CRT, scanlines
3. **⬜ Minimalista**: Diseño limpio, colores neutros, enfocado en jugabilidad
4. **🌃 Cyberpunk**: Colores cian/magenta, lluvia digital, ambiente futurista
5. **🌈 Arcoíris**: Gradientes coloridos, ambiente alegre
6. **🎃 Temas Estacionales**: Halloween, Navidad, etc.

### Efectos Visuales:
- **Efectos de partículas** mejorados al completar líneas
- **Trails/Estelas** al mover piezas rápidamente
- **Fondos animados** temáticos y reactivos
- **Skins para bloques** personalizables
- **Animaciones de transición** entre pantallas
- **Shake de cámara** en eventos importantes

### Personalización del Pit:
- Materiales del pit (vidrio, metal, neón, madera)
- Iluminación configurable
- Efectos ambientales (lluvia, nieve, estrellas)

### Dificultad de Implementación: 🟢 Fácil-Media
### Archivos a Modificar:
- Modificar: `BlockOut/Sprites.cpp`, `BlockOut/Game.cpp`
- Agregar texturas en: `BlockOut/images/`

---

## 📊 Sistema de Progresión

Sistema de progresión a largo plazo que persiste entre partidas.

### Características:

#### **Niveles de Jugador** 🎖️
- Experiencia (XP) acumulativa
- Sistema de niveles (1-100)
- XP ganado por:
  - Líneas completadas
  - Puntaje obtenido
  - Logros desbloqueados
  - Tiempo jugado

#### **Sistema de Desbloqueo** 🔓
- Nuevos temas visuales
- Efectos de sonido especiales
- Música adicional
- Avatares para perfil online
- Títulos personalizados

#### **Misiones Semanales** 📋
- 3-5 misiones que cambian cada semana
- Recompensas especiales por completarlas
- Ejemplos:
  - "Completa 50 líneas en modo Zen"
  - "Alcanza nivel 5 sin usar el modo práctica"
  - "Obtén 10,000 puntos en una sola partida"

#### **Temporadas** 🎭
- Contenido limitado por tiempo (3 meses)
- Pase de temporada gratuito y premium
- Recompensas exclusivas
- Temas estacionales

### Dificultad de Implementación: 🟡 Media-Alta
### Archivos a Modificar:
- Crear: `BlockOut/Progression.h`, `BlockOut/Progression.cpp`
- Modificar: `BlockOut/SetupManager.cpp` (para guardar progreso)
- Base de datos local para persistencia

---

## 🎵 Mejoras de Audio

Expandir las capacidades de audio del juego.

### Funcionalidades Propuestas:

#### **Más Tracks Musicales** 🎼
- Diferentes tracks según:
  - Nivel actual
  - Tema visual seleccionado
  - Modo de juego
- Biblioteca de 10-15 tracks
- Música dinámica que se intensifica con la velocidad

#### **Efectos de Sonido Dinámicos** 🔊
- Sonidos que cambian según la velocidad del juego
- Feedback audio al completar líneas (diferentes según cantidad)
- Sonidos satisfactorios para logros
- Efectos espaciales 3D

#### **Visualizador de Música** 📊
- Fondo que reacciona al ritmo y frecuencias
- Efectos visuales sincronizados con la música
- Opcional: activar/desactivar

#### **Playlist Personalizable** 🎧
- Permitir al jugador seleccionar su música
- Soporte para archivos MP3/OGG propios
- Lista de reproducción aleatoria o secuencial

### Dificultad de Implementación: 🟢 Fácil-Media
### Archivos a Modificar:
- Modificar: `BlockOut/SoundManager.h`, `BlockOut/SoundManager.cpp`
- Agregar música en: `BlockOut/sounds/`

---

## 🤖 Mejoras al Bot/IA

El juego ya tiene `BotPlayer.cpp`. Expandir sus capacidades.

### Funcionalidades Propuestas:

#### **Niveles de Dificultad de IA** 🎚️
1. **Principiante**: Comete errores ocasionales, no optimiza
2. **Normal**: Juego decente, algunas suboptimizaciones
3. **Difícil**: Muy bueno, rara vez comete errores
4. **Experto**: Juego casi perfecto, maximiza puntaje
5. **Imposible**: IA perfecta con lookahead profundo

#### **Modo "Aprende de la IA"** 🎓
- Visualización en tiempo real del "pensamiento" del bot
- Mostrar por qué elige cierta posición
- Puntuación de cada posible movimiento
- Explicaciones textuales

#### **Competir Contra IA** ⚔️
- Modo versus contra el bot
- Seleccionar nivel de dificultad
- Mostrar ambos pits lado a lado

#### **Tutorial Interactivo Guiado por IA** 📚
- IA actúa como tutor
- Sugerencias contextuales
- Correcciones en tiempo real
- Progresión gradual de dificultad

### Dificultad de Implementación: 🟡 Media-Alta
### Archivos a Modificar:
- Modificar: `BlockOut/BotPlayer.h`, `BlockOut/BotPlayer.cpp`, `BlockOut/BotPlayerAI.cpp`
- Crear: `BlockOut/AITutor.cpp`

---

## 📱 Mejoras Social y Competitivo

El juego ya tiene sistema online de scores. Expandir capacidades sociales.

### Funcionalidades Propuestas:

#### **Tablas de Clasificación Mejoradas** 🏅
- Clasificación por categorías:
  - Por modo de juego
  - Por setup (pit dimension, block set)
  - Diaria, semanal, mensual, histórica
  - Por región/país
- Filtros y búsqueda

#### **Sistema de Amigos** 👥
- Agregar amigos por nombre de usuario
- Lista de amigos en el menú
- Comparar scores directamente
- Ver cuando están jugando
- Notificaciones cuando superas a un amigo

#### **Repeticiones Compartibles** 📹
- Exportar repeticiones (.bl2replay) fácilmente
- Compartir vía código/link
- Importar repeticiones de otros jugadores
- Galería de mejores repeticiones comunitarias
- Comentarios y "me gusta" en repeticiones

#### **Torneos Automáticos** 🏆
- Torneos semanales/mensuales automáticos
- Inscripción abierta
- Premios virtuales (títulos, badges)
- Bracket de eliminación o liga
- Historia de torneos participados

#### **Perfiles de Jugador** 👤
- Página de perfil pública
- Estadísticas completas
- Logros mostrados
- Historial de partidas
- Gráficos de progreso

### Dificultad de Implementación: 🟡 Media (requiere backend)
### Archivos a Modificar:
- Modificar: `BlockOut/Http.h`, `BlockOut/Http.cpp`
- Modificar páginas de menú: `BlockOut/PageHallOfFameOnLine.cpp`
- Requiere: Actualización del servidor/API web

---

## 🎓 Tutorial y Sistema de Aprendizaje

Mejorar la experiencia para nuevos jugadores.

### Funcionalidades Propuestas:

#### **Tutorial Interactivo Completo** 📖
- Secuencia paso a paso al primer inicio
- Enseña:
  - Controles básicos
  - Rotación en 3D
  - Estrategias básicas
  - Sistemas de puntaje
- Opcional: repetible desde el menú

#### **Consejos Contextuales** 💡
- Tips que aparecen según el nivel del jugador
- Adaptativo: detecta errores comunes y sugiere mejoras
- Desactivable para jugadores experimentados
- Base de datos de 50+ consejos

#### **Modo "Aprende Jugando"** 🎮
- Versión extendida del modo Practice
- Hints visuales:
  - Mejor posición resaltada
  - Predicción de huecos problemáticos
  - Avisos de peligro
- Niveles graduales de asistencia

#### **Desafíos de Entrenamiento** 🎯
- Situaciones específicas pre-diseñadas
- Enfocados en habilidades particulares:
  - Rotación avanzada
  - Planificación espacial
  - Recuperación de situaciones difíciles
  - Optimización de puntaje
- Sistema de estrellas (1-3 por desafío)

#### **Glosario y Manual** 📚
- Glosario de términos del juego
- Explicaciones de mecánicas avanzadas
- Estrategias documentadas
- Videos demostrativos (opcional)

### Dificultad de Implementación: 🟢 Media
### Archivos a Modificar:
- Crear: `BlockOut/Tutorial.cpp`, `BlockOut/Challenges.cpp`
- Modificar: `BlockOut/Menu.cpp`, `BlockOut/Game.cpp`

---

## 🔧 Mejoras Técnicas de Gameplay

Características que mejoran la experiencia de juego moderna.

### Funcionalidades Propuestas:

#### **Sistema de Combos** 🔥
- Puntos extra por acciones consecutivas:
  - Completar líneas en turnos consecutivos
  - Múltiples líneas a la vez
  - Colocaciones perfectas seguidas
- Multiplicador visual
- Bonus de puntaje exponencial

#### **Predictor de Piezas** 🔮
- Mostrar las próximas 3-5 piezas
- Preview visual al lado del pit
- Configurable (cantidad de piezas a mostrar)
- Ayuda a planificar estrategia

#### **Hold/Guardar Pieza** 💾
- Guardar una pieza para usar después
- Similar a Tetris moderno
- Tecla configurable
- Solo se puede usar una vez por pieza
- Preview visual de pieza guardada

#### **Hard Drop Mejorado** ⚡
- Preview semitransparente de dónde caerá
- Confirmación visual antes de soltar
- Animación rápida al caer
- Configuración de velocidad

#### **Sistema "Casi Perfecto"** ⭐
- Detecta cuando un movimiento es casi óptimo
- Avisos visuales sutiles
- Ayuda a mejorar sin ser intrusivo
- Estadística de % de movimientos óptimos

#### **Modo Fantasma Permanente** 👻
- Opción de mostrar siempre dónde caerá la pieza
- Configurable en opciones
- Transparencia ajustable
- Color diferenciado

#### **Sistema de Grab/Pausa Mejorado** ⏯️
- Pausar sin entrar a menú
- Overlay de pausa con estadísticas actuales
- Opción de guardar y salir
- Continuar exactamente donde quedaste

### Dificultad de Implementación: 🟢 Media
### Archivos a Modificar:
- Modificar: `BlockOut/Game.cpp`, `BlockOut/Game.h`
- Modificar: `BlockOut/PolyCube.cpp`

---

## 📋 Prioridades de Implementación

### 🟢 **Fácil - Buen punto de partida para CoderDojo**

1. **Predictor de próximas piezas** - Excelente práctica con UI/rendering
2. **Nuevos temas visuales** - Perfecto para aprender sobre gráficos
3. **Modo Contra Reloj** - Introducción a lógica de juego
4. **Tutorial mejorado** - Gran proyecto para principiantes
5. **Más música y sonidos** - Trabajo con assets de audio

### 🟡 **Dificultad Media - Proyectos intermedios**

1. **Sistema de logros** - Persistencia de datos, lógica de tracking
2. **Power-ups** - Lógica de juego compleja, efectos visuales
3. **Sistema de progresión** - Base de datos, diseño de sistemas
4. **Hold/Guardar pieza** - Modificación core de mecánicas
5. **Multijugador local** - Arquitectura multiusuario

### 🔴 **Difícil - Proyectos avanzados**

1. **Multijugador online** - Networking, sincronización, servidor
2. **Sistema de temporadas** - Backend complejo, gestión de contenido
3. **IA avanzada multinivel** - Algoritmos complejos, optimización
4. **Motor de física mejorado** - Matemáticas avanzadas, rendimiento
5. **Sistema de torneos automático** - Backend, matchmaking, gestión

---

## 🤝 Contribuir

Si eres parte de **CoderDojo** o **Code Club** y quieres implementar alguna de estas funcionalidades:

1. Lee la [guía de contribución](../CONTRIBUTING.md)
2. Elige una funcionalidad del roadmap
3. Crea un issue en GitHub describiendo tu intención
4. Haz un fork del repositorio
5. Implementa la funcionalidad
6. Crea un Pull Request

### Recursos de Aprendizaje:

- **OpenGL**: Para mejoras gráficas
- **SDL**: Para input y sonido
- **C++**: Lenguaje del proyecto
- **Algoritmos de juegos**: Para IA y lógica

---

## 📞 Contacto

¿Tienes más ideas? ¿Quieres discutir una implementación?

- 🌐 [Sitio Oficial](http://www.blockout.net/blockout2)
- 💬 [GitHub Issues](https://github.com/coderdojo-cordoba/blockout2025/issues)
- 📧 Información del autor en README principal

---

**Última actualización**: Noviembre 2025  
**Versión del documento**: 1.0
