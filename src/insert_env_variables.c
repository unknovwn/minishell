/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_env_variables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:52:08 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/14 15:50:36 by mgeneviv         ###   ########.fr       */
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
	while ((index - j >= 0) && (command[index - j] == '\\'))
	{
		backslash_counter++;
		j++;
	}
	return ((backslash_counter % 2 == 0) && !(ft_isspace(command[index + 1])));
}

char	*get_var_name(char *str)
{
	char	*name;
	size_t	name_len;
	int		i;

	i = 0;
	name_len = ft_isdigit(str[0]);
	if (!name_len)
	{
		name_len = 0;
		while (ft_isalpha(str[i]) || ft_isdigit(str[i]) || str[i] == '_')
		{
			i++;
			name_len++;
		}
	}
	if (!(name = (char *)malloc(sizeof(char) * (name_len + 1))))
		return (0);
	i = 0;
	while (name_len--)
	{
		name[i] = str[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

size_t	count_result_len(char *command)
{
	size_t	result_len;
	char	*var_name;
	char	*var_value;
	int		i;

	result_len = 0;
	i = 0;
	while (command[i])
	{
		if (is_env_var(command, i))
		{
			if (!(var_name = get_var_name(&(command[++i]))))
				print_error_and_exit(strerror(errno));
			i += ft_strlen(var_name);
			if ((var_value = get_var_value(var_name)))
				result_len += ft_strlen(var_value);
			free(var_name);
		}
		else
		{
			result_len++;
			i++;
		}
	}
	return (result_len);
}

char	*insert_env_variables(char *command)
{
	char	*result;
	char	*var_name;
	char	*var_value;
	size_t	result_len;
	int		i;

	result_len = count_result_len(command);
	if (!(result = (char*)malloc(sizeof(char) * result_len)))
		return (0);
	result[0] = '\0';
	i = 0;
	while (command[i])
	{
		if (is_env_var(command, i))
		{
			if (!(var_name = get_var_name(&(command[++i]))))
			{
				free(result);
				return (0);
			}
			i += ft_strlen(var_name);
			if ((var_value = get_var_value(var_name)))
				ft_strncat(result, var_value, ft_strlen(var_value));
			free(var_name);
		}
		else
			ft_strncat(result, &(command[i++]), 1);
	}
	return (result);
}
