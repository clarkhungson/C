#!/bin/bash

PS3='Choose one word:'
select word in "linux" "bash" "scripting" "tutorial"
do
	echo "The word you have select is: $word"
	break
done
exit 0