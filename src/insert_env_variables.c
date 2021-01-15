/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_env_variables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:52:08 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/15 14:09:14 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "insert_env_variables_utils.h"

char	*insert_env_variables(char *command)
{
	char	*result;
	size_t	result_len;
	int		i;

	result_len = count_result_len(command);
	if (!(result = (char*)malloc(sizeof(char) * (result_len + 1))))
		return (0);
	result[0] = '\0';
	i = 0;
	while (command[i])
	{
		if ((i = iterate_loop(result, command, i)) == -1)
		{
			free(result);
			return (0);
		}
	}
	return (result);
}
