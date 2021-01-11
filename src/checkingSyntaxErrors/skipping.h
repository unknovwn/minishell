/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skipping.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:36:53 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/11 18:36:54 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKIPPING_H
# define SKIPPING_H

char	*skip_protected(char *current);
int		is_protect(char c);
char	*skip_symbols(char *current, char c);
char	*skip_bslash(char *current);
char	*skip_space(char *current);

#endif
