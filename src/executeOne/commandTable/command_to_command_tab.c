#include "command_table.h"
#include "split_str.h"
#include "utils.h"

static int	set_redirect(t_command *cell, t_split_str s)
{
	if (is_redirect_from(s.current))
	{
		skip_sep(&s);
		if ((set_redirect_from(cell, s)) != 0)
			return (-1);
	}
	else if (is_redirect_double_to(s.current))
	{
		skip_sep(&s);
		if ((set_redirect_double_to(cell, s)) != 0)
			return (-1);
	}
	else if (is_redirect_to(s.current))
	{
		skip_sep(&s);
		if ((set_redirect_to(cell, s)) != 0)
			return (-1);
	}
	return (0);
}

static int	set_redirects(t_command *cell, char *command)
{
	t_split_str	s;

	init_str(&s, command, is_redirect_or_space);
	while (*s.current != '\0')
	{
		split_skip_space(&s);
		if (is_redirect(s.current))
		{
			if (set_redirect(cell, s) != 0)
				return (-1);
			skip_sep(&s);
		}
		skip_string(&s);
	}
	return (0);
}

int			commands_to_command_tab(t_command_tab *tab, char **commands)
{
	size_t		i;

	i = 0;
	while (i < tab->len)
	{
		if ((tab->cells[i].argv = split_argv(commands[i])) == NULL)
			return (-1);
		if (tab->cells[i].argv[0] == NULL)
		{
			free(tab->cells[i].argv);
			tab->cells[i].argv = NULL;
		}
		if (set_redirects(&(tab->cells[i]), commands[i]) != 0)
			return (-1);
		i += 1;
	}
	return (0);
}
