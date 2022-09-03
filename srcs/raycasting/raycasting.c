#include "cub3d.h"

void	ft_drawstartend(t_map *map)
{
	if (map->ray.side == 0)
		map->ray.perpwalldist = ((double)map->ray.mapx - \
				map->ray.posx + (1 - (double)map->ray.
				stepx) / 2) / map->ray.raydirx;//modifier la formule de calcul perpwalldist pour tests, check que perp = sidedistX - deladistX si side == 0.. check notion
	else
		map->ray.perpwalldist = ((double)map->ray.mapy - \
				map->ray.posy + (1 - (double)map->ray.
				stepy) / 2) / map->ray.raydiry;
	map->ray.lineheight = (int)(map->ry / map->ray.perpwalldist);
	map->ray.drawstart = -map->ray.lineheight / 2 + map->ry / 2;//Là ou on va commencer à dessiner
	if (map->ray.drawstart < 0)
		map->ray.drawstart = 0;
	map->ray.drawend = map->ray.lineheight / 2 + map->ry / 2;//fin du dessin
	if (map->ray.drawend >= map->ry || map->ray.drawend < 0)
		map->ray.drawend = map->ry - 1;
}

void	ft_incrementray(t_map *map)
{
	while (map->ray.hit == 0)//tant qu'un mur n'a pas été touché
	{
		if (map->ray.sidedistx < map->ray.sidedisty)
		{
			map->ray.sidedistx += map->ray.deltadistx;
			map->ray.mapx += map->ray.stepx;
			map->ray.side = 0;
		}
		else
		{
			map->ray.sidedisty += map->ray.deltadisty;
			map->ray.mapy += map->ray.stepy;
			map->ray.side = 1;
		}
		if (map->full_map[map->ray.mapx][map->ray.mapy] == '1')
			map->ray.hit = 1;
	}
	ft_drawstartend(map);
}

void	ft_stepsidedist(t_map *map)
{
	if (map->ray.raydirx < 0)
	{
		map->ray.stepx = -1;
		map->ray.sidedistx = (map->ray.posx - map->ray.mapx) \
							* map->ray.deltadistx;
	}
	else
	{
		map->ray.stepx = 1;
		map->ray.sidedistx = (map->ray.mapx + 1.0 - map->ray.posx) \
							* map->ray.deltadistx;
	}
	if (map->ray.raydiry < 0)
	{
		map->ray.stepy = -1;
		map->ray.sidedisty = (map->ray.posy - map->ray.mapy) \
							* map->ray.deltadisty;
	}
	else
	{
		map->ray.stepy = 1;
		map->ray.sidedisty = (map->ray.mapy + 1.0 - map->ray.posy) \
							* map->ray.deltadisty;
	}
	ft_incrementray(map);
}

int     ft_raycasting(t_map *map)
{
    map->ray.x = 0;
    while (map->ray.x < map->rx)//on lance un rayon pour chaque X
    {
        ft_initray(map);
    	ft_stepsidedist(map);//calcul de la distance entre camera plane et le mur pour déterminer la taille de ceux-ci + drawstart & drawend
		map->ray.x++;
        //check if recup->s.zbuffer[recup->ray.x] = recup->ray.perpwalldist isnt needed once on linux
    }
    /* ft_sprite(map);//to code */
	mlx_put_image_to_window(map->data.mlx_ptr, map->data.mlx_win, map->data.img, 0, 0);
	ft_forward_back(map);
	ft_left_right(map);
	ft_rotate_right_left(map);
	ft_swap(map);//in case it lags
	return (0);
}