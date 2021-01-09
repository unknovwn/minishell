/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:26:36 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/09 18:05:03 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		handle_inter(int sig)
{
	if (sig == 2)
		ft_putstr("\n", STDOUT);
}

int	main(void)
{
	t_command	**command_table;
	/* char		*command_result; */
	int			pid;
	int			status;

	signal(SIGINT, handle_inter);
	while (1)
	{
		if ((pid = fork()) == -1)
			continue ;
		if (pid == 0)
		{
			if (!(command_table = read_command()))
			{
				if (errno)
					ft_putstr(strerror(errno), STDERR);
				exit(1);
			}
			if ((ft_strcmp(((*command_table)->argv)[0], "exit")) == 0)
			{
				ft_putstr("exit\n", STDOUT);
				free_command_table(command_table);
				exit(MINISHELL_EXIT);
			}
			if (((*command_table)->argv)[0])
				printf("command: \"%s\"\n", ((*command_table)->argv)[0]);
			exit(0);
			/* command_result = execute(command_table); */
			/* print(command_result); */
		}
		if ((waitpid(pid, &status, 0)) == -1)
			ft_putstr(strerror(errno), STDERR);
		if (WEXITSTATUS(status) == MINISHELL_EXIT)
			break ;
	}
	return (0);
}
