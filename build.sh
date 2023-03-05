#!/bin/sh
gcc brainfuck.c -o brainfuck.out -Wall -Os -static
strip brainfuck.out