/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:38:02 by kimnguye          #+#    #+#             */
/*   Updated: 2025/01/31 15:03:17 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* direction_vector 
N = (0, 1)
S = (0, -1)
E = (1, 0)
W = (-1, 0)
*/

#include "includes/cub3d.h"

/*counts the nb of points in the map (max_x and max_y) fd
returns 0 when success
returns -1 if gnl failed
returns -2 if the map is not rectangular*/
int	ft_init_max(int fd, t_mlx *vars)
{
	char	*gnl;
	int		line_x;

	vars->max_y = 0;
	gnl = get_next_line(fd);
	if (gnl == NULL)
		return (ft_printf("GNL failed\n"), -1);
	vars->max_x = ft_countsplits(gnl, ' ');
	while (gnl)
	{
		vars->max_y++;
		line_x = ft_countsplits(gnl, ' ');
		if (line_x < vars->max_x)
			return (close(fd), get_next_line(fd), free(gnl),
				ft_printf("Memory allocation: FAILED\n"),
				ft_printf("A rectangular map is expected!"), -2);
		free(gnl);
		gnl = get_next_line(fd);
	}
	close(fd);
	 vars->max = vars->max_x * vars->max_y;
	return (0);
}

/*returns a mallocated map
close the program on errors*/
void	fdf_init_map(t_mlx *vars, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_close(vars, 3), (void)0);
	if (ft_init_max(fd, vars) < 0)
		return (ft_close(vars, 3), (void)0);
	vars->map = ft_malloc_map(vars);
	if (vars->map == NULL)
		return (ft_close(vars, 4), (void)0);
}

/* initialize the parameters view (zoom, translation, center)*/
void	ft_init_param_view(t_mlx *vars)
{
	vars->trans_x = 0;
	vars->trans_y = 0;
	vars->margin_x = 0;
	vars->margin_x = 0;
	vars->rot_x = 0;
	vars->rot_y = 0;
	vars->rot_z = 0;
	vars->center_x = WIDTH / 2;
	vars->center_y = HEIGHT / 2;
	vars->view = 1;
}
/*initialize mlx_ptr, win_ptr, img_ptr, img_data, img_hi*/
t_mlx	*fdf_init_vars(void)
{
	t_mlx	*vars;

	vars = malloc (sizeof(t_mlx));
	if (!vars)
		return (NULL);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (free(vars), NULL);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "kimnguye - FdF 42");
	if (!vars->win)
		return (ft_close(vars, 0), NULL);
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars->img)
		return (ft_close(vars, 1), NULL);
	vars->img_data = mlx_get_data_addr
		(vars->img, &vars->pixel_bits, &vars->line_size, &vars->endian);
	if (!vars->img_data)
		return (ft_close(vars, 2), NULL);
	ft_launch_hi(vars);
	if (!vars->img_hi)
		return (ft_close(vars, 3), NULL);
	return (vars);
}