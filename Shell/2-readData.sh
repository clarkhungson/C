# Read data from keyboard

#!/bin/bash
echo -e  "Please input data: \c"
read word
echo $word

echo `clear`

echo -e "Can you please input 2 another words: \c"
read word1 word2
echo -e "Those are: $word1 $word2"
echo -e "Or"
echo -e "Those are: \"$word1\"\"$word2\""