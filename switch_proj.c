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

void	zomming(int key, t_convert *con)
{
	if (key == NUM_PAD_PLUS)
		con->zoom++;
	else if (key == NUM_PAD_MINUS)
		con->zoom--;
	mlx_clear_window(con->mlx, con->win);
	draw(con);
}

void	iso(int *x, int *y, int z)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -z + (prev_x + prev_y) * sin(0.523599);
}

void	switch_proj(t_convert *con)
{
	con->alpha = 0;
	con->beta = 0;
	con->gamma = 0;
	if (con->is_iso == 1)
		con->is_iso = 0;
	else
		con->is_iso = 1;
	mlx_clear_window(con->mlx, con->win);
	draw(con);
}
