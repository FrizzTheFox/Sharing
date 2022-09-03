/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahmimid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:48:57 by jahmimid          #+#    #+#             */
/*   Updated: 2021/06/10 13:14:03 by jahmimid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src,
		size_t destsize)
{
	int	i;

	i = 0;
	if (src == NULL || dest == NULL)
		return (0);
	if (destsize > 0)
	{
		while (src[i] != '\0' && destsize > 1)
		{
			dest[i] = src[i];
			i++;
			destsize--;
		}
		dest[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}
