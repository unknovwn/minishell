#ifndef INSERT_ENV_VARIABLES_UTILS_H
# define INSERT_ENV_VARIABLES_UTILS_H

# include <libft.h>

int		is_in_single_quotes(char *str, int index);
int		is_env_var(char *command, int index);
char	*get_var_name(char *str);
int		count_result_len(char *command);
int		iterate_loop(char *result, char *command, int i);

#endif
