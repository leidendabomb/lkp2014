#!/bin/bash

exec diff -Naur <(./$1 < samples/$1.in) samples/$1.out
