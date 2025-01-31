/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:49:52 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/03 14:30:13 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*create a new list resulting from the application of f to each element*/
t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*new;
	t_list	*res;
	t_list	*old;

	if (!lst)
		return (NULL);
	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	old = res;
	old->nb = f(lst->nb);
	old->next = NULL;
	lst = lst->next;
	while (lst)
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return (ft_lstclear(&res, del), NULL);
		new->nb = f(lst->nb);
		new->next = NULL;
		old->next = new;
		old = old->next;
		lst = lst->next;
	}
	return (res);
}
