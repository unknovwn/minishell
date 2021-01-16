#!/bin/sh

make -C ../../superSplit/
make -C ../../../libft/

#gcc -fsanitize=address\
gcc\
	../../../libft/libft.a\
	../../superSplit/super_split.a\
	../../checkingSyntaxErrors/*.c\
	../commandTable/*.c\
	main.c ../*.c -o executeOne &&\
#	./executeOne "   < file"
#	./executeOne "command  < file"
#	./executeOne "command  < file >> dto_file"
#	./executeOne "command 1 > to_file1 | command < to_file1"&&\
	./executeOne "command 1 > to_file1 > to_file1.2 >> dto_file1 >> dto_file1.2 | command 2 3 < dto_file1 > to_file2 >> d_to_file2 7 8 9 | command 3 4 5"
