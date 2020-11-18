#!/bin/bash
gcc -o  "${1//.c}" $1 -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic
