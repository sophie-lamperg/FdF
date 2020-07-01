/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyesenia <gyesenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:29:08 by gyesenia          #+#    #+#             */
/*   Updated: 2019/09/11 16:03:42 by gyesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

void				*ft_memalloc(size_t size)
{
	void	*memalloc;

	if (!(memalloc = (void *)malloc(size)))
		return (NULL);
	ft_bzero(memalloc, size);
	return (memalloc);
}
