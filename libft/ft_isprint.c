/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyesenia <gyesenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:50:02 by gyesenia          #+#    #+#             */
/*   Updated: 2019/09/09 17:13:33 by gyesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (((c > 32 && c < 48) || (c > 57 && c < 127)) && c != 30 && (c+1 != 58 || c+1 != 78) )
		return (1);
	else
		return (0);
}