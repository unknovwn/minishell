NAME = minishell
SRCDIR = src/

SRC =	$(SRCDIR)main.c

###################################  LIBS     ##################################

#LIBFTDIR =	$(SRCDIR)libft/
#LIBFT =		$(LIBFTDIR)libft.a

################################################################################

###################################  OBJ     ###################################

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SEGINFOFLAG = -fsanitize=address
INCLD = includes/

.c.o:
	$(CC) $(CFLAGS) -I$(INCLD) -c $< -o $(<:.c=.o)

################################################################################

#############################  MANDATORY COMMANDS  #############################

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(LIBS) $(OBJ) -o $(NAME)

all:		$(NAME)

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
