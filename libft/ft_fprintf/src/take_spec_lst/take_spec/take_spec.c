/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:06:22 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/09 23:23:06 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Puts 'type'(d, i, s, p ...) to lst->spec.
*/

#include <stdlib.h>
#include "ft_fprintf.h"

char	*take_spec(char *s, t_spec_info *lst)
{
	while (*s != '\0' && is_flag(*s))
		s++;
	lst->spec = (*s);
	if (*s != '\0')
		return (++s);
	else
		return (s);
}
