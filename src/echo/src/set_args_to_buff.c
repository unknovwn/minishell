#include <stdlib.h>

static size_t	count_args_len(int argc, char **args)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (argc != 0)
	{
		i = 0;
		while ((*args)[i] != '\0')
		{
			len += 1;
			i += 1;
		}
		if (argc - 1 != 0)
			len += 1;
		args += 1;
		argc -= 1;
	}
	return (len);
}

static void		set_buff(char **buff, int argc, char **args)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (argc != 0)
	{
		j = 0;
		while ((*args)[j] != '\0')
		{
			(*buff)[i] = (*args)[j];
			i += 1;
			j += 1;
		}
		if (argc - 1 != 0)
			(*buff)[i] = ' ';
		i += 1;
		args += 1;
		argc -= 1;
	}
	(*buff)[i] = '\0';

}

char			*set_args_to_buff(int argc, char **args,
								uint8_t newline_flag)
{
	char	*buff;
	size_t	len;

	len = count_args_len(argc, args);
	if (newline_flag == 1)
		len += 1;
	buff = (char*)malloc(sizeof(char) * (len + 1));
	if (buff == NULL)
		return (NULL);
	set_buff(&buff, argc, args);
	if (newline_flag == 1)
		buff[len - 1] = '\n';
	buff[len] = '\0';
	return (buff);
}
