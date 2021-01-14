/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:50:56 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/13 16:18:57 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "check_syntax_errors.h"
#include "utils.h"
#include "libft.h"
#include "skipping.h"

static char	*skip_quotes(char *current, char c)
{
	while (*current != '\0' && *current != c)
	{
		if (*current == '\\')
			current = skip_bslash(current);
		else
			current += 1;
	}
	return (current);
}

static char	*check_multiline_quotes(char *current)
{
	if (*current == '\\')
		current = skip_bslash(current);
	while (*current != '\0')
	{
		if (*current == '\'')
			current = skip_quotes(current + 1, '\'');
		else if (*current == '\"')
			current = skip_quotes(current + 1, '\"');
		if (*current == '\0')
			return (ERROR_UNCLOSED_QUOTES);
		else
			current += 1;
		if (*current == '\\')
			current = skip_bslash(current);
	}
	return (NULL);
}

static char	*check_near_unexpected_token(char *current)
{
	char	*status;

	status = NULL;
	current = skip_space(current);
	if (is_semicolon(current))
		return (ERROR_NEAR_SEMICOLON);
	else if (is_pipe(current))
		return (ERROR_NEAR_PIPE);
	while (*current != '\0' && status == NULL)
	{
		if (cse_is_protect(*current))
			current = cse_skip_protected(current);
		if (is_semicolon(current))
			status = check_error_near(current + 1);
		else if (is_pipe(current))
			status = check_error_near(current + 1);
		else if (is_redirect(current))
			status = check_error_near_with_redirect_to(current + 1);
		current += 1;
	}
	return (status);
}

char		*check_syntax_errors(char *command)
{
	char	*status;

	status = check_multiline_quotes(command);
	if (status != NULL)
		return (status);
	status = check_near_unexpected_token(command);
	return (status);
}
