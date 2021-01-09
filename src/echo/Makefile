NAME = echo

SOURCE_FILES =	echo.c \

SRC = $(addprefix src/, $(SOURCE_FILES))

#############################  STRUCT SPLIT STR ################################


################################################################################

###################################  LIBS     ##################################

LIBFT_DIR = ../../libft/
LIBS = $(LIBFT_DIR)libft.a

################################################################################

###################################  OBJ     ###################################

OBJ = $(SRC:.c=.o)

CC = gcc
MAKELIB = ar rc
CFLAGS = -Wall -Wextra -Werror
SEGINFOFLAG = -fsanitize=address
INCLD = include/

.c.o:
	$(CC) -I$(INCLD) -c $< -o $(<:.c=.o)

################################################################################

#############################  MANDATORY COMMANDS  #############################

$(NAME): $(OBJ)
	$(CC) -I$(INCLD) $(OBJ) $(LIBS) -o $(NAME)

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
