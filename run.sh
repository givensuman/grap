#!/bin/bash

gcc *.h *.c -o grep
./grep $1 $2
