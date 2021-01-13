/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semicolon_and_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:51:22 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/11 18:51:22 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "check_syntax_errors.h"
#include "skipping.h"

int		is_semicolon(char c)
{
	return (c == ';');
}

int		is_pipe(char c)
{
	return (c == '|');
}

int		is_redirect(char c)
{
	return (c == '>' || c == '<');
}

char	*check_error_near(char *current)
{
	current = skip_space(current);
	if (*current == ';')
		return (ERROR_NEAR_SEMICOLON);
	else if (*current == '|')
		return (ERROR_NEAR_PIPE);
	return (NULL);
}

char	*check_error_near_with_redirect_to(char *current)
{
	if (*(current - 1) == '>' && *(current) == '>')
		current += 1;
	current = skip_space(current);
	if (*current == '>' && *(current + 1) == '>')
		return (ERROR_NEAR_TWO_REDIRECT_TO);
	else if (*current == '>')
		return (ERROR_NEAR_REDIRECT_TO);
	else if (*current == '<')
		return (ERROR_NEAR_REDIRECT_FROM);
	else if (*current == '\n' || *current == '\0')
		return (ERROR_NEAR_NEWLINE);
	else
		return (check_error_near(current));
}
