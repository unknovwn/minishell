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

#ifndef MUTANT_SPLIT_H
# define MUTANT_SPLIT_H

# include <stdint.h>
# include <stdlib.h>

char		**mutant_split(const char *s, char c);

typedef struct		s_split_str
{
	char	*current;
	char	*after_protecting;
	char	separator;
	uint8_t	new_word_flag;
}					t_split_str;

size_t		count_elements(t_split_str str);

char		*skip_protected(const char *s);

#endif

