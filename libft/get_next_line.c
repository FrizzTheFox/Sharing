/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahmimid <jahmimid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:37:15 by jahmimid          #+#    #+#             */
/*   Updated: 2022/06/15 13:28:26 by jahmimid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*ft_get_line(char **save, char **line)
{
	int		i;
	char	*new_save;

	i = 0;
	new_save = NULL;
	while ((*save)[i] != '\n' && (*save)[i] != '\0')
		i++;
	if ((*save)[i] == '\n')
	{
		*line = ft_substr(*save, 0, (i + 1));
		new_save = ft_strdup(&(*save)[i + 1]);
	}
	else
		*line = ft_strdup(*save);
	ft_free(save);
	return (new_save);
}

int	ft_read_line(int fd, char **buff, char **save, char **line)
{
	char	*tmp;
	int		read_size;

	read_size = 1;
	while (ft_strchr(*save, '\n') == NULL && read_size > 0)
	{
		read_size = read(fd, *buff, BUFFER_SIZE);
		(*buff)[read_size] = '\0';
		tmp = *save;
		*save = ft_strjoin_gnl(tmp, *buff);
		free(tmp);
	}
	ft_free(buff);
	*save = ft_get_line(save, line);
	if ((!**line))
		ft_free(line);
	return (read_size);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*buff;
	int			read_size;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (read(fd, buff, 0) < 0)
	{
		free(buff);
		return (NULL);
	}
	if (save == NULL)
		save = ft_strdup("");
	read_size = ft_read_line(fd, &buff, &save, &line);
	if (read_size == 0 && line == NULL)
		return (NULL);
	return (line);
}
