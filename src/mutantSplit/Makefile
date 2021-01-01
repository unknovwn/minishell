NAME = mutant_split

SOURCE_FILES =	main.c \
				mutant_split.c \
				$(COUNTING_STRINGS) \
				$(COPYING_STRINGS)
SRC = $(addprefix src/, $(SOURCE_FILES))

#############################  COPYING STRINGS #################################

COUNTING_STRINGS_FILES =	count_strings.c \
						count_strings_utils.c
COUNTING_STRINGS = $(addprefix counting_strings/, $(COUNTING_STRINGS_FILES))

################################################################################

#############################  COPYING STRINGS #################################

COPYING_STRINGS_FILES =	copy_strings.c \
						copy_strings_utils.c
COPYING_STRINGS = $(addprefix copying_strings/, $(COPYING_STRINGS_FILES))

################################################################################

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
	$(CC) -I$(INCLD) -c $< -o $(<:.c=.o)

################################################################################

#############################  MANDATORY COMMANDS  #############################

$(NAME): $(OBJ)
	#make -C $(LIBFT_DIR)
	$(CC) $(LIBS) $(OBJ) -o $(NAME)

all: $(NAME)

debug: $(OBJ)
	$(CC) $(CFLAGS) $(SEGINFOFLAG) $(LIBS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)
	#make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	#make fclean -C $(LIBFT_DIR)

re:	fclean	all

################################################################################

###############################  BONUS COMMANDS  ##############################

norm:
	norminette **/*.c
	norminette **/*.h

################################################################################

.PHONY: all debug clean fclean re norm
