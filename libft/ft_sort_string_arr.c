#include "libft.h"

static int	partition(char **arr, int low, int high)
{
	char		*pivot;
	char		*temp;
	int			i;
	int			j;

	pivot = arr[high];
	i = low;
	j = low - 1;
	while (i < high)
	{
		if ((ft_strcmp(arr[i], pivot)) < 0)
		{
			temp = arr[++j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
		i++;
	}
	temp = arr[j + 1];
	arr[j + 1] = arr[high];
	arr[high] = temp;
	return (j + 1);
}

static void	qsort_string_arr(char **arr, int low, int high)
{
	int			pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, low, high);
		qsort_string_arr(arr, low, pivot_index - 1);
		qsort_string_arr(arr, pivot_index + 1, high);
	}
}

char		**ft_sort_string_arr(char **arr)
{
	int	arr_len;
	int	i;

	arr_len = 0;
	i = 0;
	while (arr[i++])
		arr_len++;
	qsort_string_arr(arr, 0, arr_len - 1);
	return (arr);
}
