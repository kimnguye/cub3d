/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:01:08 by kimnguye          #+#    #+#             */
/*   Updated: 2025/01/31 15:01:46 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

/*closes the program and free everything*/
int	ft_close_all(t_mlx *param)
{
	return (ft_close(param, CLOSE_ALL));
}

/*closes the program and uses a closing code*/
int	ft_close(t_mlx *param, unsigned int code)
{
	if (code >= 5)
		ft_free_map(param->res);
	if (code >= 4)
		ft_free_map(param->map);
	if (code >= 3)
		mlx_destroy_image(param->mlx, param->img_hi);
	if (code >= 2)
		mlx_destroy_image(param->mlx, param->img);
	if (code >= 1)
		mlx_destroy_window(param->mlx, param->win);
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	free(param);
	if (code <= 5)
		ft_printf(" (error code: %i)\n", code);
	exit(EXIT_SUCCESS);
	return (0);
}