#!/bin/bash

sum=0

while true
do
	czuj1=$RANDOM
	czuj2=$RANDOM
	czuj3=$RANDOM
	czuj4=$RANDOM
	v=$RANDOM
	batt=$RANDOM
	
	let "czuj1 %= 9"
	let "czuj2 %= 9"
	let "czuj3 %= 9"
	let "czuj4 %= 9"
	let "v %= 20"
	let "batt %= 100"
	let "sum=$czuj1+2*$czuj2+3*$czuj3+4*$czuj4+5*$v+6*$batt"
	text="X $czuj1 $czuj2 $czuj3 $czuj4 $v $batt $sum FC"
	echo $text | tee $1
    sleep 1
done
