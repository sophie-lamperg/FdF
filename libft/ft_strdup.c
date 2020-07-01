/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyesenia <gyesenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:45:42 by gyesenia          #+#    #+#             */
/*   Updated: 2019/09/18 12:59:25 by gyesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strdup(const char *src)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	while (src[k] != '\0')
	{
		k++;
		i++;
	}
	str = (char*)malloc(sizeof(*src) * (i + 1));
	i = 0;
	if (!str)
		return (0);
	else
	{
		while (src[i] != '\0')
		{
			str[i] = src[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
}
