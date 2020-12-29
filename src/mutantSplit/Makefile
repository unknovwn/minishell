NAME = split_commands

SOURCE_FILES =	main.c \
				mutant_split.c \
				utils.c \
				count_result_len.c
SRC = $(addprefix src/, $(SOURCE_FILES))

###################################  LIBS     ##################################

LIBFT_DIR = ../../libft/
LIBS = -L$(LIBFT_DIR) -lft

################################################################################

###################################  OBJ     ###################################

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SEGINFOFLAG = -fsanitize=address
INCLD = include/

.c.o:
	$(CC) $(CFLAGS) -I$(INCLD) -c $< -o $(<:.c=.o)

################################################################################

#############################  MANDATORY COMMANDS  #############################

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LIBS) $(OBJ) -o $(NAME)

all: $(NAME)

debug: $(OBJ)
	$(CC) $(CFLAGS) $(SEGINFOFLAG) $(LIBS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re:	fclean	all

################################################################################

###############################  BONUS COMMANDS  ##############################

norm:
	norminette **/*.c
	norminette **/*.h

################################################################################

.PHONY: all debug clean fclean re norm
