#include "cub3d.h"

void	free_all(t_map *map)
{
	free_textures(map);
	free_floor_ceiling(map);
	/* free_map(map); */
}

void	free_textures(t_map *map)
{
	if (map->NO)
	{
		free(map->NO);
		map->NO = NULL;
	}
	if (map->SO)
	{
		free(map->SO);
		map->SO = NULL;
	}
	if (map->WE)
	{
		free(map->WE);
		map->WE = NULL;
	}
	if (map->EA)
	{
		free(map->EA);
		map->EA = NULL;
	}
}

void	free_floor_ceiling(t_map *map)
{
	if (map->floor)
	{
		free(map->floor);
		map->floor = NULL;
	}
	if (map->ceiling)
	{
		free(map->ceiling);
		map->ceiling = NULL;
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->map_counter)
	{
		if (map->full_map[i] != NULL)
			free(map->full_map[i]);
		i++;
	}
	if (map->full_map != NULL)
	{
		free(map->full_map);
		map->full_map = NULL;
	}
}
