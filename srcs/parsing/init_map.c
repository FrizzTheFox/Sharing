#include "cub3d.h"

int	get_map_size(t_map *map)
{
	int		line_count;
	int		flag;
	char	*line;
	int		fd;

	line_count = 0;
	flag = 1;
	line = NULL;
	fd = open(map->map_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (flag == 1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			flag = 0;
		if (flag == 1 && line_count > 5)
		{
			if (map->width < ft_strlen(line))
				map->width = ft_strlen(line);
		}
		line_count++;
		free(line);
		line = NULL;
	}
	map->height = line_count - 1;
	return (0);
}

int	parse_map(t_map *map, char *map_path)
{
	int		i;
	int		count;
	int		flag;
	char	*line;
	int		fd;

	(void)map_path;
	i = 0;
	flag = 1;
	line = NULL;
	fd = open(map->map_name, O_RDONLY);
	(void)count;
	(void)i;
	if (fd == -1)
	{
		ft_quit(map, 4);
		return (-1);
	}
	while (flag == 1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			flag = 0;
		if (check_empty_line(line) == 0)
		{
			if (map->texture_counter < 6)
			{
				if (get_texture(map, line) == -1)
					return (-1);
			}
			else if (map->texture_counter >= 6)
			{
				if (get_map(map, line) == -1)
					return (-1);
				map->full_map[map->map_counter] = '\0';
			}
			map->texture_counter++;
		}
		if (line != NULL)
			free(line);
	}
	return (0);
}

void	init_map(t_map *map)
{
	// map->map_name = NULL;
	map->height = 0;
	map->width = 0;
	map->NO = NULL;
	map->SO = NULL;
	map->WE = NULL;
	map->EA = NULL;
	map->floor = NULL;
	map->ceiling = NULL;
	map->texture_counter = 0;
	map->map_counter = 0;
	map->map_height = 0;
	map->map_width = 0;
}
