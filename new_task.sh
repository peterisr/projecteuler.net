
#!/bin/sh
if [ -z $1 ]; then 
	echo "Input the task number.";
	exit 1;
fi

TASKNUM=$1

if [ ${#TASKNUM} -lt 2 ]; then
    TASKNUM="0"$TASKNUM;
fi;

if [ ${#TASKNUM} -lt 3 ]; then
    TASKNUM="0"$TASKNUM;
fi;

FOLDER=$TASKNUM
FILE=$FOLDER".cpp"

if [ -e $FOLDER ]; then
    echo "Task folder '$FOLDER' already exists.";
    exit 1;
fi;

REPLACE="TASKNUMBER"
TEMPLATE=$(cat template.cpp)
TEMPLATE=${TEMPLATE//$REPLACE/$TASKNUM}

mkdir $FOLDER
echo "$TEMPLATE" > $FOLDER/$FILE
