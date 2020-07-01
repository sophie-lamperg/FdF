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

static void		check_shift(t_convert *con)
{
	int			map_width;
	int			map_height;

	map_width = (con->x_max - 1) * con->zoom;
	map_height = (con->y_max - 1) * con->zoom;
	if (con->shift_x + 10 > WIDHT - map_width)
		con->shift_x = WIDHT - map_width;
	if (con->shift_x - 10 < map_width)
		con->shift_x = map_width;
	if (con->shift_y + 10 > HEIGHT - map_height / 2 + 20)
		con->shift_y = HEIGHT - map_height / 2 + 20;
	if (con->shift_y - 10 < map_height / 2)
		con->shift_y = map_height / 2;
}

void			check_abroad(t_convert *con)
{
	int			map_width;
	int			map_height;

	map_width = con->x_max * con->zoom;
	map_height = con->y_max * con->zoom;
	if (con->is_iso == 1)
		check_shift(con);
	else
	{
		if (con->shift_x + 10 > WIDHT - map_width / 2)
			con->shift_x = WIDHT - map_width / 2;
		if (con->shift_x - 10 < map_width / 2 + 20)
			con->shift_x = map_width / 2 + 20;
		if (con->shift_y + 10 > HEIGHT - map_height / 2)
			con->shift_y = HEIGHT - map_height / 2;
		if (con->shift_y - 10 < map_height / 2 + 20)
			con->shift_y = map_height / 2 + 20;
	}
}
