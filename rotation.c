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

void	rotate_x(int *y, int *z, double alpha)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) + *z * sin(alpha);
	*z = -prev_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(int *x, int *z, double beta)
{
	int prev_x;

	prev_x = *x;
	*x = prev_x * cos(beta) + *z * sin(beta);
	*z = -prev_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(gamma) - prev_y * sin(gamma);
	*y = prev_x * sin(gamma) + prev_y * cos(gamma);
}

void	rotate(int key, t_convert *con)
{
	if (key == NUM_PAD_2)
		con->alpha += 0.05;
	else if (key == NUM_PAD_8)
		con->alpha -= 0.05;
	else if (key == NUM_PAD_4)
		con->beta -= 0.05;
	else if (key == NUM_PAD_6)
		con->beta += 0.05;
	else if (key == NUM_PAD_1)
		con->gamma += 0.05;
	else if (key == NUM_PAD_3)
		con->gamma -= 0.05;
	mlx_clear_window(con->mlx, con->win);
	draw(con);
}

void	move(int key, t_convert *con)
{
	if (key == MAIN_PAD_ARROW_UP)
		con->shift_y -= 10;
	else if (key == MAIN_PAD_ARROW_DOWN)
		con->shift_y += 10;
	if (key == MAIN_PAD_ARROW_LEFT)
		con->shift_x -= 10;
	else if (key == MAIN_PAD_ARROW_RIGHT)
		con->shift_x += 10;
	check_abroad(con);
	mlx_clear_window(con->mlx, con->win);
	draw(con);
}
