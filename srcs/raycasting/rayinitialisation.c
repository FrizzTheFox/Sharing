#include "cub3d.h"

void	ft_initray2(t_map *map)
{
	if (map->ray.raydiry == 0)//pour eviter la division par 0
		map->ray.deltadistx = 0;
	else if (map->ray.raydirx == 0)//pour eviter la division par 0
		map->ray.deltadistx = 1;
	else
		map->ray.deltadistx = sqrt(1 + (map->ray.raydiry
			* map->ray.raydiry) / (map->ray.raydirx *
			map->ray.raydirx));
	if (map->ray.raydirx == 0)//pour eviter la division par 0
		map->ray.deltadisty = 0;
	else if (map->ray.raydiry == 0)//pour eviter la division par 0
		map->ray.deltadisty = 1;
	else
		map->ray.deltadisty = sqrt(1 + (map->ray.raydirx *
			map->ray.raydirx) / (map->ray.raydiry *
			map->ray.raydiry));
}

void	ft_initray(t_map *map)
{
	map->ray.hit = 0;
	map->ray.perpwalldist = 0;
	map->ray.camerax = 2 * map->ray.x / (double)map->rx - 1;
	map->ray.raydirx = map->ray.dirx + map->ray.planx * \
						map->ray.camerax;
	map->ray.raydiry = map->ray.diry + map->ray.plany * \
						map->ray.camerax;
	map->ray.mapx = (int)map->ray.posx;
	map->ray.mapy = (int)map->ray.posy;
	map->ray.movespeed = 0.1;//to modify for tests
	map->ray.rotspeed = 0.033 * 1.8;//to modify for tests
	ft_initray2(map);
}


void    ft_start_pos(t_map *map)//ne pas oublier de coder la fonction pour stocker la position de départ suite au parsing
{
    if (map->start == 'N')
    {
        map->ray.dirx = -1;
        map->ray.plany = 0.66;
    }
    if (map->start == 'S')
    {
        map->ray.dirx = 1;
        map->ray.plany = -0.66;
    }
    if (map->start == 'E')
    {
        map->ray.dirx = 1;
        map->ray.plany = 0.66;
    }
    if (map->start == 'W')
    {
        map->ray.dirx = -1;
        map->ray.plany = -0.66;
    }
}

void    ft_initialisation(t_map *map)
{
    map->data.forward = 0;
	map->data.back = 0;
	map->data.left = 0;
	map->data.right = 0;
	map->data.rotate_right = 0;
	map->data.rotate_left = 0;
	map->ray.posx = (double)map->dx + 0.5;
	map->ray.posy = (double)map->dy + 0.5;
	map->ray.dirx = 0;
	map->ray.diry = 0;
	map->ray.planx = 0;
	map->ray.plany = 0;
	ft_start_pos(map);//on initie la direction du joueur en fonction de la position de départ de la map
}