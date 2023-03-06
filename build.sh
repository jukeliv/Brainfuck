#!/bin/sh
gcc brainfuck_linux.c -o brainfuck.out -Wall -Os -static
strip brainfuck.out