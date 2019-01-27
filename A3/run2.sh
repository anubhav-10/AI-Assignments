#!/bin/bash
a='.satoutput'
b='.graph'
c='.subgraphs'
head -1 $1$b > file3.txt
cat file3.txt $1$a > final.txt
./decode < final.txt > $1$c
