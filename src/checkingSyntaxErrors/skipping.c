/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skipping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:35:14 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/11 18:35:15 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*skip_space(char *current)
{
	while (ft_isspace(*current) && *current != '\0')
		current += 1;
	return (current);
}

char	*skip_bslash(char *current)
{
	if (*(current + 1) != '\0')
		return (current + 2);
	else
		return (current + 1);
}

char	*skip_symbols(char *current, char c)
{
	while (*current != '\0' && *current != c)
	{
		if (*current == '\\')
			current = skip_bslash(current);
		else
			current += 1;
	}
	if (*current == c)
		return (current + 1);
	else
		return (current);
}

int		is_protect(char c)
{
	return (c == '\'' || c == '\"' || c == '\\');
}

char	*skip_protected(char *current)
{
	if (*current == '\\')
		current = skip_bslash(current);
	else if (*current == '\'')
		current = skip_symbols(current + 1, '\'');
	else if (*current == '\"')
		current = skip_symbols(current + 1, '\"');
	if (is_protect(*current))
		current = skip_protected(current);
	return (current);
}
