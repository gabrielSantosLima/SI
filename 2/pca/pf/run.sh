#!/bin/bash
echo "==== RUN YOUR CODE===="

compile(){
  fileName=$1
  echo ">> Compiling..."
  gcc $fileName -o output.out
  echo ">> Running $fileName..."
  echo ">> Output:"
  ./output.out
}

if [ "$1" == "" ] 
then
  echo 'File was not specified. Try run ".\run.sh <YOUR_FILE_NAME>.c" '
else
  compile $1
fi

echo "Done."