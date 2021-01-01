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

/*
** ==========================================================================
**                            Counting word len.
** ==========================================================================
*/

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

size_t			count_string_len(t_split_str s)
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

/*
** ==========================================================================
** ==========================================================================
*/

/*
** ==========================================================================
**                            Copying strings.
** ==========================================================================
*/
/*
static void		skip_string(t_split_str *s)
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

char			*copy_and_skip_symbol(char *dst, t_split_str *s)
{
	*dst = *s->current;
	dst += 1;
	s->current += 1;
	s->after_protecting = skip_protected(s->current);
	return (dst);
}

char			*copy_and_skip_protected(char *dst, t_split_str *s)
{
	if (*s->current == '\\')
	{
		s->current += 1;
		if (*s->current != '\0')
		{
			*dst = *s->current;
			dst += 1;
			s->current += 1;
		}
	}
	else
	{
		s->current += 1;
		while (s->current != s->after_protecting - 1)
		{
			*dst = *s->current;
			dst += 1;
			s->current += 1;
		}
		if (is_end_or_sep(s) == false)
			s->current += 1;
	}
	s->after_protecting = skip_protected(s->current);
	return (dst);
}

static void		copy_string(char *dst, t_split_str s)
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

char			*copy_and_skip_string(t_split_str *s)
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

void			skip_sep(t_split_str *s)
{
	while (*s->current == s->separator && *s->current != '\0')
	{
		s->current += 1;
	}
	s->after_protecting = skip_protected(s->current);
}

static size_t	copy_strings(t_arr_strings *strings, t_split_str s)
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
*/

/*
** ==========================================================================
** ==========================================================================
*/
static void		init_str(t_split_str *str, char *s, char c)
{
	str->current = s;
	str->after_protecting = skip_protected(str->current);
	str->separator = c;
	str->new_word_flag = 1;

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

	copy_strings(&strings, str);






	//free_string_arr(result);
	return (strings.arr);
}

