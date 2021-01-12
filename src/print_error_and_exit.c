/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_and_exit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:44:59 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/12 16:53:58 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

<<<<<<< HEAD:src/print_error_and_exit.c
#include "minishell.h"

void	print_error_and_exit(void)
{
	ft_fprintf(STDERR, "%s: %s\n", SHELL_NAME, strerror(errno));
	exit(1);
}
=======
#ifndef UTILS_H
# define UTILS_H

int		is_semicolon(char c);
int		is_pipe(char c);
int		is_redirect(char c);

char	*check_error_near(char *current);
char	*check_error_near_with_redirect_to(char *current);

#endif
>>>>>>> checking-syntax-errors:src/checkingSyntaxErrors/utils.h
