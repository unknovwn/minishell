/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:50:56 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/16 17:46:10 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "check_syntax_errors.h"
#include "utils.h"
#include "libft.h"
#include "skipping.h"

char		*check_syntax_errors(char *current)
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
