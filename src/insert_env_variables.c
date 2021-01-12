/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_env_variables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:52:08 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/12 21:58:25 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_in_single_quotes(char *str, int index)
{
	size_t	backslash_counter;
	int		i;
	int		is_inside;

	backslash_counter = 0;
	i = 0;
	is_inside = 0;
	while (i < index)
	{
		while (str[i] == '\\')
		{
			backslash_counter++;
			i++;
		}
		if ((backslash_counter % 2 == 0) && (str[i] == '\''))
			is_inside = !is_inside;
		backslash_counter = 0;
		i++;
	}
	return (is_inside);
}

int		is_env_var(char *command, int index)
{
	size_t	backslash_counter;
	int		j;

	if (command[index] != '$')
		return (0);
	if (is_in_single_quotes(command, index))
		return (0);
	backslash_counter = 0;
	j = 1;
	while ((index - j > 0) && (command[index - j] == '\\'))
	{
		backslash_counter++;
		j++;
	}
	return ((backslash_counter % 2 == 0) && !(ft_isspace(command[index + 1])));
}
size_t	count_vars(char *command)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (command[i])
	{
		if (is_env_var(command, i))
			count++;
		i++;
	}
	return (count);
}

char	*insert_env_variables(char *command)
{
	char	*result;
	size_t	number_of_vars;
	int		i;

	if ((number_of_vars = count_vars(command)) == 0)
		return (ft_strdup(command));
	i = 0;
	while (command[i])
	{
		if (is_env_var(command, i))
		{
		}
		i++;
	}
	return (result);
}
