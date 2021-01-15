/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_and_exit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:44:59 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/14 20:39:57 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_macro.h"
#include "libft.h"

void	print_error_and_exit(char *error_string)
{
	ft_fprintf(STDERR, "%s: %s\n", SHELL_NAME, error_string);
	exit(1);
}
