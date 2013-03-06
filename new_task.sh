#!/bin/sh
if [ -z $1 ]; then 
	echo "Input the task number.";
	exit 1;
fi

FOLDER=$1

if [ ${#FOLDER} -lt 2 ]; then
    FOLDER="0"$FOLDER;
fi;

if [ ${#FOLDER} -lt 3 ]; then
    FOLDER="0"$FOLDER;
fi;

if [ -e $FOLDER ]; then
    echo "Task folder '$FOLDER' already exists.";
    exit 1;
fi;

FILE=$FOLDER".cpp"

mkdir $FOLDER
cp template.cpp $FOLDER/$FILE
