NAME = minishell

SOURCE_FILES = minishell.c
SRC = $(addprefix src/, $SOURCE_FILES)

###################################  LIBS     ##################################

LIBS = -Llibft/ -lft

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
	$(CC) $(CFLAGS) $(LIBS) $(OBJ) -o $(NAME)

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
	norminette **/*.c
	norminette **/*.h

################################################################################
