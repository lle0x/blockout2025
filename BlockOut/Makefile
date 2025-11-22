#---------------------------------------------------------------------
# Makefile for BlockOut
#
# Ubuntu (tested on 22.04 / 24.04) build packages:
#
#  build-essential
#  libglu1-mesa-dev
#  libgl1-mesa-dev
#  libxext-dev
#  libsdl1.2-dev
#  libsdl-mixer1.2-dev
#  libasound2-dev
#
#---------------------------------------------------------------------
# All source files needed for the application
#

SRC = 	BlockOut.cpp         PageChooseSetup.cpp       PageStartGame.cpp \
	EditControl.cpp      PageControls.cpp          Pit.cpp \
	Game.cpp             PageCredits.cpp           PolyCube.cpp \
	Http.cpp             PageHallOfFame.cpp        SetupManager.cpp \
	InitPolyCube.cpp     PageHallOfFameOnLine.cpp  SoundManager.cpp \
	Menu.cpp             PageHttp.cpp              Sprites.cpp \
	MenuGraphics.cpp     PageMainMenu.cpp          Utils.cpp \
	MenuGrid.cpp         PageOptions.cpp           PageChangeSetup.cpp  \
	PageScoreDetails.cpp PageGSOptions.cpp         BotPlayer.cpp \
	BotPlayerAI.cpp      BotMatrix.cpp \
	GLApp/GLApp.cpp  GLApp/GLFont.cpp  GLApp/GLMatrix.cpp  GLApp/GLSprite.cpp

OBJ=    BlockOut.o         PageChooseSetup.o       PageStartGame.o \
	EditControl.o      PageControls.o          Pit.o \
	Game.o             PageCredits.o           PolyCube.o \
	Http.o             PageHallOfFame.o        SetupManager.o \
	InitPolyCube.o     PageHallOfFameOnLine.o  SoundManager.o \
	Menu.o             PageHttp.o              Sprites.o \
	MenuGraphics.o     PageMainMenu.o          Utils.o \
	MenuGrid.o         PageOptions.o           PageChangeSetup.o  \
	PageScoreDetails.o PageGSOptions.o         BotPlayer.o \
	BotPlayerAI.o      BotMatrix.o \
	GLApp/GLApp.o  GLApp/GLFont.o  GLApp/GLMatrix.o  GLApp/GLSprite.o

#---------------------------------------------------------------------

ADD_LIBS = ../ImageLib/src/libimagelib.a

CXX		= g++

ifdef _macos
CXXFLAGS = -O2 -DMACOS -DGL_SILENCE_DEPRECATION -c -I../ImageLib/src -I. $(shell sdl-config --cflags)
LFLAGS = $(ADD_LIBS) $(shell sdl-config --libs) -lSDL_mixer -framework OpenGL -framework GLUT -lm
else

ifdef _linux64
SDL_LIBS = /usr/lib/x86_64-linux-gnu
else
SDL_LIBS = /usr/lib/i386-linux-gnu
endif

ifdef _release

CXXFLAGS =     -O2 -Dlinux -c \
               -I/usr/include/SDL -I../ImageLib/src -I.

LFLAGS   =      -Wl,--strip-all \
		$(ADD_LIBS) \
		-lSDL_mixer -lSDL -lasound \
		-lGL -lGLU -lpthread -lm -ldl

else

CXXFLAGS =     -g -D_DEBUG -Dlinux -c \
               -I/usr/include/SDL -I../ImageLib/src -I.

LFLAGS   =      -L $(SDL_LIBS) \
		$(ADD_LIBS) \
		-lSDL_mixer -lSDL -lasound \
		-lGL -lGLU -lpthread -lm -ldl

endif
endif


#--------------------------------------------------------------------

all: blockout

blockout: $(OBJ)
	@echo Linking...
	@rm -f blockout
	$(CXX) $(OBJ) $(LFLAGS) -o blockout
	@echo Linking OK...

clean:
	@echo Cleaning...
	@rm -f *.o
	@rm -f GLApp/*.o
