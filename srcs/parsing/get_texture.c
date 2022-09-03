#include "cub3d.h"

int	get_texture(t_map *map, char *line)
{
	if (map->texture_counter < 4)
	{
		if (get_texture_walls(map, line) == -1)
		{
			if (line != NULL)
				free(line);
			ft_quit(map, 5);
			return (-1);
		}
	}
	else if (map->texture_counter >= 4)
	{
		if (get_texture_floor_ceiling(map, line) == -1)
		{
			if (line != NULL)
				free(line);
			ft_quit(map, 5);
			return (-1);
		}
	}
	return (0);
}

int	check_texture_path(char *line)
{
	if ((line[3] != '.' && line[4] != '/') && line[0] != 'F' && line[0] != 'C')
		return (1);
	return (0);
}

char *tmp_function(char *line)
{
	int	i = 3;
	int	j = 0;
	char *ret;
	ret = malloc(sizeof(char) * ft_strlen(line));
	if (!ret)
		return (NULL);
	while (i < (ft_strlen(line) - 3))
	{
		ret[j] = line[i];
		i++;
		j++;
	}
	return (ret);
}

int	get_texture_path(t_map *map, char *line, char *orientation)
{
	if (check_texture_path(line) == 1 && map->texture_counter < 5)
	{
		ft_quit(map, 5);
		return (1);
	}
	else if (ft_strncmp(orientation, "north", 5) == 0)
		map->NO = ft_substr(line, 3, (ft_strlen(line) - 4))/* tmp_function(line) */;
	else if (ft_strncmp(orientation, "south", 5) == 0)
		map->SO = ft_substr(line, 3, (ft_strlen(line) - 4))/* tmp_function(line) */;
	else if (ft_strncmp(orientation, "west", 4) == 0)
		map->WE = ft_substr(line, 3, (ft_strlen(line) - 4))/* tmp_function(line) */;
	else if (ft_strncmp(orientation, "east", 4) == 0)
		map->EA = ft_substr(line, 3, (ft_strlen(line) - 4))/* tmp_function(line) */;
	else if (ft_strncmp(orientation, "floor", 5) == 0)
		map->floor = ft_substr(line, 2, (ft_strlen(line) - 3));
	else if (ft_strncmp(orientation, "ceiling", 7) == 0)
		map->ceiling = ft_substr(line, 2, (ft_strlen(line) - 3));
	return (0);
}

int	get_texture_floor_ceiling(t_map *map, char *line)
{
	if (check_texture_path(line) == 1 && map->texture_counter < 5)
	{
		ft_quit(map, 5);
		return (1);
	}
	if ((ft_strncmp(line, "F ", 2) == 0) && map->texture_counter == 4)
		get_texture_path(map, line, "floor");
	else if ((ft_strncmp(line, "C ", 2) == 0) && map->texture_counter == 5)
		get_texture_path(map, line, "ceiling");
	return (0);
}

int	get_texture_walls(t_map *map, char *line)
{
	if ((ft_strncmp(line, "NO ./", 5) == 0) && map->texture_counter == 0)
		get_texture_path(map, line, "north");
	else if ((ft_strncmp(line, "SO ./", 5) == 0) && map->texture_counter == 1)
		get_texture_path(map, line, "south");
	else if ((ft_strncmp(line, "WE ./", 5) == 0) && map->texture_counter == 2)
		get_texture_path(map, line, "west");
	else if ((ft_strncmp(line, "EA ./", 5) == 0) && map->texture_counter == 3)
		get_texture_path(map, line, "east");
	else
		return (-1);
	return (0);
}
