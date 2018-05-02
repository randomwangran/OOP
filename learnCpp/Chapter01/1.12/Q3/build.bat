@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64
@echo off    
set compilerflags=/Od /Zi /EHsc
@echo off
set linkerflags=/OUT:question3.exe
@echo off
cl.exe %compilerflags% question3.cpp io.cpp /link %linkerflags%
@echo off
call question3.exe