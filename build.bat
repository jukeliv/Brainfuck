@echo off
clang brainfuck.c -o brainfuck.exe -Wall -Os -static
llvm-strip brainfuck.exe