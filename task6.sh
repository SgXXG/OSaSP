#!/bin/bash

if [ $# -lt "3" -o $# -gt "3" ]; then
	echo "Not enough parameters found"
	echo "1-st parameter - name of the text file"
	echo "2-nd parameter - the directory to search"
	echo "3-rd parameter - the extension of the files for search"
else
	find $2 . -name "*.$3">$1.txt
fi