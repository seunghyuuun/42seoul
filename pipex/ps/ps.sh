#!/bin/bash

number=0

while [ $number -le 30 ]
do
	ps -l
	sleep 1
	((number++))
done
