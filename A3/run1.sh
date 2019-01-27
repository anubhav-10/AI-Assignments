#!/bin/bash
a='.graph'
b='.satinput'
./main $1$a
cat file1.txt file2.txt > $1$b
