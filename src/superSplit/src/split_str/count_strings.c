/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:24:19 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/16 21:34:58 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_str.h"

size_t		count_strings(t_split_str s)
{
	size_t		word_count;

	word_count = 0;
	while (*s.current != '\0')
	{
		if (!(is_sep(&s)))
		{
			word_count += 1;
			skip_string(&s);
		}
		else
			skip_sep(&s);
	}
	return (word_count);
}
