/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahmimid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:48:45 by jahmimid          #+#    #+#             */
/*   Updated: 2021/06/10 13:14:22 by jahmimid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src,
		size_t destsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] != '\0' && i < destsize)
		i++;
	j = i;
	while (src[i - j] != '\0' && i + 1 < destsize)
	{
		dest[i] = src[i - j];
		i++;
	}
	if (j < destsize)
		dest[i] = '\0';
	return (j + ft_strlen(src));
}
