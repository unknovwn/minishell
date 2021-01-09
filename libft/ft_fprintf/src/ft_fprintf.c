/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:35:56 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/09 23:19:10 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Function works like fprintf (man fprintf).
**	Realise types: %c, %s, %p, %d, %i, %u, %x, %X.
**	Realise flags: 0 - * .
*/

#include <unistd.h>
#include <stdio.h>
#include "ft_fprintf.h"

int					ft_fprintf(int fd, const char *s, ...)
{
	t_result_str	res_s;
	t_spec_info		*spec_lst;
	va_list			arg_p;

	va_start(arg_p, s);
	spec_lst = take_spec_lst(s, arg_p);
	va_end(arg_p);
	if ((take_res_s(s, &res_s, spec_lst)) == -1)
	{
		spec_lst_clear(&spec_lst);
		return (-1);
	}
	write(fd, res_s.str, res_s.str_len);
	spec_lst_clear(&spec_lst);
	free(res_s.str);
	return (res_s.str_len);
}
