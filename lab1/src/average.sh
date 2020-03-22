#!/bin/bash
index=1
sum=0
count=0

for arg in "$@"
do 
  echo "Аргумент #$index = $arg" 
  let "count+=1"
  let "sum=sum+arg"
done
let "sum=sum/count"
echo "$count"
echo "$sum"
exit 0