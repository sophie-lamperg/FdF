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

double		percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int			get_default_color(int z, t_convert *con)
{
	double	percentage;

	percentage = percent(con->z_min, con->max_z, z);
	if (percentage < 0.2)
		return (COLOR_DISCO);
	else if (percentage < 0.4)
		return (COLOR_BRICK_RED);
	else if (percentage < 0.6)
		return (COLOR_FLAMINGO);
	else if (percentage < 0.8)
		return (COLOR_JAFFA);
	else
		return (COLOR_SAFFRON);
}

int			get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int			color(t_coords cur, t_coords a, t_coords b, t_delta delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (delta.deltax > delta.deltay)
		percentage = percent(a.x, b.x, cur.x);
	else
		percentage = percent(a.y, b.y, cur.y);
	red = get_light((a.color >> 16) & 0xFF, (b.color >> 16) & 0xFF, percentage);
	green = get_light((a.color >> 8) & 0xFF, (b.color >> 8) & 0xFF, percentage);
	blue = get_light(a.color & 0xFF, b.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
