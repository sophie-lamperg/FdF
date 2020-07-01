/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyesenia <gyesenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:59:07 by gyesenia          #+#    #+#             */
/*   Updated: 2019/09/17 13:59:27 by gyesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_list_size(t_list *begin_list)
{
	int count;

	count = 1;
	if (begin_list)
	{
		while (begin_list->next)
		{
			count++;
			begin_list = begin_list->next;
		}
		return (count);
	}
	return (0);
}
