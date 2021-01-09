/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 21:01:45 by gdrive            #+#    #+#             */
/*   Updated: 2021/01/09 21:01:46 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECHO_H
# define ECHO_H

# include <stdint.h>

typedef struct		s_printing
{
	uint8_t			newline_flag;
	char			**args;
	int				argc;
	char			**current;
	char			*buff;
	size_t			buff_len;
}					t_printing;

#endif
