/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyesenia <gyesenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 23:10:40 by gyesenia          #+#    #+#             */
/*   Updated: 2020/02/12 23:13:56 by gyesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int ac, char **av)
{
	char		*try;
	t_convert	con;

	(void)ac;
	try = ft_reader(av[1]);
	if (!(ft_strncmp("Error", try, 5)))
	{
		ft_putstr("Invalid file");
		return (0);
	}
	prepare_data(&con, try);
	convert_int(&con, try);
	con.mlx = mlx_init();
	con.win = mlx_new_window(con.mlx, WIDHT, HEIGHT, "fdf");
	draw(&con);
	control_keys(&con);
	mlx_loop(con.mlx);
	free(try);
	free(con.z_points);
	return (0);
}
