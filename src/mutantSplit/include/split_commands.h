/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutant_split.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:03:32 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/29 15:03:33 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_COMMANDS_H
# define SPLIT_COMMANDS_H

# include <stdint.h>
# include <stdlib.h>

char		**split_commands(const char *s, char c);

size_t		count_commands(const char *s, char c);

int			is_protect(char c);
char		*skip_protected(const char *s);

#endif

