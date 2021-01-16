/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_skip_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 02:14:58 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/17 02:14:59 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_str.h"
#include "libft.h"

void		split_skip_space(t_split_str *s)
{
	while (ft_s_isspace(s->current))
		s->current += 1;
	s->after_protecting = skip_protected(s->current);
}
