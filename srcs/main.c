#include "cub3d.h"

int	map_validation(t_map *map)
{
	if (calculate_fullmap_xy(map) == -1)
		return (-1);
	else if (full_1_walls(map) == -1 || regular_walls(map) == -1)
		return (-1);
	else if (orientation_checker(map) == -1)
		return (-1);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_map	map;

	(void)envp;
	(void)argc;
	(void)argv;
	if (argc != 2)
		ft_quit(&map, 1);
	init_map(&map);
	if (check_map_name(&map, argv[1]) == 0)
		ft_quit(&map, 2);
	get_map_size(&map);
	map.full_map = malloc(sizeof(char *) * (map.map_counter + 1));
	if (map.full_map == NULL)
	{
		free_all(&map);
		return (-1);
	}
	if (parse_map(&map, argv[1]) == -1 || map_validation(&map) == -1)
		ft_quit(&map, 3);
	/* print_all(&map);//printer */
	ft_mlx(&map);
	free_all(&map);
	return (0);
}
