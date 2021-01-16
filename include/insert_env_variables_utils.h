/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_env_variables_utils.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:05:10 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/16 16:23:48 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSERT_ENV_VARIABLES_UTILS_H
# define INSERT_ENV_VARIABLES_UTILS_H

# include <libft.h>

int		is_in_single_quotes(char *str, int index);
int		is_env_var(char *command, int index);
char	*get_var_name(char *str);
int		count_result_len(char *command);
int		iterate_loop(char *result, char *command, int i);

#endif
