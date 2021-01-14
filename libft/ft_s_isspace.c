/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_isspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:00:46 by mgeneviv          #+#    #+#             */
/*   Updated: 2021/01/14 15:03:13 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_s_isspace(char *s)
{
	return (*s == ' ' || (*s >= 9 && *s <= 13));
}
