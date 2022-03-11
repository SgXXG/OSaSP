#!/bin/bash

if [ $# -lt "2" -o $# -gt "2" ]; then
	echo "Not enough parameters found"
	echo "1-st parameter - file"
	echo "2-nd parameter - name of exe"
else
	sudo gcc $1.c -o $2.exe &&
	./$2.exe
fi