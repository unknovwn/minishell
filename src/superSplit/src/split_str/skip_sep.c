/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_sep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 02:52:35 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/02 02:52:36 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "split_str.h"

static int	is_sep_and_is_not_end(t_split_str *s)
{
	return (s->delim_comparator(*s->current) == true && *s->current != '\0');
}

void		skip_sep(t_split_str *s)
{
	while (is_sep_and_is_not_end(s))
	{
		s->current += 1;
	}
	s->after_protecting = skip_protected(s->current);
}
