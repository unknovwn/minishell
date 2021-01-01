/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_and_skip_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 00:59:51 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/02 00:59:52 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include <stdbool.h>
#include "mutant_split.h"

static char	*copy_and_skip_symbol(char *dst, t_split_str *s)
{
	*dst = *s->current;
	dst += 1;
	s->current += 1;
	s->after_protecting = skip_protected(s->current);
	return (dst);
}

static char	*copy_and_skip_protected(char *dst, t_split_str *s)
{
	if (*s->current == '\\')
		dst = copy_and_skip_backslash_protecting(dst, s);
	else
		dst = copy_and_skip_quotes_protecting(dst, s);
	return (dst);
}

static void	copy_string(char *dst, t_split_str s)
{
	char	*dst_begin;

	dst_begin = dst;
	while (is_end_or_sep(&s) == false)
	{
		if (is_protect(*s.current))
			dst = copy_and_skip_protected(dst, &s);
		else
			dst = copy_and_skip_symbol(dst, &s);
	}
	*dst = '\0';
	printf("~~~~~STRING~~~~~\n");

	printf("|%s|\n", dst_begin);

	printf("~~~~~~~~~~~~~~~~\n");
}

static char	*copy_and_skip_string(t_split_str *s)
{
	char	*string;
	size_t	string_len;

	string_len = count_string_len(*s);
	string = (char*)malloc(sizeof(char) * (string_len + 1));
	if (string == NULL)
		return (NULL);
	string[string_len] = '\0';
	copy_string(string, *s);


	skip_string(s);
	printf("string  len = %zu\n", string_len);
	return (string);

}

size_t		copy_strings(t_arr_strings *strings, t_split_str s)
{
	size_t	i;

	i = 0;
	while (i < strings->len)
	{
		skip_sep(&s);
		strings->arr[i] = copy_and_skip_string(&s);
		free(strings->arr[i]);
		if (strings->arr[i] == NULL)
			break ;
		i += 1;
	}
	return (i);
}
