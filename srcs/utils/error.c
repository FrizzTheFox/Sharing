#include "cub3d.h"

void	ft_quit(t_map *map, int id)
{
	if (id == 1)
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
	else if (id == 2)
		ft_putstr_fd("Error\nThe map file has to be in .cub format\n", 2);
	else if (id == 3)
		ft_putstr_fd("Error\nError during parsing of the map\n", 2);
	else if (id == 4)
		ft_putstr_fd("Error\nCouldn't open map\n", 2);
	else if (id == 5)
		ft_putstr_fd("Error\nError while getting map texture\n", 2);
	else if (id == 6)
		ft_putstr_fd("Error\nNon-valid char found in map\n", 2);
	if (id != 1)
		free_all(map);
	exit(id);
}
