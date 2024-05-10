#!/bin/bash

fileName=$1

compile(){  
  gcc $fileName -o output.out
  ./output.out
  rm output.out
}

if [ "$fileName" == "" ] 
then
  echo 'File was not specified. Try run ".\run.sh <YOUR_FILE_NAME>.c" '
else
  compile
fi