NAME = libft.a

SRC = free_string_arr.c \
	  ft_lstadd_back.c \
	  ft_lstclear.c \
	  ft_lstdelone.c \
	  ft_lstlast.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_split.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLD = ../include/

.c.o:
	$(CC) $(CFLAGS) -I$(INCLD) -c $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
