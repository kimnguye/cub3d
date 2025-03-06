/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:33:34 by a                 #+#    #+#             */
/*   Updated: 2025/03/06 16:42:24 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_mlx(t_cub *cub)
{
	if (cub)
	{
		if (cub->img.data)
			mlx_destroy_image(cub->mlx, cub->img.data);
		if (cub->mini_map.data)
			mlx_destroy_image(cub->mlx, cub->mini_map.data);
		if (cub->texture_n.data)
			mlx_destroy_image(cub->mlx, cub->texture_n.data);
		if (cub->texture_s.data)
			mlx_destroy_image(cub->mlx, cub->texture_s.data);
		if (cub->texture_w.data)
			mlx_destroy_image(cub->mlx, cub->texture_w.data);
		if (cub->texture_e.data)
			mlx_destroy_image(cub->mlx, cub->texture_e.data);
		if (cub->door.data)
			mlx_destroy_image(cub->mlx, cub->door.data);
		if (cub->win)
			mlx_destroy_window(cub->mlx, cub->win);
		if (cub->mlx)
			(mlx_destroy_display(cub->mlx), free(cub->mlx));
	}
}

void	free_cub(t_cub *cub)
{
	if (cub->map)
		ft_free_double_tab(&cub->map);
	if (cub->line)
		free(cub->line);
	if (cub->map_width)
		free(cub->map_width);
	close(cub->fd);
}

int	close_all(t_cub *cub)
{
	free_cub(cub);
	free_mlx(cub);
	exit(EXIT_SUCCESS);
	return (0);
}

void	exit_error(t_cub *cub, char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	free_cub(cub);
	if (cub->mlx)
		free_mlx(cub);
	exit(1);
}
