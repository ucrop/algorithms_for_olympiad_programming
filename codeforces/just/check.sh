#!/bin/bash

c++ --std=c++17 qwe.cpp -o qwe
for i in in*
do
    j=$(echo $i | tail -c +3 | head -c 1)
    out="out$j.out" 
    ./qwe < $i > "res$j.out" 2>> "_output.txt"
    if [[ -z "$(diff -b res$j.out $out)" ]]
    then
        echo "Test $j: ok"
    else
        echo "Test $j: wa"
        echo "Correct answer:"
        cat $out
        echo "Your answer:"
        cat "res$j.out"
    fi 
done
