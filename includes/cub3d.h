#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "../minilibx-linux/mlx.h"

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;//image qui est cherchée via le fichier .cub dans la fonction ft_get_texture // aussi l'adresse de la fenêtre si recup->data.img
	int				*addr;//adresse de la texture, 
	int				bits_per_pixel;//bits per pixel, dans ft_get_texture_adress, on accède a ses infos via la mlx
	int				line_length;//size line, dans ft_get_texture_adress, on accède a ses infos via la mlx
	int				endian;//endian, dans ft_get_texture_adress on accède a ses infos via la mlx, endian désigne la manière dont les ordinateurs organisent les octets pour constituer des nombres
	int				forward;
	int				back;
	int				left;
	int				right;
	int				rotate_left;
	int				rotate_right;
	int				minimapechelle;
	int				width;
	int				height;
	void			*img2;
	int				*addr2;
}					t_data;


typedef struct		s_ray
{
	double			posx;//initialisé dans ft_initialisation2 -> (double)recup->dx + 0.5;   Avec dy, elle représente le vecteur de départ du joueur
	double			posy;//initialisé dans ft_initialisation2 -> (double)recup->dy + 0.5;
	double			dirx;// Direction X du joueur   Avec diry représente le vecteur de la direction du joueur
	double			diry;// Direction Y du joueur  
	double			planx;// Camera plane of the player   Qui constitue le vecteur de la caméra avec plany
	double			plany;//Camera plane of the player
	double			raydirx;//raycasting X, direction X du rayon, = recup->ray.dirx + recup->ray.planx * recup->ray.camerax;
	double			raydiry;//raycasting Y, direction Y du rayon, = recup->ray.diry + recup->ray.plany * recup->ray.camerax;
	double			camerax;// axe horizontal de la caméra, gauche = -1 , milieu = 0, droite = 1
	int				mapx;// coordonnée X du carré dans lequel on est sur la map, initialisé : recup->ray.posx; seulement quel carré non sa position précise en float
	int				mapy;// coordonnée Y du carré dans lequel on est, initialisé : recup->ray.posy;
	double			sidedistx;//sideDistX and sideDistY are initially the distance the ray has to travel from its start position to the first x-side and the first y-side.	
	double			sidedisty;
	double			deltadistx;//distance que le rayon parcours entre chaque point d'intersection vertical
	double			deltadisty;//distance que le rayon parcours entre chaque point d'intersection horizontal

	int				stepx;//1 ou -1
	int				stepy;
	int				hit;// initié a 0 dans ft_initialisation3,  sera 1 si un mur est touché, sinon 0
	int				side;
	double			perpwalldist;// initié a 0 dans ft_initialisation3,  distance entre le joueur et le mur
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			movespeed;//recup->ray.movespeed = 0.1;
	double			rotspeed;//recup->ray.rotspeed = 0.033 * 1.8;						try to modify in ft_initialisation3, may be speed swaps
	int				x;//initié à 0 dans ft_raycasting, sert à parcourir tout les rayons		try to modify in ft_initialisation3
	int				texture;
}					t_ray;


typedef struct		s_sprxy
{
	double			x;//coordinates recup->sxy[v].x = (double)i + 0.5
	double			y;// coor       recup->sxy[v].y = (double)i + 0.5
}					t_sprxy;

typedef struct s_map
{
    int			rx;//taille x et y de la fenêtre
	int			ry;
	char		*floor;
	char		*ceiling;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		start;//position de départ du joueur
	int			dx;//coordonnée départ
	int			dy;
	int			screenx;//resolution
	int			screeny;//resolution
	char		**full_map;//**map
	char		*map_name;
	int			height;
	int			width;
	int			map_height;
	int			map_width;
	int			texture_counter;
	int			map_counter;
	t_sprxy		*sxy;//structure initiée dans ft_init_sprite
	t_data		texture[5];
	t_data		data;
	t_ray		ray;
}	t_map;

//main.c

//utils/error.c
void	ft_quit(t_map *map, int id);
void    print_all(t_map *map);

//parsing/checks.c
int		check_map_name(t_map *map, char *name);
int		check_empty_line(char *line);

//parsing/parsing.c
int		parse_map(t_map *map, char *map_path);

//parsing/init_map.c
int		get_map_size(t_map *map);
int		save_texture_info(t_map *map, char *line);
int		get_texture_info(t_map *map, int fd);
int		parse_map(t_map *map, char *map_path);
void	init_map(t_map *map);

//parsing/get_texture.c
int		get_texture(t_map *map, char *line);
int		check_texture_path(char *line);
int		get_texture_path(t_map *map, char *line, char *orientation);
int		get_texture_floor_ceiling(t_map *map, char *line);
int		get_texture_walls(t_map *map, char *line);
//parsing/get_texture2.c
int		save_texture_info(t_map *map, char *line);
int		get_texture_info(t_map *map, int fd);

//parsing/get_map.c
int		get_map(t_map *map, char *line);

//utils/free.c
void    free_all(t_map *map);
void    free_textures(t_map *map);
void	free_floor_ceiling(t_map *map);
void    free_map(t_map *map);

//utils/walls.c
int		calculate_fullmap_xy(t_map *map);
int 	full_1_walls(t_map *map);
int 	regular_walls(t_map *map);
int 	orientation_checker(t_map *map);

//raycasting/rayinitialisation.c
void    ft_initialisation(t_map *map);
void	ft_initray(t_map *map);
void	ft_initray2(t_map *map);

//raycasting/raycasting.c
int     ft_raycasting(t_map *map);

//raycasting/raycasting_utils.c
void	ft_rotate_left(t_map *map, double olddirx);
void	ft_rotate_right_left(t_map *map);
void	ft_left_right(t_map *map);
void	ft_forward_back(t_map *map);
void	ft_swap(t_map *map);

//mlx/mlx.c
int     ft_mlx(t_map *map);
void    ft_get_texture(t_map *map);
#endif