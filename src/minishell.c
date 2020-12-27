/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:26:36 by mgeneviv          #+#    #+#             */
/*   Updated: 2020/12/27 16:28:55 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_list	*command_table;
	char	*command_result;

	while (1)
	{
		command_table = read_command();
		command_result = execute(command_table);
		print(command_result);
		ft_lstclear(command_table, free_string_arr);
		free(command_result);
	}
	return (0);
}
