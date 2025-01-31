/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:03:37 by kimnguye          #+#    #+#             */
/*   Updated: 2024/12/09 17:12:43 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_print_split(char **split, char *str)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		printf("%s_", str);
		printf("split[%i]=*%s*\n", i, split[i]);
		i++;
	}
}
