#!/bin/bash
#this compiles and uploads arduino ide sketches in place of the ide

BOARD="esp32:esp32:esp32"
PORT="/dev/ttyUSB0"

if [ $# > 1 ]
then
    if [ $1 = '1' ]
    then
        echo "Compiling sketch..."
        arduino-cli compile -b $BOARD
    elif [ $1 = '2' ]
    then
        echo "Compiling and uploading..."
        arduino-cli compile -b $BOARD
        arduino-cli upload -b $BOARD -p $PORT
    else
        echo "Invalid argument recieved"
    fi
else
    echo "No arguments given"
fi

