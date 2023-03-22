#!/bin/bash

# 引数の値を変数に代入する
NAME="sample"
FROM=0
UPTO=1600
ASPECT_RATIO=1.5
SHRINK_RATIO=0.99
FILESIZE_HEIGHT=2500
START_X=-1.21765
START_Y=0.3453625
DEFAULT_WIDTH=0.2
DEFAULT_HEIGHT=0.15
LENGTH=1800

# make clean && make コマンドを実行する
make clean && make

rm -rf ./work/$NAME

# make run コマンドを実行する
make run ARGS="-name $NAME -from $FROM -upto $UPTO -aspect-ratio $ASPECT_RATIO -shrink-ratio $SHRINK_RATIO -filesize-height $FILESIZE_HEIGHT -start-x $START_X -start-y $START_Y -default-width $DEFAULT_WIDTH -default-height $DEFAULT_HEIGHT -length $LENGTH"

ffmpeg -r 30 -i ./work/$NAME/%08d.png -vcodec libx264 -pix_fmt yuv420p -r 60 ./dist/video.mp4
