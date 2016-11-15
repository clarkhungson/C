#while do

#!/bin/bash
COUNT=0
while [ $COUNT -lt 10 ];do
	echo $COUNT
	sleep 1
	let COUNT=COUNT+1
done