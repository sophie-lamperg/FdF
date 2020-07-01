/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyesenia <gyesenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:42:42 by gyesenia          #+#    #+#             */
/*   Updated: 2019/09/12 14:27:40 by gyesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t		len_find;

	len_find = ft_strlen(find);
	if (*find == '\0')
		return ((char *)str);
	while (*str != '\0' && len >= len_find)
	{
		if (ft_strncmp(str, find, len_find) == 0)
			return ((char *)str);
		str++;
		len--;
	}
	return (NULL);
}
