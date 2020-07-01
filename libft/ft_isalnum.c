/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyesenia <gyesenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:19:15 by gyesenia          #+#    #+#             */
/*   Updated: 2019/09/09 16:33:17 by gyesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	size_t	res_isalpha;
	size_t	res_isdigit;

	res_isalpha = ft_isalpha(c);
	res_isdigit = ft_isdigit(c);
	if (res_isdigit == 1 || res_isalpha == 1)
		return (1);
	else
		return (0);
}
