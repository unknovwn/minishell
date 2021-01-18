/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command_tab_utils.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:28:09 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/18 15:37:50 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_COMMAND_TAB_UTILS_H
# define EXECUTE_COMMAND_TAB_UTILS_H

int	is_in_redirected(int fd);
int	is_out_redirected(int fd);
int	count_argc(char **argv);
int	execute_builtin(char **argv);

#endif
