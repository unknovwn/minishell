/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_and_exit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:44:59 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/13 20:01:46 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error_and_exit(char *error_string)
{
	ft_fprintf(STDERR, "%s: %s\n", SHELL_NAME, error_string);
	exit(1);
}
