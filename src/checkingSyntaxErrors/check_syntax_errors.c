/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:50:56 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/11 19:36:22 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "check_syntax_errors.h"
#include "skipping.h"
#include "semicolon_and_pipe.h"
#include "../../include/libft.h"

static char *skip_quotes(char *current, char c)
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
		if (current == '\0')
			break ;
		if (*current == '\'')
			current = skip_quotes(current, '\'');
		else if (*current == '\"')
			current = skip_quotes(current, '\"');
		if (*current == '\0')
			return (ERROR_UNCLOSED_QUOTES);
		else
			current += 1;
		if (*current == '\\')
			current = skip_bslash(current);
	}
	return (NULL);
}

char	*check_error_near_with_redirect_to(char *current);
char	*check_error_near_with_redirect_from(char *current);

static char	*check_near_unexpected_token(char *current)
{
	char	*status;
	uint8_t	redirect_to_flag;
	uint8_t	redirect_from_flag;

	//printf("INPUT!%s!\n", current);
	status = NULL;
	redirect_to_flag = 0;
	redirect_from_flag = 0;
	current = skip_space(current);
	if (*current == ';')
		return (ERROR_NEAR_SEMICOLON);
	else if (*current == '|')
		return (ERROR_NEAR_PIPE);
	while (*current != '\0' && status == NULL)
	{
		//printf("before |%c|\n", *current);
		if (is_protect(*current))
			current = skip_protected(current);
		//printf("after |%c|\n", *current);
		//current = skip_space(current);
		//printf("after skip |%c|\n", *current);
		if (*current == ';')
			status = check_error_near(current + 1);
		else if (*current == '|')
			status = check_error_near_with_pipe(current + 1);
		else if (*current == '>')
			status = check_error_near_with_redirect_to(current + 1);
		else if (*current == '<')
			status = check_error_near_with_redirect_from(current + 1);
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
