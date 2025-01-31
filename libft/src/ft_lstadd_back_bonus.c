/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:30:46 by kimnguye          #+#    #+#             */
/*   Updated: 2024/09/03 14:26:33 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

void	ft_lstadd_back_int(t_list **lst, int n)
{
	if (!*lst)
		*lst = ft_lstnew(n);
	else
		ft_lstlast(*lst)->next = ft_lstnew(n);
}

// we can add an element pointing on other elements
// int	main (void)
// {
// 	t_list	**liste;
// 	t_list	*elem;
// 	int		i;
// 	int		n;
// 	int		*ptr;
// 	n = 5;
// 	liste = malloc (sizeof(t_list *));
// 	if (!liste)
// 	{
// 		printf("erreur de malloc 1\n");
// 		return (0);
// 	}
// 	i = 1;
// 	while (i <= n)
// 	{
// 		ptr = &i;
// 		elem = ft_lstnew(ptr);
// 		ft_lstadd_back(liste, elem);
// 		printf("%i \n", *(int *)(ft_lstlast(*liste)->content));
// 		i++;
// 	}
// 	return (0);
// }
