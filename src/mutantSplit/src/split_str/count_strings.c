/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_result_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:24:19 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/29 15:24:23 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include <stdbool.h>
#include "mutant_split.h"
#include "split_str.h"

size_t		count_strings(t_split_str s)
{
	size_t		word_count;

	word_count = 0;
	while (*s.current != '\0')
	{
		if (*s.current != s.separator)
		{
			word_count += 1;
			skip_string(&s);
		}
		else
			skip_sep(&s);
	}
	return (word_count);
}

