/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:09:31 by anaraujo          #+#    #+#             */
/*   Updated: 2023/02/07 18:29:28 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "includes/so_long.h"

/*In this function, I will verify if the map is sorrounded by walls*/

int	map_surrounded_by_walls(t_mapdata mapdata)
{
	int	i;
	int	j;

	i = 0;
	while (i < mapdata.size.y)
	{
		j = 0;
		while (mapdata.map[i][j] != '\0')
		{
			if (i == 0 && mapdata.map[i][j] != '1')
				return (0);
			if (j == 0 && mapdata.map[i][j] != '1')
				return (0);
			if (i == (mapdata.size.y - 1) && mapdata.map[i][j] != '1')
				return (0);
			if (j == (mapdata.size.x - 1) && mapdata.map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*In this function, I will verify if there is a path valid. 
I will use the flood_fill*/
bool	flood_fill(t_mapdata *map, t_point curr, char **maze)
{
	static int	collect = 0;
	static bool	found_exit = false;

	if (maze[curr.y][curr.x] == WALL)
		return (false);
	else if (maze[curr.y][curr.x] == COLLECTABLE)
		collect++;
	else if (maze[curr.y][curr.x] == EXIT)
		found_exit = true;
	maze[curr.y][curr.x] = WALL;
	flood_fill(map, (t_point){curr.x, curr.y - 1}, maze);
	flood_fill(map, (t_point){curr.x - 1, curr.y}, maze);
	flood_fill(map, (t_point){curr.x + 1, curr.y}, maze);
	flood_fill(map, (t_point){curr.x, curr.y + 1}, maze);
	return (collect == map->collect && found_exit);
}

bool	has_valid_path(t_mapdata *mapdata)
{
	char	**dup;
	bool	is_valid;
	int		i;

	i = 0;
	dup = ft_calloc(mapdata->size.y + 1, sizeof(char *));
	if (!dup)
		handle_errors("Failed allocation on has_valid_path()\n");
	while (i < mapdata->size.y)
	{
		dup[i] = ft_strdup(mapdata->map[i]);
		if (!dup[i])
		{
			matrix_delete(dup);
			handle_errors("Failed allocation on has_valid_path()\n");
		}
		i++;
	}
	is_valid = flood_fill(mapdata, mapdata->pp, dup);
	matrix_delete(dup);
	return (is_valid);
}

/*In this function, I will verify if the length of each line is equal*/

int	line_length_equal(t_mapdata mapdata, char *file)
{
	int	i;
	int	j;
	int	line_count;
	int	column_count;

	line_count = count_lines_map(file);
	column_count = count_column_map(mapdata);
	i = 0;
	while (i < line_count)
	{
		j = 0;
		while (mapdata.map[i][j] != '\0')
		{
			if (mapdata.map[i][j + 1] == '\0' && j == (column_count - 1))
				break ;
			else if (mapdata.map[i][j + 1] == '\0' && j != (column_count - 1))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*In this function, I will verify the arguments and if the file is a .ber.*/

int	valid_file(int argc, char *file)
{
	if (argc == 1)
		return (error("There is no arguments."));
	if (argc > 2)
		handle_errors("Only the first file would be used.");
	if (!ft_strend_cmp(file, ".ber"))
		return (error("Map should be a .ber file"));
	return (1);
}
