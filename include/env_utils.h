/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:59:21 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/14 20:52:36 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

# include "libft.h"

typedef struct	s_env_variable {
	char	*name;
	char	*value;
}				t_env_variable;

void			delete_env_var(void *env_var);
void			clear_env(void);
char			*get_var_value(char *name);
t_env_variable	*create_env_var(char *name, char *value);
int				add_env_var(char *name, char *value);
void			parse_env_var(char *var);
t_list			*init_env(void);
char			*insert_env_variables(char *command);

extern t_list	*g_env;

#endif
