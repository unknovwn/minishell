#include "minishell_macro.h"
#include "libft.h"

int		echo_command(int argc, char **argv)
{
	int	i;
	int	newline;

	newline = 1;
	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		if ((ft_strchr(argv[i], 'n')))
			newline = 0;
		i++;
	}
	while (i < argc)
	{
		if (i > 1 + !newline)
			ft_putstr(" ", STDOUT);
		ft_putstr(argv[i++], STDOUT);
	}
	if (newline)
		ft_putstr("\n", STDOUT);
	return (0);
}
