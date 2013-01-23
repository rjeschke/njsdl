CPP=g++
CC=gcc
NASM=nasm
EXE=../../../lib/njsdl/linux32/libnjsdl.so
CPPFLAGS=-O3 -fno-strict-aliasing -Wall -Wno-format -march=i686 -mfpmath=387 -D LINUX -D HB32
CCFLAGS=$(CPPFLAGS)
NASMFLAGS=-f elf32 -Xgnu -dALIGN_BUG
LIBS = -lSDL -lGL

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
	@$(CC) -shared -o $(EXE) $(LIBS) $(objects)
	@echo READY.

all: $(EXE)

clean:
	rm -f *.o
	rm -f $(EXE)