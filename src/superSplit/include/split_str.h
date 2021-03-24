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
void				split_skip_space(t_split_str *s);

size_t				count_string_len(t_split_str s);
size_t				count_string_len_with_protect(t_split_str s);
size_t				count_strings(t_split_str str);

char				*copy_and_skip_bslash_protecting(char *dst, t_split_str *s);
char				*copy_with_and_skip_bslash_protecting(char *dst,
															t_split_str *s);

char				*copy_and_skip_quotes_protecting(char *dst, t_split_str *s);
char				*copy_with_and_skip_quotes_protecting(char *dst,
															t_split_str *s);

char				*copy_and_skip_string(t_split_str *s);
char				*copy_and_skip_string_with_protect(t_split_str *s);

size_t				copy_strings(t_arr_strings *strings, t_split_str s);
size_t				copy_strings_with_protect(t_arr_strings *strings,
												t_split_str s);

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
char				*sup_skip_bslash(char *s);

/*
** ==========================================================================
** ==========================================================================
*/

#endif
