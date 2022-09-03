/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahmimid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:34:58 by jahmimid          #+#    #+#             */
/*   Updated: 2021/06/07 14:55:34 by jahmimid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	char	*destcpy;
	char	*srccpy;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	destcpy = (char *)dest;
	srccpy = (char *)src;
	if (dest > src)
	{
		while (len-- > 0)
			destcpy[len] = srccpy[len];
	}
	else
	{
		while (i < len)
		{
			destcpy[i] = srccpy[i];
			i++;
		}
	}
	return (destcpy);
}
