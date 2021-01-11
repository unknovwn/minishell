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

#include <stdio.h>
#include <stdlib.h>

#include "skipping.h" 
#include "check_syntax_errors.h" 

char	*check_error_near(char *current)
{
	current = skip_space(current);
	if (*current == ';')
		return (ERROR_NEAR_SEMICOLON);
	else if (*current == '|')
		return (ERROR_NEAR_PIPE);
	return (NULL);
}

char	*check_error_near_with_pipe(char *current)
{
	if (is_protect(*current))
		current = skip_protected(current);
	//printf("%c <-\n", *current);
	if (*current == ';')
			return (ERROR_NEAR_SEMICOLON);
	return (check_error_near(current + 1));
}
