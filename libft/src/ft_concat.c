/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:51:55 by kimnguye          #+#    #+#             */
/*   Updated: 2024/11/04 20:16:46 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*returns the concatenation of 3 strings in a mallocated (char *) */
char	*ft_concat_3(char *str_1, char *str_2, char *str_3)
{
	char	*res;
	int		n;
	int		i;

	i = 0;
	n = ft_strlen(str_1) + ft_strlen(str_2) + ft_strlen(str_3);
	res = malloc (n + 1);
	if (!res)
		return (NULL);
	while (str_1 && *str_1)
		res[i++] = *(str_1++);
	while (str_2 && *str_2)
		res[i++] = *(str_2++);
	while (str_3 && *str_3)
		res[i++] = *(str_3++);
	if (i != n)
		return (NULL);
	res[i] = '\0';
	return (res);
}

// int main (int argc, char **argv)
// {
// 	char	*path;

// 	if (argc != 4)
// 		return (0);
// 	path = ft_concat_3(argv[1], argv[2], argv[3]);
// 	if (path)
// 		ft_printf("$%s$\n", path);
// 	printf("longueur de la chaine: %zu\n", ft_strlen(path));
// 	free(path);
// 	return (0);
// }
