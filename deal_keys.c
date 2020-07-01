/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyesenia <gyesenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:15:55 by gyesenia          #+#    #+#             */
/*   Updated: 2020/02/13 13:41:06 by gyesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys_mac.h"
#include <stdio.h>

void			inc_z(int key, t_convert *con)
{
	if (key == NUM_PAD_DOT)
	{
		if (con->z_div < 4)
			con->z_div += 0.1;
		else if (con->z_div > 4 && con->z_div < 10)
			con->z_div += 0.2;
		else if (con->z_div > 10 && con->z_div < 15)
			con->z_div += 0.4;
		else if (con->z_div > 15 && con->z_div < 20)
			con->z_div += 0.4;
	}
	else if (key == NUM_PAD_0)
	{
		if (con->z_div > 10)
			con->z_div -= 1;
		else if (con->z_div > 1)
			con->z_div -= 0.1;
		else if (con->z_div > 0.7)
			con->z_div -= 0.05;
		else if (con->z_div > 0.5)
			con->z_div -= 0.01;
	}
	mlx_clear_window(con->mlx, con->win);
	draw(con);
}

int				deal_key(int key, void *param)
{
	t_convert	*con;

	con = (t_convert*)param;
	if (key == MAIN_PAD_ESC)
	{
		mlx_destroy_window(con->mlx, con->win);
		free(con->z_points);
		exit(0);
	}
	else if (key == NUM_PAD_1 || key == NUM_PAD_3 || key == NUM_PAD_2 ||
			key == NUM_PAD_4 || key == NUM_PAD_6 || key == NUM_PAD_8)
		rotate(key, con);
	else if (key == NUM_PAD_PLUS || key == NUM_PAD_MINUS)
		zomming(key, con);
	else if (key == MAIN_PAD_ARROW_LEFT || key == MAIN_PAD_ARROW_RIGHT ||
		key == MAIN_PAD_ARROW_DOWN || key == MAIN_PAD_ARROW_UP)
		move(key, con);
	else if (key == NUM_PAD_5)
		switch_proj(con);
	else if (key == NUM_PAD_DOT || key == NUM_PAD_0)
		inc_z(key, con);
	return (0);
}
