#!/bin/bash
for ((i=1; i < 150; i++))
do
od -A n -t d -N 1 /dev/urandom
done