#include "cub3d.h"

void	ft_get_texture_adress(t_map *map)
{
	map->texture[0].addr = (int *)mlx_get_data_addr(map->texture[0].img,
			&map->texture[0].bits_per_pixel,
			&map->texture[0].line_length, &map->texture[0].endian);
	map->texture[1].addr = (int *)mlx_get_data_addr(map->texture[1].img,
			&map->texture[1].bits_per_pixel,
			&map->texture[1].line_length, &map->texture[1].endian);
	map->texture[2].addr = (int *)mlx_get_data_addr(map->texture[2].img,
			&map->texture[2].bits_per_pixel,
			&map->texture[2].line_length, &map->texture[2].endian);
	map->texture[3].addr = (int *)mlx_get_data_addr(map->texture[3].img,
			&map->texture[3].bits_per_pixel,
			&map->texture[3].line_length, &map->texture[3].endian);
	map->texture[4].addr = (int *)mlx_get_data_addr(map->texture[4].img,
			&map->texture[4].bits_per_pixel,
			&map->texture[4].line_length, &map->texture[4].endian);
}

void	ft_get_texture(t_map *map)
{
	if (!(map->texture[0].img = mlx_xpm_file_to_image(map->data.mlx_ptr,
					map->NO, &(map->texture[0].width),
					&(map->texture[0].height))))
		exit(1);
	if (!(map->texture[1].img = mlx_xpm_file_to_image(map->data.mlx_ptr,
					map->SO, &(map->texture[1].width),
					&(map->texture[1].height))))
		exit(1);
	if (!(map->texture[2].img = mlx_xpm_file_to_image(map->data.mlx_ptr,
					map->WE, &(map->texture[2].width),
					&(map->texture[2].height))))
		exit(1);
	if (!(map->texture[3].img = mlx_xpm_file_to_image(map->data.mlx_ptr,
					map->EA, &(map->texture[3].width),
					&(map->texture[3].height))))
		exit(1);
/* 	if (!(map->texture[4].img = mlx_xpm_file_to_image(map->data.mlx_ptr,
					map->SP, &(map->texture[4].width),
					&(map->texture[4].height))))
		ft_error(map, "Texture S\n"); */
	ft_get_texture_adress(map);
}
