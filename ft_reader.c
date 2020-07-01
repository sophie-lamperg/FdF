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

#include <unistd.h>
#include "fdf.h"

char			*ft_reader(char *arr)
{
	int			fd;
	char		*buf;
	int			ret;

	fd = open(arr, O_RDONLY);
	if (!(buf = (char *)malloc((sizeof(char) * (100000000 + 1)))))
		return (0);
	if (fd < 0 || (ret = read(fd, buf, 0)) < 0)
		return ("Error");
	while ((ret = read(fd, buf, 100000000)))
	{
		buf[ret] = '\0';
		write(1, buf, ret);
	}
	write(1, "\n", 1);
	close(fd);
	return (buf);
}

void			prepare_data(t_convert *con, char *str)
{
	con->x_max = count_x(str);
	con->y_max = count_y(str);
	check_map(str, con->x_max);
	if (con->x_max > 100 || con->y_max > 100)
	{
		con->is_iso = 0;
		con->zoom = HEIGHT / con->y_max / 2;
		con->shift_x = WIDHT / 4 + WIDHT / 8;
		con->shift_y = HEIGHT / 4;
	}
	else
	{
		con->is_iso = 1;
		con->zoom = 20;
		con->shift_x = WIDHT / 4 * 2;
		con->shift_y = HEIGHT / 4 + HEIGHT / 8;
	}
	con->z_div = 1;
	con->alpha = 0;
	con->beta = 0;
	con->gamma = 0;
}

void			fill_tab(t_convert *con)
{
	while (con->spl_wspace[con->spl_atoi_count])
	{
		con->num_point = 0;
		con->z_points[con->z_point] = \
			ft_atoi(con->spl_wspace[con->spl_atoi_count]);
		con->z_point++;
		while (con->spl_wspace[con->spl_atoi_count][con->num_point] &&
			con->spl_wspace[con->spl_atoi_count][con->num_point] != ',')
			con->num_point++;
		if (con->spl_wspace[con->spl_atoi_count][con->num_point] == ',')
		{
			if (!ft_strncmp("0x",
					&con->spl_wspace[con->spl_atoi_count][++con->num_point], 2))
				con->z_points[con->z_point] = ft_atoi_base(&con->spl_wspace \
				[con->spl_atoi_count][con->num_point + 2], 16);
		}
		else
			con->z_points[con->z_point] = -1;
		con->z_point++;
		free((con->spl_wspace[con->spl_atoi_count]));
		con->spl_atoi_count++;
	}
}

int				convert_int(t_convert *con, char *str)
{
	int			len;

	len = con->x_max * con->y_max;
	if (!(con->z_points = (int *)malloc(sizeof(int) * (len * 2))))
		return (0);
	con->spl_new_line = ft_strsplit(str, '\n');
	con->fst_spl_count = 0;
	con->z_point = 0;
	while (con->spl_new_line[con->fst_spl_count])
	{
		con->spl_atoi_count = 0;
		con->spl_wspace = ft_strsplit(con->spl_new_line[con->fst_spl_count],
				' ');
		fill_tab(con);
		free((con->spl_wspace[con->spl_atoi_count]));
		free(con->spl_new_line[con->fst_spl_count]);
		con->fst_spl_count++;
		free((con->spl_wspace));
	}
	free(con->spl_new_line[con->fst_spl_count]);
	free(con->spl_new_line);
	con->max_z = z_max(con);
	con->z_min = (z_min(con) < 0) ? 0 : z_min(con);
	return (1);
}
