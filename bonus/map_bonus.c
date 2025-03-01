/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:19:24 by kimnguye          #+#    #+#             */
/*   Updated: 2025/02/25 22:22:53 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	draw_player(t_img *img, int x, int y, int color)
{
	int	i;
	int	j;

	j = x;
	while (j < x + PLAYER_SIZ)
	{
		i = y;
		while (i < y + PLAYER_SIZ)
		{
			if (j < MAP_WIDTH && i < MAP_HEIGHT)
				put_pixel(img, j, i, color);
			i++;
		}
		j++;
	}
}

/*draw wall*/
void	draw_square(t_cub *cub, int x, int y, int color)
{
	int	i;

	i = 0;
	while (i < BLOCK && x + i < MAP_WIDTH && y
		+ i < MAP_HEIGHT)
	{
		put_pixel(&cub->mini_map, x + i, y, color);
		put_pixel(&cub->mini_map, x, y + i, color);
		put_pixel(&cub->mini_map, x + BLOCK, y + i, color);
		put_pixel(&cub->mini_map, x + i, y + BLOCK, color);
		i++;
	}
}

void	draw_map(t_cub *cub)
{
	int	j;
	int	i;
	int	x0;
	int	y0;

	x0 = cub->player.x0;
	y0 = cub->player.y0;
	draw_player(&cub->mini_map, cub->player.x - x0, cub->player.y - y0, GREEN);
	i = y0 / BLOCK;
	while (cub->map[i])
	{
		j = x0 / BLOCK;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '1')
			{
				draw_square(cub, (j * BLOCK - x0), (i * BLOCK - y0), BLUE);
			}
			j++;
		}
		i++;
	}
}
