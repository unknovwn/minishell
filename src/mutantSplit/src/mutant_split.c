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
#include "mutant_split.h"

static void		free_strings(t_arr_strings *strings)
{
	char	**begin;

	if (strings == NULL)
		return ;
	begin = strings->arr;
	while (strings->arr != NULL)
	{
		free(*strings->arr);
		strings->arr += 1;
	}
	free(begin);
}

char			**mutant_split(const char *s, char c)
{
	t_arr_strings	strings;
	t_split_str	str;

	init_str(&str, (char*)s, c);
	strings.len = count_strings(str);
	printf("------MyLen = %zu\n", strings.len);
	strings.arr = (char**)malloc(sizeof(char*) * (strings.len + 1));
	if (strings.arr == NULL)
	{
		write(2, "ERROR: cannot allocate memory\n", 30);
		return (NULL);
	}
	strings.arr[strings.len] = NULL;
	if (strings.len != copy_strings(&strings, str))
	{
		write(2, "ERROR: cannot allocate memory\n", 30);
		free_strings(&strings);
	}
	return (strings.arr);
}

