/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:26:36 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/10 19:46:24 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			main(void)
{
	t_command_tab	*command_table;
	int				pid;
	int				status;

	if ((signal(SIGINT, SIG_IGN)) == SIG_ERR)
		ft_putstr("\nCannot catch SIGINT\n", STDERR);
	if ((signal(SIGQUIT, SIG_IGN)) == SIG_ERR)
		ft_putstr("\nCannot catch SIGQUIT\n", STDERR);
	while (1)
	{
		if ((pid = fork()) == -1)
		{
			ft_fprintf(STDERR, "%s: %s\n", SHELL_NAME, strerror(errno));
			exit(1);
		}
		if (pid == 0)
		{
			if (!(command_table = read_command()))
			{
				if (errno)
					ft_putstr(strerror(errno), STDERR);
				exit(1);
			}
			execute_command(command_table);
			free_command_table(command_table);
			exit(0);
		}
		if ((waitpid(pid, &status, 0)) == -1)
			ft_putstr(strerror(errno), STDERR);
		else {
			if (WEXITSTATUS(status) == MINISHELL_EXIT)
				break ;
		}
	}
	return (0);
}
