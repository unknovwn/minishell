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
