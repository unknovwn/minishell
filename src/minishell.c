/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:26:36 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/13 16:53:51 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		*g_env;

t_list		*init_env(void)
{
	t_env_variable	*last_return_value;
	t_list			*env;

	if (!(last_return_value = create_env_var("?", "0")))
		print_error_and_exit();
	if (!(env = ft_lstnew(last_return_value)))
	{
		delete_env_var(last_return_value);
		print_error_and_exit();
	}
	return (env);
}

int			main(void)
{
	t_command_tab	*command_table;
	int				pid;
	int				status;

	if ((signal(SIGINT, SIG_IGN)) == SIG_ERR)
		ft_putstr("\nCannot catch SIGINT\n", STDERR);
	if ((signal(SIGQUIT, SIG_IGN)) == SIG_ERR)
		ft_putstr("\nCannot catch SIGQUIT\n", STDERR);
	g_env = init_env();
	while (1)
	{
		if ((pid = fork()) == -1)
			print_error_and_exit();
		if (pid == 0)
		{
			if (!(command_table = read_command()))
			{
				if (errno)
					print_error_and_exit();
				exit(1);
			}
			execute_command(command_table);
			free_command_table(command_table);
			exit(0);
		}
		if ((waitpid(pid, &status, 0)) == -1)
			ft_fprintf(STDERR, "%s: %s\n", SHELL_NAME, strerror(errno));
		else
		{
			if (WEXITSTATUS(status) == MINISHELL_EXIT)
				break ;
		}
	}
	clear_env();
	return (0);
}
