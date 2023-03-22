#!/bin/bash

make clean && make
rm -rf ./work/sample
./bin/program -name sample -from 0 -upto 30 -aspect-ratio 1.5 -shrink-ratio 0.6 -filesize-height 100 -start-x -1.21990088 -start-y 0.335100082 -default-width 0.2 -default-height 0.15 -length 1800
