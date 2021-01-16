/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 21:46:32 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/15 21:51:32 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int	cd_command(int argc, char **argv);
int	env_command(void);
int	exit_command(int argc, char **argv);
int	export_command(int argc, char **argv);
int	pwd_command(void);
int	unset_command(int argc, char **argv);

#endif
