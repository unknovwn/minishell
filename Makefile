NAME = minishell

SOURCE_FILES = minishell.c \
			   read_command.c \
			   execute_command.c \
			   env_utils.c \
			   env_utils2.c \
			   insert_env_variables.c \
			   insert_env_variables_utils.c \
			   print_error.c \
			   checkingSyntaxErrors/check_syntax_errors.c \
			   checkingSyntaxErrors/skipping.c \
			   checkingSyntaxErrors/utils.c \
			   builtins/cd.c \
			   builtins/exit.c \
			   builtins/pwd.c \
			   builtins/env.c \
			   builtins/export.c \
			   builtins/unset.c
SRC = $(addprefix src/, $(SOURCE_FILES))

###################################  LIBS     ##################################

LIBFT_DIR = libft/
SUPER_SPLIT_DIR = src/superSplit/
LIBS = $(LIBFT_DIR)libft.a $(SUPER_SPLIT_DIR)super_split.a

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
	make -C $(SUPER_SPLIT_DIR)
	$(CC) $(CFLAGS) $(LIBS) $(OBJ) -o $(NAME)

all: $(NAME)

debug: $(OBJ)
	make -C $(LIBFT_DIR)
	make -C $(SUPER_SPLIT_DIR)
	$(CC) $(CFLAGS) $(SEGINFOFLAG) $(LIBS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(SUPER_SPLIT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(SUPER_SPLIT_DIR)

re:	fclean	all

################################################################################

###############################  BONUS COMMANDS  ##############################

SHELL = /bin/zsh
norm:
	norminette -R CheckForbiddenSourceHeader **/*.c
	norminette -R CheckForbiddenSourceHeader **/*.h

################################################################################

.PHONY: all debug clean fclean re norm
