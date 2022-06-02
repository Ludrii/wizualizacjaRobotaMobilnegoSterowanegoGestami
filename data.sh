#!/bin/bash

sum=0

while true
do
	czuj1=$RANDOM
	czuj2=$RANDOM
	czuj3=$RANDOM
	czuj4=$RANDOM
	
	let "czuj1 %= 9"
	let "czuj2 %= 9"
	let "czuj3 %= 9"
	let "czuj4 %= 9"
	let "sum=$czuj1+2*$czuj2+3*$czuj3+4*$czuj4"
	text="X $czuj1 $czuj2 $czuj3 $czuj4 $sum FC"
	echo $text | tee $1
    sleep 1
done
