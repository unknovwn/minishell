/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:08:46 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/18 15:52:56 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

char		*read_command(void);
int			execute(char *command);

extern int	g_exit_code;
extern int	g_sin;
extern int	g_sout;

#endif
