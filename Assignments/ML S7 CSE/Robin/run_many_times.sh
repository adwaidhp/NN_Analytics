#!/bin/bash

a=0

# lt is less than operator

#Iterate the loop until a less than 10

while [ $a -lt 100 ]
do

# Print the values
echo "Run $a:"
./a.out
echo ""

# increment the value
a=`expr $a + 1`
done
