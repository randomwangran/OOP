@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64
@echo off    
set compilerflags=/Od /Zi /EHsc
@echo off
set linkerflags=/OUT:question2.exe
@echo off
cl.exe %compilerflags% question2.cpp /link %linkerflags%
@echo off
call question2.exe