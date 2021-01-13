#!/bin/sh

make -C ../../superSplit/
make -C ../../../libft/
gcc -fsanitize=address\
	../../../libft/libft.a\
	../../superSplit/super_split.a\
	../../checkingSyntaxErrors/*.c\
	../commandTable/*.c\
	main.c ../*.c -o executeOne &&\
	./executeOne "command 1 | command 2 | command 3"
