/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyesenia <gyesenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:44:37 by gyesenia          #+#    #+#             */
/*   Updated: 2019/09/09 11:37:54 by gyesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i;
	char		*ptr_dst;
	const char	*ptr_src;

	ptr_dst = dst;
	ptr_src = src;
	i = 0;
	while (ptr_src[i] != '\0' && (i < len))
	{
		ptr_dst[i] = ptr_src[i];
		++i;
	}
	while (i < len)
	{
		ptr_dst[i] = '\0';
		i++;
	}
	return (dst);
}
