/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutant_split.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:03:32 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/02 05:28:09 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_SPLIT_H
# define SUPER_SPLIT_H

# include <stdint.h>
# include <stdlib.h>

char			**super_split(const char *s, int (*delim_comparator)(char*), 
												int with_protect);

#endif
