#Ashley Nguyen - apn2my
#PostLab07 - averagetime.sh
#3/22/16

#!/bin/bash
size=5
result=0

echo "Enter the exponent for counter.cpp: "
read input

if [[ $input == "quit" ]] ; then
    exit 0
    fi

for ((i=1; i<=size; i++))
do
    echo "Running iteration ${i}..."
    time=`./a.out ${input}`
    echo "time taken:" ${time} ms
    result=`expr $result + $time`
done

echo ${size} "iterations took" ${result} "ms"
avg=`expr $result / $size`
echo "Average time was" ${avg} "ms"
