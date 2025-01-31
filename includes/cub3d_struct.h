/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:58:18 by kimnguye          #+#    #+#             */
/*   Updated: 2025/01/31 15:02:38 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

typedef struct s_pos	t_pos;
typedef struct s_mlx	t_mlx;

typedef struct s_data {
	t_pos	*player;
	t_pos	*dir_vector;
	int		**map;
}	t_data;

typedef struct s_pos {
	double	x;
	double	y;
}	t_pos;

typedef struct s_map {
	int		*x;
	int		*y;
	char	*NO_texture;
	char	*SO_texture;
	char	*WE_texture;
	char	*EA_texture;
	int		F_color[2];
	int		C_color[2];
}	t_map;


typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_hi;
	char	*img_data;
	int		w_hi;
	int		h_hi;
	int		pixel_bits;
	int		line_size;
	int		endian;
	int		max_y;
	int		max_x;
	int		max;
	t_map	*map;
	t_map	*res;
	int		margin_x;
	int		margin_y;
	int		center_x;
	int		center_y;
	int		trans_x;
	int		trans_y;
	float	zoom;
	int		rot_x;
	int		rot_y;
	int		rot_z;
	int		rot_iso;
	float	altitude;
	int		view;
}	t_mlx;

#endif