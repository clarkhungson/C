#Read signal

#!/bin/bash
trap bashtrap INT
clear
bashtrap()
{
	echo "CTRL + C detected..."
}

for a in `seq 1 10`; do
	echo "$a/10 to exit.."
	sleep 1
done;