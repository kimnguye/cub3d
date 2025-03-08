/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:57:53 by kimnguye          #+#    #+#             */
/*   Updated: 2025/03/08 19:36:37 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sprite_param(t_sprite *sprite);

bool	touch_sprite(t_cub *cub, float px, float py)
{
	int	x;
	int	y;

	x = px / BLOCK;
	y = py / BLOCK;
	cub->sprite.hit = false;
	if (cub->map[y] && cub->map[y][x] && cub->map[y][x] == 'P')
	{
		cub->sprite.hit = true;
		return (true);
	}
	if (cub->map[y] && cub->map[y][x] && cub->map[y][x] == '1')
		return (true);
	if (cub->map[y] && cub->map[y][x] && cub->map[y][x] == 'D')
		return (true);
	return (false);
}

/*update ray.x and ray.y until it hits a wall
new method: with step 1*/
// void	calc_short_dist(t_cub *cub, t_ray *ray)
// {
// 	while (1)
// 	{
// 		if (ray->sidedist_x < ray->sidedist_y)
// 		{
// 			ray->sidedist_x += ray->deltadist_x;
// 			ray->x += ray->step_x;
// 		}
// 		else
// 		{
// 			ray->sidedist_y += ray->deltadist_y;
// 			ray->y += ray->step_y;
// 		}
// 		if (touch_sprite(cub, ray->x, ray->y))
// 			break ;
// 	}
// }

/*update ray.x and ray.y until it hits a wall
new method: with step 1*/
void	calc_side_sprite(t_cub *cub, int x)
{
	while (1)
	{
		if (cub->ray.sidedist_x < cub->ray.sidedist_y)
		{
			cub->ray.sidedist_x += cub->ray.deltadist_x;
			cub->ray.x += cub->ray.step_x;
			cub->side = 1;
		}
		else
		{
			cub->ray.sidedist_y += cub->ray.deltadist_y;
			cub->ray.y += cub->ray.step_y;
			cub->side = 0;
		}
		if (touch_sprite(cub, cub->ray.x, cub->ray.y))
			break ;
	}
}

void	draw_sprite(t_cub *cub, t_img *tex_spr, int x)
{
	int		start_y;
	double	step;
	float	height;
	int		color;
	int		end;

	if (cub->sprite.hit == true)
	{
		height = (SPRITE_SIZ / fixed_dist(cub->player, cub->ray.x,
			cub->ray.y)) * (WIDTH / 2);
		start_y = (HEIGHT + height) / 2;
		step = cub->sprite.height / height;
		sprite_param(&cub->sprite);
		cub->ty = 0;
		cub->side = 0;
		cub->tx = tex_x(cub, tex_spr) % cub->sprite.width + cub->sprite.add_w;
		end = min(HEIGHT, (HEIGHT + height) / 2 + (int)height);
		printf("debut sprite y = %i, fin = %i\n, step= %f", start_y, end, step);
		while (start_y < end)
		{
			cub->ty = cub->ty + cub->sprite.add_h;
			color = get_pixel(tex_spr, cub->tx, (int)cub->ty);
			if (color != WHITE && color != GREY)
				put_pixel(&cub->img, x, start_y, color);
			cub->ty += step;
			start_y++;
		}
		printf("TY = %f\n", cub->ty);
	}
}

void	show_sprite(t_cub *cub)
{
	double	ray_angle;
	int		x;

	ray_angle = cub->player.angle - FOV / 2;
	x = 0;
	while (x < WIDTH)
	{
		init_ray(&cub->ray, cub, ray_angle);
		calc_side_sprite(cub, x);
		draw_sprite(cub, &cub->texture_sprite, x);
		ray_angle += cub->fraction;
		x++;
	}
}
