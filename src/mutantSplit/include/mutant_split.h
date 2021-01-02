/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutant_split.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:03:32 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/29 15:03:33 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_SPLIT_H
# define MUTANT_SPLIT_H

# include <stdint.h>
# include <stdlib.h>

typedef struct		s_arr_strings
{
	char			**arr;
	size_t			len;
}					t_arr_strings;

char		**mutant_split(const char *s, char c);

/*
** Counting words.
*/

typedef struct		s_split_str
{
	char	*current;
	char	*after_protecting;
	char	separator;
	uint8_t	new_word_flag;
}					t_split_str;

void	init_str(t_split_str *str, char *s, char c);
size_t		count_strings(t_split_str str);
int			is_protect(char c);
int			is_end_or_sep(t_split_str *s);

char		*skip_protected(const char *s);

size_t			copy_strings(t_arr_strings *strings, t_split_str s);
char		*copy_and_skip_string(t_split_str *s);
size_t			count_string_len(t_split_str s);
void			skip_sep(t_split_str *s);
void			skip_string(t_split_str *s);
char	*copy_and_skip_backslash_protecting(char *dst, t_split_str *s);
char	*copy_and_skip_quotes_protecting(char *dst, t_split_str *s);

#endif

