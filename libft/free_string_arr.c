#include <stdlib.h>

void	free_string_arr(void *arr)
{
	char	**string_arr;
	int		i;

	if (arr == NULL)
		return ;
	string_arr = (char**)arr;
	i = 0;
	while (string_arr[i])
		free(string_arr[i++]);
	free(string_arr);
}
