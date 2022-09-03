#include "cub3d.h"

int strchr_orientation(char *line)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (line[i])
    {
        if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
            || line[i] == 'W')
                count++;
        i++;
    }
    return (count);
}

int orientation_checker(t_map *map)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (map->full_map[i])
    {
        count += strchr_orientation(map->full_map[i]);
        i++;
    }
    if (count == 0 || count > 1)
        return (-1);
    return (0);
}

int regular_walls(t_map *map)
{
    int i;
    int j;

    i = 1;
    while (map->full_map[i])
    {
        j = 0;
        while (map->full_map[i][j])
        {
            if ((j == 0 || j == map->map_width - 1) && map->full_map[i][j] != '1')
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}

int full_1_walls(t_map *map)
{
    int i;
    int j;
    
    i = 0;
    while (map->full_map[i])
    {
        if (i == 0 || i == map->map_height - 1)
        {
            j = 0;
            while(map->full_map[i][j])
            {
                if (ft_strcmp(map->full_map[i][j], '1', 1) != 0)
                    return (-1);
                j++;
            }
        }
        i++;
    }
    return (0);
}

int calculate_fullmap_xy(t_map *map)
{
    int i;

    i = 0;
    while (map->full_map[i])
    {
        i++;
    }
    map->map_height = i;
    i = 0;
    while (map->full_map[i])
    {
        if (map->map_width == 0 || ft_strlen(map->full_map[i]) > map->map_width)
            map->map_width = ft_strlen(map->full_map[i]);
        i++;
    }
    if (!map->map_height || !map->map_width)
        return (-1);
    return (0);
}