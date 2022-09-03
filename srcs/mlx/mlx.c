#include "cub3d.h"

int		ft_exit(t_map *map)
{
	if (map->data.img)
		mlx_destroy_image(map->data.mlx_ptr, map->data.img);
	if (map->texture[0].img)
		mlx_destroy_image(map->data.mlx_ptr, map->texture[0].img);
	if (map->texture[1].img)
		mlx_destroy_image(map->data.mlx_ptr, map->texture[1].img);
	if (map->texture[2].img)
		mlx_destroy_image(map->data.mlx_ptr, map->texture[2].img);
	if (map->texture[3].img)
		mlx_destroy_image(map->data.mlx_ptr, map->texture[3].img);
	if (map->texture[4].img)
		mlx_destroy_image(map->data.mlx_ptr, map->texture[4].img);
	if (map->data.mlx_win)
		mlx_destroy_window(map->data.mlx_ptr, map->data.mlx_win);
	exit(0);
}

int		ft_key_release(int keycode, t_map *map)
{
	if (keycode == 119)//FORWARD
		map->data.forward = 0;
	else if (keycode == 115)//BACK
		map->data.back = 0;
	else if (keycode == 97)//L
		map->data.left = 0;
	else if (keycode == 100)//R
		map->data.right = 0;
	else if (keycode == 65361)//ROTATE L
		map->data.rotate_left = 0;
	else if (keycode == 65363)//ROTATE R
		map->data.rotate_right = 0;
	return (1);
}

int		ft_key_press(int keycode, t_map *map)
{
	if (keycode == 119)//W = 119
		map->data.forward = 1;
	else if (keycode == 115)//S
		map->data.back = 1;
	else if (keycode == 100)//RIGHT
		map->data.left = 1;
	else if (keycode == 97)//LEFT
		map->data.right = 1;
	else if (keycode == 65361)//ROTATE LEFT
		map->data.rotate_left = 1;
	else if (keycode == 65363)//ROTATE RIGHT
		map->data.rotate_right = 1;
/* 	else if (keycode == 65307)
		ft_error(map, "Non jrigole\n"); */
	return (1);
}

int     ft_mlx(t_map *map)
{
    ft_initialisation(map);//initialisation de toutes les variables ray
    map->data.mlx_ptr = mlx_init();
    if (!map->data.mlx_ptr)
        exit(0);//erreur à créer
    mlx_get_screen_size(map->data.mlx_ptr, &map->screenx, &map->screeny);
    ft_get_texture(map);//a compléter pour récupérer les données sur les textures (img, adresse, pixels, octets..)
    map->data.img = mlx_new_image(map->data.mlx_ptr, map->screenx, map->screeny);
    map->data.addr = (int *)mlx_get_data_addr(map->data.img, & map->data.
            bits_per_pixel, &map->data.line_length, &map->data.endian);//on récupère les parametres de la fenêtre mlx & son adresse
    ft_raycasting(map);//to finish
	map->data.mlx_win = mlx_new_window(map->data.mlx_ptr, map->rx, map->ry, "Cub3D");
	map->data.img2 = mlx_new_image(map->data.mlx_ptr, map->rx, map->ry);
	map->data.addr2 = (int *)mlx_get_data_addr(map->data.img2, &map->
			data.bits_per_pixel, &map->data.line_length, &map->data.endian);
    mlx_hook(map->data.mlx_win, 33, 1L << 17, ft_exit, map);
	mlx_hook(map->data.mlx_win, 2, 1L << 0, ft_key_press, map);
	mlx_loop_hook(map->data.mlx_ptr, ft_raycasting, map);
	mlx_hook(map->data.mlx_win, 3, 1L << 1, ft_key_release, map);
	mlx_loop(map->data.mlx_ptr);
	return (0);
}