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
	char			*buff;
}					t_printing;

char				*set_args_to_buff(int argc, char **args,
										uint8_t newline_flag);

#endif
