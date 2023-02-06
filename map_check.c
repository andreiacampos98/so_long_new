/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:18:17 by anaraujo          #+#    #+#             */
/*   Updated: 2023/01/28 20:33:28 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "includes/so_long.h"

/*In this function, I will count the number of exits that there is in the map.*/

int	nb_exit(char **map, char *file)
{
	int	i;
	int	j;
	int	line_count;
	int	count_exit;

	count_exit = 0;
	line_count = count_lines_map(file);
	i = 0;
	while (i < line_count)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
				count_exit++;
			j++;
		}
		i++;
	}
	return (count_exit);
}

/*In this function, I will count the number of players that there is in 
the map.*/

int	nb_player(char **map, char *file)
{
	int	i;
	int	j;
	int	line_count;
	int	count_player;

	count_player = 0;
	line_count = count_lines_map(file);
	i = 0;
	while (i < line_count)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				count_player++;
			j++;
		}
		i++;
	}
	return (count_player);
}

/*In this function, I will count the number of collectibles that 
there is in the map. verify if there is at least one collectible.*/
int	nb_collectible(char **map, char *file)
{
	int	i;
	int	j;
	int	line_count;
	int	count_collectible;

	count_collectible = 0;
	line_count = count_lines_map(file);
	i = 0;
	while (i < line_count)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				count_collectible++;
			j++;
		}
		i++;
	}
	return (count_collectible);
}

/*In this function, I will verify 
if there are only the following character in the array: P, C, E, 1, 0.*/
int	valid_char(t_mapdata mapdata)
{
	int	i;
	int	j;

	i = 0;
	while (i < mapdata.size.y)
	{
		j = 0;
		while (mapdata.map[i][j] != '\0')
		{
			if (mapdata.map[i][j] != 'C' && mapdata.map[i][j] != 'P' &&
				mapdata.map[i][j] != 'E' && mapdata.map[i][j] != '1' &&
				mapdata.map[i][j] != '0')
			{
				matrix_delete(mapdata.map);
				handle_errors("There is an invalid character.");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/*In this function, I will check if there is only one player and exit. 
Furthermore, if there is ate least one collectible.*/

int	valid_components(t_mapdata mapdata)
{
	if (!valid_char(mapdata))
		return (0);
	if (mapdata.player != 1)
	{
		matrix_delete(mapdata.map);
		handle_errors("There must be one 'P'.");
		return (0);
	}
	if (mapdata.collect == 0)
	{
		matrix_delete(mapdata.map);
		handle_errors("There must be at least one 'C'.");
		return (0);
	}
	if (mapdata.exit != 1)
	{
		matrix_delete(mapdata.map);
		handle_errors("There must be one 'E'.");
		return (0);
	}
	return (1);
}

/*In order to test the last functions, I use the following main.*/

/*int	main()
{
	char	**map_0;
	char	**map_1;
	char	**map_2;
	char	**map_3;
	char	**map_4;
	char	**map_5;
	char	*file;
	char	*file_1;
	char	*file_2;
	char	*file_3;
	char	*file_4;
	char	*file_5;
	char	*file_6;
	char	*file_7;
	char	*file_8;
	t_mapdata	mapdata;
	t_mapdata	mapdata_1;
	t_mapdata	mapdata_7;
	t_mapdata	mapdata_8;

	file = "maps/map_2.ber";
	file_1 = "maps_invalid/map_invalid_collectible.ber";
	file_2 = "maps_invalid/map_invalid_exit_2.ber";
	file_3 = "maps_invalid/map_invalid_exit.ber";
	file_4 = "maps_invalid/map_invalid_player_2.ber";
	file_5 = "maps_invalid/map_invalid_player.ber";
	file_6 = "maps_invalid/map_invalid_walls.ber";
	file_7 = "maps_invalid/map_char.ber";
	file_8 = "maps_invalid/map_lines.ber";
	map_0 = read_map(file);
	map_1 = read_map(file_1);
	map_2 = read_map(file_2);
	map_3 = read_map(file_3);
	map_4 = read_map(file_4);
	map_5 = read_map(file_5);
	mapdata = map(file_6);
	mapdata_1 = map(file);
	mapdata_7 = map(file_7);
	mapdata_8 = map(file_8);
	printf("\nChar %i\n", valid_char(mapdata_7));
	printf("\nNb lines equal %i\n", line_length_equal(mapdata_7, file_7));
	printf("\nNb lines equal %i\n", line_length_equal(mapdata_8, file_8));
	printf("\nCollectible %i\n", nb_collectible(map_1, file_1));
	printf("\nOne exit %i\n", nb_exit(map_2, file_2));
	printf("\nOne exit %i\n", nb_exit(map_3, file_3));
	printf("\nOne player %i\n", nb_player(map_4, file_4));
	printf("\nOne player %i\n", nb_player(map_5, file_5));
	printf("\nWalls %i\n", map_surrounded_by_walls(mapdata));
	printf("\nWalls %i\n", map_surrounded_by_walls(mapdata_1));
	return (0);
}*/
