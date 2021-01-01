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
#include "libft.h"

static void		init_str(t_split_str *str, char *s, char c)
{
	str->current = s;
	str->after_protecting = skip_protected(str->current);
	str->separator = c;
	str->new_word_flag = 1;

}

/*
** From count_elements.c
 */

int			is_new_word(t_split_str *s);
int			is_end_or_sep(t_split_str *s);
int			is_protect(char c);

/////////////////////////

static size_t	count_and_skip_protected(t_split_str *s)
{
	size_t	len;

	len = s->after_protecting - s->current;
	if (*s->current == '\'' || *s->current == '\"')
		len -= 2;
	else if (*s->current == '\\')
		len -= 1;
	s->current = s->after_protecting;
	s->after_protecting = skip_protected(s->current);
	return (len);
}

static size_t	count_and_skip_symbol(t_split_str *s)
{
	s->current += 1;
	s->after_protecting = skip_protected(s->current);
	return (1);
}

size_t			count_word_len(t_split_str s)
{
	size_t	len;

	len = 0;
	while (is_end_or_sep(&s) == false)
	{
		if (is_protect(*s.current))
			len += count_and_skip_protected(&s);
		else if (is_end_or_sep(&s) == false)
			len += count_and_skip_symbol(&s);
	}
	return (len);
}

void				skip_sep(t_split_str *s)
{
	while (*s->current == s->separator && *s->current != '\0')
	{
		s->current += 1;
	}
	s->after_protecting = skip_protected(s->current);
}

static void		skip_word(t_split_str *s)
{
	while (is_end_or_sep(s) == false)
	{
		if (s->current != s->after_protecting)
		{
			s->current = s->after_protecting;
		}
		else if (is_end_or_sep(s) == false)
		{
			s->current += 1;
		}
		s->after_protecting = skip_protected(s->current);
	}
	if (*s->current != '\0')
		s->current += 1;
	s->after_protecting = skip_protected(s->current);
}

void			copy_and_skip_word(char *dst, t_split_str *s)
{
	size_t	word_len;

	//printf("*s->current: |%c|\n", *s->current);
	word_len = count_word_len(*s);
	skip_word(s);
	printf("word    len = %zu\n", word_len);

}

char			**mutant_split(const char *s, char c)
{
	t_arr_strings	strings;
	char	**result;
	size_t	len;
	size_t	i;
	t_split_str	str;

	init_str(&str, (char*)s, c);
	strings.len = count_elements(str);
	printf("------MyLen = %zu\n", strings.len);

	strings.arr = (char**)malloc(sizeof(char*) * (strings.len + 1));
	if (strings.arr == NULL)
		return (NULL);
	strings.arr[strings.len] = NULL;


	i = 0;
	while (i < strings.len)
	{
		skip_sep(&str);
		copy_and_skip_word(strings.arr[i], &str);
		i += 1;
	}




	//free_string_arr(result);
	return (strings.arr);
}

