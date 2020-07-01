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

void			bresenham(t_coords a, t_coords b, t_convert *con)
{
	t_errors	er;
	t_delta		delt;
	t_coords	cur;
	const int	signx = a.x < b.x ? 1 : -1;
	const int	signy = a.y < b.y ? 1 : -1;

	delt.deltax = ft_abs(b.x - a.x);
	delt.deltay = ft_abs(b.y - a.y);
	er.error = delt.deltax - delt.deltay;
	cur = a;
	while (cur.x != b.x || cur.y != b.y)
	{
		mlx_pixel_put(con->mlx, con->win, cur.x, cur.y, color(cur, a, b, delt));
		er.error2 = er.error * 2;
		if (er.error2 > -delt.deltay)
		{
			er.error -= delt.deltay;
			cur.x += signx;
		}
		if (er.error2 < delt.deltax)
		{
			er.error += delt.deltax;
			cur.y += signy;
		}
	}
}

void			draw(t_convert *con)
{
	int			y;
	int			x;

	y = 0;
	while (y < con->y_max)
	{
		x = 0;
		while (x < con->x_max)
		{
			if (x != con->x_max - 1)
				bresenham(prepare_cord(set_coords(x, y, con), con),
						prepare_cord(set_coords(x + 1, y, con), con), con);
			if (y != con->y_max - 1)
				bresenham(prepare_cord(set_coords(x, y, con), con),
						prepare_cord(set_coords(x, y + 1, con), con), con);
			x++;
		}
		y++;
	}
}
