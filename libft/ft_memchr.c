/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyesenia <gyesenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:03:57 by gyesenia          #+#    #+#             */
/*   Updated: 2019/09/09 11:08:27 by gyesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr_s;

	i = 0;
	ptr_s = (const unsigned char *)s;
	while (n-- > 0)
	{
		if (ptr_s[i] == (unsigned char)c)
			return ((void *)ptr_s + i);
		i++;
	}
	return (NULL);
}
