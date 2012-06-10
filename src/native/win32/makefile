exe=..\..\..\lib\com\github\rjeschke\njsdl\win32\njsdl.dll
cc=cl.exe
link=link.exe
cppflags=/O2 /GL /D "WIN32" /D "_WIN32" /D "HB32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_WINDLL" /FD /EHsc /MT /W3 /nologo /c /Zi /TP /errorReport:prompt /I"..\\"
cflags=/O2 /GL /D "WIN32" /D "HB32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_WINDLL" /FD /EHsc /MT /W3 /nologo /c /Zi /TC /errorReport:prompt /I"..\\"
linkflags=/MANIFEST /INCREMENTAL:NO /NOLOGO /DLL /SUBSYSTEM:WINDOWS /OPT:REF /OPT:ICF /LTCG /MACHINE:X86 /ERRORREPORT:PROMPT
libs=.\SDL.lib opengl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib

objs=njsdl.obj jni_gl.obj ngl3.obj

{..\}.cpp.obj:
	@echo Compiling $< ...
	$(cc) $(cppflags) $<

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

