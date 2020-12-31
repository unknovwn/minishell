#!/bin/sh

make

./mutant_split > user_output.txt

diff user_output.txt correct_output.txt
