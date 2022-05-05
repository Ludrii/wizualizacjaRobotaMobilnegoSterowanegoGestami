#!/bin/bash

echo "Do którego pts pisać?"
read PTS
while true
do
    echo -n `shuf -i 0-8 -n 4 | tee "/dev/pts/$PTS"`
    sleep 1
done