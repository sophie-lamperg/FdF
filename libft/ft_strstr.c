/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyesenia <gyesenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:17:57 by gyesenia          #+#    #+#             */
/*   Updated: 2019/09/09 12:27:04 by gyesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	const char *ptr_str;
	const char *ptr_tofind;

	if (*to_find == '\0')
		return ((char *)str);
	while (*str != '\0')
	{
		ptr_str = str;
		ptr_tofind = to_find;
		while (*ptr_tofind != '\0' && *ptr_str == *ptr_tofind)
		{
			ptr_str++;
			ptr_tofind++;
		}
		if (*ptr_tofind == '\0')
			return ((char *)str);
		str++;
	}
	return (NULL);
}
