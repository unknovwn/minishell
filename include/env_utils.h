#ifndef ENV_UTILS_H
# define ENV_UTILS_H

# include "libft.h"

typedef struct	s_env_variable {
	char	*name;
	char	*value;
	int		shell_only;
}				t_env_variable;

void			delete_env_var(void *env_var);
void			remove_var_from_env(char *name);
void			clear_env(void);
char			*get_var_value(char *name);
t_env_variable	*create_env_var(char *name, char *value, int shell_only);
int				add_env_var(char *name, char *value, int shell_only);
t_list			*init_env(void);
char			*insert_env_variables(char *command);
int				is_valid_name(char *name);
int				set_new_value(char *name, char *value, int shell_only);

extern t_list	*g_env;

#endif
