#!/bin/bash

# 引数の値を変数に代入する
NAME="sample"
FROM=0
UPTO=30
ASPECT_RATIO=1.5
SHRINK_RATIO=0.6
FILESIZE_HEIGHT=100
START_X=-1.21990088
START_Y=0.335100082
DEFAULT_WIDTH=0.2
DEFAULT_HEIGHT=0.15
LENGTH=1800

# make clean && make コマンドを実行する
make clean && make

# make run コマンドを実行する
make run ARGS="-name $NAME -from $FROM -upto $UPTO -aspect-ratio $ASPECT_RATIO -shrink-ratio $SHRINK_RATIO -filesize-height $FILESIZE_HEIGHT -start-x $START_X -start-y $START_Y -default-width $DEFAULT_WIDTH -default-height $DEFAULT_HEIGHT -length $LENGTH"
