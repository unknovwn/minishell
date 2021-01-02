NAME = mutant_split.a

SOURCE_FILES =	mutant_split.c \
				$(STRUCT_SPLIT_STR)
SRC = $(addprefix src/, $(SOURCE_FILES))

#############################  STRUCT SPLIT STR ################################

STRUCT_SPLIT_STR_FILES =	init_split_str.c \
							skip_sep.c \
							skip_string.c \
							count_string_len.c \
							count_strings.c \
							copy_and_skip_string.c \
							copy_strings_utils.c \
							copy_strings.c
STRUCT_SPLIT_STR = $(addprefix split_str/, $(STRUCT_SPLIT_STR_FILES)) \

################################################################################

###################################  LIBS     ##################################

LIBFT_DIR = ../../libft/
LIBS = -L$(LIBFT_DIR) -lft

################################################################################

###################################  OBJ     ###################################

OBJ = $(SRC:.c=.o)

CC = gcc
MAKELIB = ar rc
CFLAGS = -Wall -Wextra -Werror
SEGINFOFLAG = -fsanitize=address
INCLD = include/

.c.o:
	$(CC) $(CFLAGS) -I$(INCLD) -c $< -o $(<:.c=.o)

################################################################################

#############################  MANDATORY COMMANDS  #############################

$(NAME): $(OBJ)
	$(MAKELIB) $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

debug: $(OBJ)
	$(CC) $(CFLAGS) $(SEGINFOFLAG) $(LIBS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean	all

################################################################################

###############################  BONUS COMMANDS  ##############################

norm:
	norminette src/**/*.c
	norminette **/*.h

################################################################################

.PHONY: all debug clean fclean re norm
