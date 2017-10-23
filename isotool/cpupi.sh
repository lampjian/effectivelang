#!/bin/bash

for i in 0 1 2 3
do
        #time echo "scale=3000; 4*a(1)" | bc -lq &> /dev/null &
        time echo "scale=3000; 4*a(1)" | bc -lq &> ~/"pi"$i &
done

