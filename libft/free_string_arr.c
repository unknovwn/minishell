/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_string_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:53:50 by mgeneviv          #+#    #+#             */
/*   Updated: 2020/12/27 19:46:53 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_string_arr(void *arr)
{
	char	**string_arr;
	int		i;

	string_arr = (char**)arr;
	i = 0;
	while (string_arr[i])
		free(string_arr[i++]);
	free(string_arr);
}
