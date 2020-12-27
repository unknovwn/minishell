/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:36:31 by mgeneviv          #+#    #+#             */
/*   Updated: 2020/11/01 14:57:47 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	result = (t_list*)malloc(sizeof(t_list));
	if (!result)
		return (0);
	result->content = content;
	result->next = 0;
	return (result);
}
