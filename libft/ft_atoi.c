/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyesenia <gyesenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:41:04 by gyesenia          #+#    #+#             */
/*   Updated: 2019/09/18 14:24:12 by gyesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../fdf.h"

int					ft_atoi(const char *str)
{
	int				neg;
	long long int	res;

	res = 0;
	neg = 1;
	while (*str < 32)
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	if (ft_isprint(*str))
		return (ft_error("Error"));
	while (*str >= '0' && *str <= '9')
	{
		if (res < 0 && neg < 0)
			return (0);
		else if (res < 0 && neg > 0)
			return (-1);
		res *= 10;
		res += *str - 48;
		if (res > 2147483647 || res < -2147483648)
			return (ft_error("Error"));
		str++;
	}
	return (res * neg);
}
