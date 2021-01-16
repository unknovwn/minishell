/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 04:48:02 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/02 05:28:14 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_STR_H
# define SPLIT_STR_H
# include <stdlib.h>
# include <stdint.h>

typedef struct		s_arr_strings
{
	char			**arr;
	size_t			len;
}					t_arr_strings;

typedef struct		s_split_str
{
	char			*current;
	char			*after_protecting;
	int				(*delim_comparator)(char*);
}					t_split_str;

/*
** ==========================================================================
**               Functions wich works with s_split_str only.
** ==========================================================================
*/

void				init_str(t_split_str *str,
							char *s,
							int (*delim_comparator)(char*));

int					is_end_or_sep(t_split_str *s);

int					is_sep(t_split_str *s);
void				skip_sep(t_split_str *s);
char				*skip_protected(const char *s);
void				skip_string(t_split_str *s);

size_t				count_string_len(t_split_str s);
size_t				count_strings(t_split_str str);

char				*copy_and_skip_bslash_protecting(char *dst, t_split_str *s);
char				*copy_and_skip_quotes_protecting(char *dst, t_split_str *s);
char				*copy_and_skip_string(t_split_str *s);
size_t				copy_strings(t_arr_strings *strings, t_split_str s);


/*
** New in HEADER
*/

void	split_str_skip_space(t_split_str *s);

/*
** ==========================================================================
** ==========================================================================
*/

/*
** ==========================================================================
**                                Utils.
** ==========================================================================
*/

int					is_protect(char c);

/*
** ==========================================================================
** ==========================================================================
*/

#endif
