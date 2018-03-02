@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64
@echo off    
set compilerflags=/Od /Zi /EHsc
@echo off
set linkerflags=/OUT:question1.exe
@echo off
cl.exe %compilerflags% question1.cpp /link %linkerflags%
@echo off
call question1.exe