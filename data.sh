#!/bin/bash

while true
do
    echo `shuf -i 0-8 -n 4 | tee $1`
    sleep 1
done
