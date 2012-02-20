CPP=g++
CC=gcc
NASM=nasm
EXE=../../../lib/njsdl/macos/libnjsdl.jnilib
CPPFLAGS=-O3 -fno-strict-aliasing -Wall -Wno-format -arch i386 -arch x86_64 -D MACOS
CCFLAGS=$(CPPFLAGS)
NASMFLAGS=-f elf32 -Xgnu -dALIGN_BUG
LIBS = `sdl-config --cflags --libs` -lGL

LIBPATH += -L"/System/Library/Frameworks/OpenGL.framework/Libraries"

%.o: ../%.cpp
	@echo Compiling $< ...
	@$(CPP) $(CPPFLAGS) -c -o $@ $<

%.o: ../%.c
	@echo Compiling $< ...
	@$(CC) $(CCFLAGS) -c -o $@ $<

%.o: ../%.asm
	@echo Assembling $< ...
	@$(NASM) $(NASMFLAGS) -o $@ $<

objects = njsdl.o jni_gl.o ngl3.o

$(EXE): $(objects)
	@echo Linking $(EXE) ...
	@$(CC) -shared -o $(EXE) $(LIBS) $(objects) $(LIBPATH)
	@echo READY.

all: $(EXE)

clean:
	rm -f *.o
	rm -f $(EXE)