#include "cub3d.h"

//swap in case it lags
void	ft_swap(t_map *map)
{
	void *tmp;

	tmp = map->data.img;
	map->data.img = map->data.img2;
	map->data.img2 = tmp;
	tmp = map->data.addr;
	map->data.addr = map->data.addr2;
	map->data.addr2 = tmp;
}

void	ft_rotate_left(t_map *map, double olddirx)
{
	double oldplanex;

	if (map->data.rotate_left == 1)
	{
		olddirx = map->ray.dirx;
		oldplanex = map->ray.planx;
		map->ray.dirx = map->ray.dirx * cos(map->ray.rotspeed / 2) -
			map->ray.diry * sin(map->ray.rotspeed / 2);
		map->ray.diry = olddirx * sin(map->ray.rotspeed / 2) + map->
			ray.diry * cos(map->ray.rotspeed / 2);
		map->ray.planx = map->ray.planx * cos(map->ray.rotspeed / 2) -
			map->ray.plany * sin(map->ray.rotspeed / 2);
		map->ray.plany = oldplanex * sin(map->ray.rotspeed / 2) +
			map->ray.plany * cos(map->ray.rotspeed / 2);
	}
}

void	ft_rotate_right_left(t_map *map)
{
	double oldplanx;
	double olddirx;

	oldplanx = map->ray.planx;
	olddirx = map->ray.dirx;
	if (map->data.rotate_right == 1)
	{
		map->ray.dirx = map->ray.dirx * cos(-map->ray.rotspeed / 2) -
			map->ray.diry * sin(-map->ray.rotspeed / 2);
		map->ray.diry = olddirx * sin(-map->ray.rotspeed / 2) +
			map->ray.diry * cos(-map->ray.rotspeed / 2);
		map->ray.planx = map->ray.planx * cos(-map->ray.rotspeed / 2)
			- map->ray.plany * sin(-map->ray.rotspeed / 2);
		map->ray.plany = oldplanx * sin(-map->ray.rotspeed / 2) +
			map->ray.plany * cos(-map->ray.rotspeed / 2);
	}
	ft_rotate_left(map, olddirx);
}

void	ft_left_right(t_map *map)
{
	if (map->data.right == 1)
	{
		if (map->full_map[(int)(map->ray.posx + map->ray.diry *
					(map->ray.movespeed * 2))][(int)map->ray.posy] == '0')
			map->ray.posx += map->ray.diry * map->ray.movespeed;
		if (map->full_map[(int)map->ray.posx][(int)(map->ray.posy -
					map->ray.dirx *
					(map->ray.movespeed * 2))] == '0')
			map->ray.posy -= map->ray.dirx * map->ray.movespeed;
	}
	if (map->data.left == 1)
	{
		if (map->full_map[(int)(map->ray.posx - map->ray.diry *
					(map->ray.movespeed * 2))][(int)map->ray.posy] == '0')
			map->ray.posx -= map->ray.diry * map->ray.movespeed;
		if (map->full_map[(int)map->ray.posx][(int)(map->ray.posy +
					map->ray.dirx *
					(map->ray.movespeed * 2))] == '0')
			map->ray.posy += map->ray.dirx * map->ray.movespeed;
	}
}

void	ft_forward_back(t_map *map)
{
	if (map->data.forward == 1)
	{
		if (map->full_map[(int)(map->ray.posx + (map->ray.dirx * map->
						ray.movespeed * 2))][(int)map->ray.posy] == '0')
			map->ray.posx += map->ray.dirx * map->ray.movespeed;
		if (map->full_map[(int)(map->ray.posx)][(int)(map->ray.posy +
					(map->ray.diry * map->ray.movespeed * 2))] == '0')
			map->ray.posy += map->ray.diry * map->ray.movespeed;
	}
	if (map->data.back == 1)
	{
		if (map->full_map[(int)(map->ray.posx - (map->ray.dirx * map->
						ray.movespeed * 2))][(int)(map->ray.posy)] == '0')
			map->ray.posx -= map->ray.dirx * map->ray.movespeed;
		if (map->full_map[(int)(map->ray.posx)][(int)(map->ray.posy -
					(map->ray.diry * map->ray.movespeed * 2))] == '0')
			map->ray.posy -= map->ray.diry * map->ray.movespeed;
	}
}