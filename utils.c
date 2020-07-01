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

int		ft_abs(int a)
{
	return (a < 0) ? -a : a;
}

int		count_y(char *c_y)
{
	int	i;
	int	y_max;

	i = 0;
	y_max = 0;
	while (c_y[i] != '\0')
	{
		if (c_y[i] == '\n')
			y_max = y_max + 1;
		i++;
	}
	return (y_max);
}

int		count_x(char *c_x)
{
	int	i;
	int	x_max;

	i = 0;
	x_max = 0;
	while (c_x[i] != '\n')
	{
		if (c_x[i] != ' ')
		{
			x_max += 1;
			while (c_x[i] != ' ' && c_x[i] != '\n')
				i++;
		}
		else
			i++;
	}
	return (x_max);
}

int		close_win(void *param)
{
	(void)param;
	exit(0);
}

void	control_keys(t_convert *con)
{
	mlx_hook(con->win, 2, 0, deal_key, con);
	mlx_hook(con->win, 17, 0, close_win, con);
}
