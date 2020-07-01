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

int				ft_error(char *res)
{
	ft_putendl(res);
	exit(200);
}

int				z_min(t_convert *con)
{
	int			i;
	int			min;

	i = 0;
	min = con->z_points[0];
	while (i < con->z_point)
	{
		if (con->z_points[i] < min)
			min = con->z_points[i];
		i++;
	}
	return (min);
}

int				z_max(t_convert *con)
{
	int			i;
	int			max;

	i = 0;
	max = con->z_points[0];
	while (i < con->z_point)
	{
		if (con->z_points[i] > max)
			max = con->z_points[i];
		i += 2;
	}
	return (max);
}

t_coords		prepare_cord(t_coords point, t_convert *con)
{
	point.x *= con->zoom;
	point.y *= con->zoom;
	point.z *= con->zoom / con->z_div;
	point.x -= (con->x_max * con->zoom) / 2;
	point.y -= (con->y_max * con->zoom) / 2;
	rotate_x(&point.y, &point.z, con->alpha);
	rotate_y(&point.x, &point.z, con->beta);
	rotate_z(&point.x, &point.y, con->gamma);
	if (con->is_iso == 1)
		iso(&point.x, &point.y, point.z);
	point.x += con->shift_x;
	point.y += con->shift_y;
	return (point);
}

t_coords		set_coords(int x, int y, t_convert *con)
{
	t_coords	point_to_put;
	int			index;

	point_to_put.x = x;
	point_to_put.y = y;
	index = ((con->x_max * y) * 2 + (x * 2));
	point_to_put.z = con->z_points[index];
	point_to_put.color = (con->z_points[index + 1] == -1) ?
			get_default_color(point_to_put.z, con) : con->z_points[index + 1];
	return (point_to_put);
}
