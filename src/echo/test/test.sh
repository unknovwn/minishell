#!/bin/sh

./echo.sh > correct.out

./my_echo.sh > user.out

diff correct.out user.out

rm correct.out user.out
