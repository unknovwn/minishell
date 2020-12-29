/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutant_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:28:05 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/29 14:28:06 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include <stdbool.h>
#include "split_commands.h"
#include "libft.h"

char	**split_commands(const char *s, char c)
{
	char	**result;
	size_t	len;
	size_t	i;

	len = count_commands(s, c);
	printf("len = |%zu|\n", len);

	result = (char**)malloc(sizeof(char*) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = NULL;
	i = 0;
	while (i < len)
	{
		//result[i] = copy_command(s, c);
		//s = skip_command;
		i += 1;
	}




	free(result);
	//free_string_arr(result);
	return (NULL);
}

