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

void			check_map(char *str, int max_x)
{
	int			i;
	int			len;

	i = 0;
	len = 0;
	while (str[i] != '\n')
	{
		if (str[i] != ' ')
		{
			len += 1;
			while (str[i] != ' ' && str[i] != '\n')
				i++;
		}
		else
			i++;
	}
	if (len != max_x)
		ft_error("bad map");
}
