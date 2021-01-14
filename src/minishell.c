/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:26:36 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/14 18:53:46 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		*g_env;

void		clear_env(void)
{
	ft_lstclear(&g_env, delete_env_var);
}

void		parse_env_var(char *var)
{
	char	*equals_sign;
	char	*name;
	char	*value;

	if (!(equals_sign = ft_strchr(var, '=')))
	{
		clear_env();
		print_error_and_exit("error: invalid program environment");
	}
	*equals_sign = '\0';
	name = var;
	value = (equals_sign + 1);
	if ((add_env_var(name, value)) == -1)
	{
		clear_env();
		print_error_and_exit(strerror(errno));
	}
}

t_list		*init_env(void)
{
	t_env_variable	*last_return_value;
	t_list			*env;

	if (!(last_return_value = create_env_var("?", "0")))
		print_error_and_exit(strerror(errno));
	if (!(env = ft_lstnew(last_return_value)))
	{
		delete_env_var(last_return_value);
		print_error_and_exit(strerror(errno));
	}
	return (env);
}

int			main(int argc, char **argv, char **envp)
{
	int				pid;
	int				status;
	char			*command;

	(void)argc;
	(void)argv;
	if ((signal(SIGINT, SIG_IGN)) == SIG_ERR)
		ft_fprintf(STDERR, "\n%s: Error: Cannot catch SIGINT\n", SHELL_NAME);
	if ((signal(SIGQUIT, SIG_IGN)) == SIG_ERR)
		ft_fprintf(STDERR, "\n%s: Error: Cannot catch SIGQUIT\n", SHELL_NAME);
	g_env = init_env();
	while (*envp)
		parse_env_var(*envp++);
	while (1)
	{
		if ((pid = fork()) == -1)
		{
			clear_env();
			print_error_and_exit(strerror(errno));
		}
		if (pid == 0)
		{
			if (!(command = read_command()))
				print_error_and_exit(strerror(errno));
			execute_command(command);
			exit(0);
		}
		if ((waitpid(pid, &status, 0)) == -1)
		{
			clear_env();
			print_error_and_exit(strerror(errno));
		}
		if (WEXITSTATUS(status) == MINISHELL_EXIT)
			break ;
	}
	clear_env();
	return (0);
}
