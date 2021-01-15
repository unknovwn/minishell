#!/bin/sh

make -C ../../superSplit/
make -C ../../../libft/

#gcc\
gcc -fsanitize=address\
	../../../libft/libft.a\
	../../superSplit/super_split.a\
	../../checkingSyntaxErrors/*.c\
	../commandTable/*.c\
	../files/*.c\
	main.c ../*.c -o executeOne &&\
	./executeOne "command 1 < file1 < file1.2 | command 2 < file2 | command 3 4 5"
