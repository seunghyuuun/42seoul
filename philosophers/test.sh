#!/bin/bash

number=1

while [ $number -le 177 ]
do
	cat a.txt | grep eating | awk '{ print $2}' | grep ${number} | wc -l
    ((number++))
done
