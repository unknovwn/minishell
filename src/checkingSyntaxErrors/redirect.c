/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:02:15 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/11 19:02:20 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "check_syntax_errors.h"
#include "semicolon_and_pipe.h"
#include "skipping.h"
#include "../../include/libft.h"

char	*check_error_near_with_redirect_to(char *current)
{
	//printf("!%s <-", current);
	if (*(current) == '>')
	{
		current += 1;
		current = skip_space(current);
		if (*current == '>' && *(current + 1) == '>')
			return (ERROR_NEAR_TWO_REDIRECT_TO);
		else if (*current == '>')
			return (ERROR_NEAR_REDIRECT_TO);
		else
			return (check_error_near(current));
	}
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

char	*check_error_near_with_redirect_from(char *current)
{
	current = skip_space(current);
	if (*current == '>')
		return (ERROR_NEAR_REDIRECT_TO);
	else if (*current == '<')
		return (ERROR_NEAR_REDIRECT_FROM);
	else if (*current == '\n' || *current == '\0')
		return (ERROR_NEAR_NEWLINE);
	else
		return (check_error_near(current));
}
