/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:00:31 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/15 18:07:27 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *num)
{
	int		result;
	int		sign;
	int		i;

	i = 0;
	if ((sign = (*num == '-')))
		i++;
	result = 0;
	while (num[i])
	{
		result *= 10;
		result += (num[i++] - '0');
	}
	if (sign)
		result = -result;
	return (result);
}
