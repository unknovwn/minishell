/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutant_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:28:05 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/02 05:26:13 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include "split_str.h"

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
	t_split_str		str;

	init_str(&str, (char*)s, c);
	strings.len = count_strings(str);
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
