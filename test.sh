#!/bin/bash

exec diff -Naur <(./$1 < testdata/$1.in) testdata/$1.out
