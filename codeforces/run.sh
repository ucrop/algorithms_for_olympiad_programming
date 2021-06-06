#!/bin/bash

c++ --std=c++17 qwe.cpp -o qwe 
./qwe < "_input.txt" > "_output.txt" 2>> "_output.txt"
