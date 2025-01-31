/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimnguye <kimnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:58:15 by kimnguye          #+#    #+#             */
/*   Updated: 2025/01/31 15:06:44 by kimnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int main(int argc, char **argv)
{
	int	fd;
	t_mlx	*vars;
	
	if (argc != 2)
		return (printf("error: check the number of your arguments\n"), 1);
	// if (ft_parse(argv[1]))
	// 	return (printf("error: check your argument\n"), 1);
	vars = fdf_init_vars();
	if (!vars)
		return (1);
	// ft_init_map(vars, argv);
	// if (vars->map == NULL)
	// 	return (1);
	// ft_printf("Memory allocation : SUCCES\n");
	// fd = open(argv[1], O_RDONLY);
	// fdf_save_map(fd, vars);
	// close (fd);
	ft_printf("Sauvegarde de la carte: SUCCES\n");
	// ft_initial_view(vars);
	mlx_hook(vars->win, KEYPRESS_EVENT, 1L << 0, key_hook, vars);
	mlx_hook(vars->win, BUTTONPRESS_EVENT, 1L << 2, mouse_hook, vars);
	mlx_hook(vars->win, 17, 1L << 17, ft_close_all, vars);
	mlx_loop(vars->mlx);
	return (0);
}