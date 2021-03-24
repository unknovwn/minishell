#include "libft.h"

void	ft_putstr(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}
