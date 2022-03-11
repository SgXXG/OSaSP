#!/bin/bash

if [ $# -lt "3" -o $# -gt "3" ]; then
	{
	echo "Not enough parameters found" 
	echo "1-st parameter - name of the owner" 
	echo "2-nd parameter - the directory to search" 
	echo "3-rd parameter - name of the file to output" 
	} >&2
else
	find $2 -user $1  >$3.txt
fi