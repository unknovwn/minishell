NAME = libft.a

SRC = free_string_arr.c \
	  ft_lstadd_back.c \
	  ft_lstclear.c \
	  ft_lstdelone.c \
	  ft_lstlast.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_isspace.c \
	  ft_strlen.c \
	  ft_putstr.c \
	  ft_strlcpy.c \
	  ft_strcmp.c \
	  ft_remove_chars.c \
	  ft_uitoa.c \
	  ft_strdup.c \
	  ft_strchr.c \
	  ft_isdigit.c \
	  ft_isalpha.c \
	  ft_s_isspace.c \
	  ft_strncat.c \
	  ft_strcpy.c \
	  ft_memcmp.c \
	  ft_atoi.c \
	  ft_lstsize.c \
	  ft_sort_string_arr.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLD = ../include/

.c.o:
	$(CC) $(CFLAGS) -I$(INCLD) -c $<

$(NAME): $(OBJ)
	make -C ft_fprintf/
	cp ft_fprintf/libftfprintf.a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	make clean -C ft_fprintf/
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ft_fprintf/
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
