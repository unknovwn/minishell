/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 02:31:35 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/17 02:31:35 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	count_strs(char **strs)
{
	size_t	len;

	len = 0;
	while (*strs != NULL)
	{
		len += 1;
		strs += 1;
	}
	return (len);
}
