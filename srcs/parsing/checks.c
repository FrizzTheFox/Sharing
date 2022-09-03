#include "cub3d.h"

int	check_map_name(t_map *map, char *name)
{
	int	i;

	i = ft_strlen(name);
	if (name[i - 4] == '.' && name[i - 3] == 'c' && name[i - 2] == 'u'
		&& name[i - 1] == 'b')
	{
		map->map_name = name;
		return (1);
	}
	else
		return (0);
}

int	check_empty_line(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (1);
	while (line[i] != '\0')
	{
		if (ft_isspace(line[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

/* int	check_line_before_parse(char *line)
{
	
} */