/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeneviv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:13:19 by mgeneviv          #+#    #+#             */
/*   Updated: 2020/11/07 20:39:18 by mgeneviv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*tail;

	if (!lst || !f)
		return (0);
	result = ft_lstnew(f(lst->content));
	if (!result)
	{
		ft_lstclear(&result, del);
		return (0);
	}
	if (lst->next)
	{
		tail = ft_lstmap(lst->next, f, del);
		if (!tail)
		{
			ft_lstdelone(result, del);
			return (0);
		}
		ft_lstadd_back(&result, tail);
	}
	return (result);
}
