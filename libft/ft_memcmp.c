/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahmimid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:44:56 by jahmimid          #+#    #+#             */
/*   Updated: 2021/06/07 14:55:10 by jahmimid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1cpy;
	unsigned char	*s2cpy;

	i = 0;
	if (s1 == s2 || n == 0)
		return (0);
	s1cpy = (unsigned char *)s1;
	s2cpy = (unsigned char *)s2;
	while (s1cpy[i] == s2cpy[i] && i < n - 1)
		i++;
	return (s1cpy[i] - s2cpy[i]);
}
