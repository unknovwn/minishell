/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_strings_with_protect.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:18:17 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/18 15:18:18 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_str.h"

size_t		copy_strings_with_protect(t_arr_strings *strings, t_split_str s)
{
	size_t	i;

	i = 0;
	while (i < strings->len)
	{
		skip_sep(&s);
		strings->arr[i] = copy_and_skip_string_with_protect(&s);
		if (strings->arr[i] == NULL)
			break ;
		i += 1;
	}
	return (i);
}
