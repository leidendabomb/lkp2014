#!/bin/bash

./$1 < testdata/$1.in > test.txt

exec diff -Naur test.txt testdata/$1.out
