/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:55:20 by kimnguye          #+#    #+#             */
/*   Updated: 2025/01/31 15:03:28 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <math.h>
# include "cub3d_define.h"
# include "cub3d_struct.h"
# include "../libft/includes/libft.h"

/*events handler*/
int		mouse_hook(int button, int x, int y, t_mlx *param);
int		key_hook(int key, t_mlx *param);
int		ft_rot_handler(int key, t_mlx *param);
void	ft_translation_handler(int key, t_mlx *vars);

/*ft_close*/
int	ft_close(t_mlx *param, unsigned int code);
int	ft_close_all(t_mlx *param);

/*ft_init*/
t_mlx	*fdf_init_vars(void);
int		ft_init_max(int fd, t_mlx *vars);
void	fdf_init_map(t_mlx *vars, char **argv);
void	ft_init_param_view(t_mlx *vars);

#endif