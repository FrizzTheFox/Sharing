#include "cub3d.h"

int	get_texture_info(t_map *map, int fd)
{
	int		i;
	int		flag;
	char	*line;

	i = 0;
	flag = 1;
	line = NULL;
	while (flag == 1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			flag = 0;
		if (flag == 1)
		{
			if (save_texture_info(map, line) == -1)
				return (-1);
		}
		i++;
		free(line);
		line = NULL;
	}
	return (0);
}

int	save_texture_info(t_map *map, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
	{
		map->NO = ft_substr(line, 3, (ft_strlen(line) - 3));
		if (map->NO == NULL)
			return (-1);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		map->SO = ft_substr(line, 3, (ft_strlen(line) - 3));
		if (map->SO == NULL)
			return (-1);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		map->WE = ft_substr(line, 3, (ft_strlen(line) - 3));
		if (map->WE == NULL)
			return (-1);
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		map->EA = ft_substr(line, 3, (ft_strlen(line) - 3));
		if (map->EA == NULL)
			return (-1);
	}
	return (0);
}
