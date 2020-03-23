#!/bin/bash
sum=0
count=0

for arg in $(cat numbers.txt);
do 
  let "count+=1"
  let "sum=sum+arg"
done 
let "sum=sum/count"
echo "$count"
echo "$sum"
exit 0