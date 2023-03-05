@echo off
gcc brainfuck.c -o brainfuck.exe -Wall -O2 -static
objcopy --strip-unneeded brainfuck.exe
strip brainfuck.exe