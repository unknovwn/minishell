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

char			**mutant_split(const char *s, char c)
{
	char	**result;
	size_t	len;
	size_t	i;
	t_split_str	str;

	init_str(&str, (char*)s, c);
	len = count_elements(str);
	printf("------MyLen = %zu\n", len);

	result = (char**)malloc(sizeof(char*) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = NULL;
	i = 0;
	while (i < len)
	{
		//result[i] = copy_command(s, c);
		//s = skip_command;
		i += 1;
	}




	free(result);
	//free_string_arr(result);
	return (NULL);
}

