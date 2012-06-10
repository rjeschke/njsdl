exe=..\..\..\lib\com\github\rjeschke\njsdl\win64\njsdl.dll
cc=cl.exe
link=link.exe
cflags=/O2 /GL /D "WIN64" /D "HB64" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_WINDLL" /FD /EHsc /MD /W3 /nologo /c /Zi /TC /errorReport:prompt /I"..\\"
linkflags=/MANIFEST /INCREMENTAL:NO /NOLOGO /DLL /SUBSYSTEM:WINDOWS /OPT:REF /OPT:ICF /LTCG /MACHINE:X64 /ERRORREPORT:PROMPT
libs=.\SDL.lib opengl32.lib

objs=njsdl.obj jni_gl.obj ngl3.obj

{..\}.c.obj:
	@echo Compiling $< ...
	$(cc) $(cflags) $<

$(exe): $(objs)
	@echo Linking $(exe) ...
	@$(link) $(linkflags) /out:$(exe) $** $(libs)
	@echo READY.


all: $(exe)

clean:
	@del *.obj
	@del *.dll

