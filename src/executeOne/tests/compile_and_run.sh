#!/bin/sh

make -C ../../superSplit/
make -C ../../../libft/

#gcc -fsanitize=address\
gcc\
	../../../libft/libft.a\
	../../superSplit/super_split.a\
	../../checkingSyntaxErrors/*.c\
	../commandTable/*.c\
	../files/*.c\
	main.c ../*.c -o executeOne &&\
	./executeOne "command 1 < file | command 2 < file | command 3 4 5"
