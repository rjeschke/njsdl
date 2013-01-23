CPP=g++
CC=gcc
EXE=../../../lib/njsdl/linux64/libnjsdl.so
CPPFLAGS=-O3 -fno-strict-aliasing -Wall -Wno-format -D LINUX -fPIC
CCFLAGS=$(CPPFLAGS)
LIBS = -lSDL -lGL

%.o: ../%.cpp
	@echo Compiling $< ...
	@$(CPP) $(CPPFLAGS) -c -o $@ $<

%.o: ../%.c
	@echo Compiling $< ...
	@$(CC) $(CCFLAGS) -c -o $@ $<

objects = njsdl.o jni_gl.o ngl3.o

$(EXE): $(objects)
	@echo Linking $(EXE) ...
	@$(CC) -shared -o $(EXE) $(LIBS) $(objects)
	@echo READY.

all: $(EXE)

clean:
	rm -f *.o
	rm -f $(EXE)