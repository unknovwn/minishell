/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_split_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 03:18:28 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/02 03:18:29 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutant_split.h"
#include "split_str.h"

void	init_str(t_split_str *str, char *s, char c)
{
	str->current = s;
	str->after_protecting = skip_protected(str->current);
	str->separator = c;
	str->new_word_flag = 1;
}
