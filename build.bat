@echo off
gcc brainfuck.c -o brainfuck.exe -Wall -Os -static
strip brainfuck.exe