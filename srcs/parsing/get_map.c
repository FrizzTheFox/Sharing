#include "cub3d.h"

int	parse_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != '2'
			&& line[i] != ' ' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'W' && line[i] != 'E' && line[i] != '\n'
			&& line[i] != '\t')
			return (-1);
		i++;
	}
	return (0);
}

char	*strip_newline(char *str)
{
	int		len;
	char	*tmp;

	len = ft_strlen(str);
	if (str[len - 1] == '\n')
	{
		tmp = ft_substr(str, 0, len - 1);
		return (tmp);
	}
	else
		return (str);
}

int	fill_map(t_map *map, char *line)
{
	int 	len;
	char	*str;

	len = ft_strlen(line);
	str = strip_newline(line);
	while (len < map->width)
	{
		str = ft_strjoin(str, "1");
		len++;
	}
	map->full_map[map->map_counter] = ft_strdup(str);
	return (0);
}

char	*strip_spaces(char *line)
{
	int 	i;
	int 	count;
	char	*str;

	i = -1;
	count = 0;
	while (line[++i])
	{
		if (line[i] != ' ')
			count++;
	}
	i = 0;
	str = malloc(sizeof(char) * (count + 1));
	count = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			str[count] = line[i];
			count++;
		}
		i++;
	}
	str[count] = '\0';
	return (str);
}

int	get_map(t_map *map, char *line)
{
	char	*newline;

	if (parse_map_line(line) == -1)
		ft_quit(map, 6);
	if (line == NULL)
		map->full_map = NULL;
	else
	{
		newline = strip_spaces(line);
		map->full_map[map->map_counter] = ft_strdup(newline);
		fill_map(map, newline);
		if (map->full_map[map->map_counter] == NULL)
			return (-1);
	}
	map->map_counter++;
	return (0);
}