/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skipping.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:36:53 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/12 23:25:20 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKIPPING_H
# define SKIPPING_H

char	*cse_skip_protected(char *current);
int		cse_is_protect(char c);
char	*cse_skip_symbols(char *current, char c);
char	*skip_bslash(char *current);
char	*skip_space(char *current);

#endif
