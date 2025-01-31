/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:41:14 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/03 14:28:12 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	int		n;
	int		i;
	t_list	*ptr;

	if (!*lst)
		return ;
	i = 0;
	n = ft_lstsize(*lst);
	while (i < n)
	{
		ptr = (*lst)->next;
		del((*lst)->nb);
		free(*lst);
		*lst = ptr;
		i++;
	}
}
