/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyesenia <gyesenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:16:45 by gyesenia          #+#    #+#             */
/*   Updated: 2019/09/17 13:51:25 by gyesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa(int n)
{
	char	*str;
	int		flag;
	int		len;
	int		backup_n;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	backup_n = n;
	len = 2;
	flag = 0;
	ft_itoa_is_negative(&n, &flag);
	while (backup_n /= 10)
		len++;
	len += flag;
	if ((str = (char *)malloc(len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + 48;
		n = n / 10;
	}
	if (flag)
		str[0] = '-';
	return (str);
}
