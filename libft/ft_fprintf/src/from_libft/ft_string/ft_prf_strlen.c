/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prf_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 10:24:16 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/09 23:23:06 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Function works like strlen (man strlen),
*/

#include "ft_fprintf.h"

size_t		ft_prf_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
