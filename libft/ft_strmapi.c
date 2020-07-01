/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyesenia <gyesenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:49:58 by gyesenia          #+#    #+#             */
/*   Updated: 2019/09/11 17:28:20 by gyesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			i;
	size_t			j;
	char			*str;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	str = (char *)malloc(j + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f((unsigned int)i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
