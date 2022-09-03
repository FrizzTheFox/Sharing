#include "cub3d.h"

void    print_all(t_map *map)
{
    char    *separator = "----------------------------------------------\n";
    printf("%s", separator);
    printf("4 SIDES \n%s\n%s\n%s\n%s\n", map->NO, map->SO, map->WE, map->EA);
    printf("%s", separator);
    printf("FLOOR & CEILING \n%s\n%s\n", map->floor, map->ceiling);
    printf("%s", separator);
    printf("FULL MAP \n");
    int i = 0;
	while (map->full_map[i] && i < map->map_counter)
	{
		if (i >= 10)
            printf("Map Line %d: %s\n", i, map->full_map[i]);
        else
            printf("Map Line %d:  %s\n", i, map->full_map[i]);
		i++;
	}
    printf("%s", separator);
    printf("Y & X\n");
    printf("Height: %d\n", map->map_height);
	printf("Width: %d\n", map->map_width);/* 
    printf("LAST %d: %s\n", map->map_height, map->full_map[map->map_height - 1]);
    printf("LAST : %s\n", map->full_map[map->map_height]); */
    return ;
}