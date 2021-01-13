/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:26:36 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/13 20:17:07 by mgeneviv         ###   ########.fr       */
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
	name = var;
	value = (equals_sign + 1);
	if ((add_env_var(name, value)) == -1)
	{
		clear_env();
		print_error_and_exit(strerror(errno));
	}
}

t_list		*init_env(char **envp)
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
	while (*envp)
		parse_env_var(*envp++);
	return (env);
}

void		print_env(void)
{
	t_list *env;
	char *name;
	char *value;

	env = g_env;
	while (env)
	{
		name = ((t_env_variable*)(env->content))->name;
		value = ((t_env_variable*)(env->content))->value;
		ft_fprintf(STDOUT, "%s=%s\n", name, value);
		env = env->next;
	}
}

int			main(int argc, char **argv, char **envp)
{
	t_command_tab	*command_table;
	int				pid;
	int				status;

	(void)argc;
	(void)argv;
	if ((signal(SIGINT, SIG_IGN)) == SIG_ERR)
		ft_fprintf(STDERR, "\n%s: Error: Cannot catch SIGINT\n", SHELL_NAME);
	if ((signal(SIGQUIT, SIG_IGN)) == SIG_ERR)
		ft_fprintf(STDERR, "\n%s: Error: Cannot catch SIGQUIT\n", SHELL_NAME);
	g_env = init_env(envp);
	/* print_env(); */
	while (1)
	{
		if ((pid = fork()) == -1)
		{
			clear_env();
			print_error_and_exit(strerror(errno));
		}
		if (pid == 0)
		{
			if (!(command_table = read_command()))
			{
				if (errno)
					print_error_and_exit(strerror(errno));
				exit(1);
			}
			execute_command(command_table);
			free_command_table(command_table);
			exit(0);
		}
		if ((waitpid(pid, &status, 0)) == -1)
		{
			clear_env();
			print_error_and_exit(strerror(errno));
		}
		else
		{
			if (WEXITSTATUS(status) == MINISHELL_EXIT)
				break ;
		}
	}
	clear_env();
	return (0);
}
