/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:16:19 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/15 13:50:09 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				free_string_arr(void *arr);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *));
int					ft_isspace(int c);
int					ft_s_isspace(char *s);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
size_t				ft_strlen(const char *str);
void				ft_putstr(char *str, int fd);
size_t				ft_strlcpy(char *dst, const char *src, int dstsize);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_fprintf(int fd, const char *s, ...);
char				*ft_remove_chars(char *str, int (*char_comparator)(int));
char				*ft_uitoa(unsigned int n);
char				*ft_strdup(const char *str);
char				*ft_strchr(const char *s, char c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncat(char *s1, const char *s2, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

#endif
