/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyesenia <gyesenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:29:47 by gyesenia          #+#    #+#             */
/*   Updated: 2020/02/13 14:33:44 by gyesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_atoi_base(const char *str, int str_base)
{
	int neg;
	int res;

	neg = 1;
	res = 0;
	while (*str < 33)
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while (*str != '\0')
	{
		res *= str_base;
		if (*str >= '0' && *str <= '9')
			res += *str - 48;
		else if (*str >= 'A' && *str <= 'Z')
			res += *str - 55;
		else if ((*str >= 'a' && *str <= 'z'))
			res += *str - 87;
		str++;
	}
	return (neg * res);
}
