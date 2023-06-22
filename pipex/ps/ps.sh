#!/bin/bash

number=0

while [ $number -le 10 ]
do
	ps -l
	sleep 1
	((number++))
done
