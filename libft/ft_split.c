/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahmimid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:12:53 by jahmimid          #+#    #+#             */
/*   Updated: 2021/07/05 17:20:01 by jahmimid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int	wcount;
	int	check;

	wcount = 0;
	check = 1;
	if (s == NULL || *s == '\0')
		return (0);
	while (*s)
	{
		if (*s == c)
			check = 1;
		else if (check == 1)
		{
			wcount++;
			check = 0;
		}
		s++;
	}
	return (wcount);
}

static int	ft_word_lenght(char const *s, char c, int i)
{
	int	wlen;

	wlen = 0;
	if (s == NULL || *s == '\0')
		return (0);
	while (s[i] != '\0' && s[i] != c)
	{
		wlen++;
		i++;
	}
	return (wlen);
}

static char	**ft_free(char **str, int i)
{
	while (str[i] && i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
	return (NULL);
}

static char	**treat(char const *s, char **dst, char c, int slen)
{
	int	a;
	int	b;
	int	d;

	a = 0;
	b = 0;
	while (s[a] && b < slen)
	{
		d = 0;
		while (s[a] == c)
			a++;
		dst[b] = (char *)malloc(sizeof(char) * (ft_word_lenght(s, c, a) + 1));
		if (dst[b] == NULL)
			return (ft_free(dst, b));
		while (s[a] && s[a] != c)
		{
			dst[b][d] = s[a];
			d++;
			a++;
		}
		dst[b][d] = '\0';
		b++;
	}
	dst[b] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	int		slen;
	char	**str;

	slen = ft_word_count(s, c);
	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (slen + 1));
	if (str == NULL)
		return (NULL);
	return (treat(s, str, c, slen));
}
