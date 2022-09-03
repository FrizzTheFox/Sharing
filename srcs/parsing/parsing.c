#include "cub3d.h"

/* int parse_map(char *map_name)
{
    t_map   map;
    int     map_fd;

    map_fd = open(map_name, O_RDONLY);
    if (map_fd == -1)
    {
        ft_quit(map, 4);
        return (-1);
    }
    map = init_map(map_name, map_fd);
    if (map == NULL)
        return (1);
    printf("Height: %d\n", map.height);
    printf("Width: %d\n", map.width);
    return (0);
} */