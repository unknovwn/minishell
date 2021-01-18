/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:28:05 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/16 21:36:46 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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

/*
** Split that supports quotes escape charactes (" ", ' ' and backslash).
*/

char			**super_split(const char *s, int (*delim_comparator)(char*), 
												int with_protect)
{
	t_arr_strings	strings;
	t_split_str		str;

	init_str(&str, (char*)s, delim_comparator);
	strings.len = count_strings(str);
	strings.arr = (char**)malloc(sizeof(char*) * (strings.len + 1));
	if (strings.arr == NULL)
	{
		write(2, "ERROR: cannot allocate memory\n", 30);
		return (NULL);
	}
	strings.arr[strings.len] = NULL;
	if (with_protect > 0)
	{
		if (strings.len != copy_strings(&strings, str))
			free_strings(&strings);
	}
	else
	{
		if (strings.len != copy_strings_with_protect(&strings, str))
			free_strings(&strings);
	}
	return (strings.arr);
}
