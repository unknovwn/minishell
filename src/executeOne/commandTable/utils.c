/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:39:17 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/14 13:39:18 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	is_redirect_from(char *s)
{
	return (*s == '<');
}

int	is_redirect_to(char *s)
{
	return (*s == '>');
}

int	is_redirect_double_to(char *s)
{
	if (ft_strcmp(s, ">>") == 0)
		return (2);
	else
		return (0);
}
