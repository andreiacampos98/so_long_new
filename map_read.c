/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:18:15 by anaraujo          #+#    #+#             */
/*   Updated: 2023/02/07 18:16:07 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "includes/so_long.h"

/*Function to count the number of lines in the map file*/

int	count_lines_map(char *file)
{
	int			fd;
	int			lines;
	char		*tmp;

	lines = 0;
	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		lines++;
		free(tmp);
	}
	close(fd);
	return (lines);
}

/*Function to count the number of columns in the map file*/

int	count_column_map(t_mapdata mapdata)
{
	t_point		size;

	size.y = 0;
	size.x = 0;
	while (mapdata.map[size.y][size.x] != '\0')
	{
		size.x++;
	}
	return (size.x);
}

/*Function to allocate memory in the array map. 
I use the funtion count_lines_map in order to allocate memory.*/

char	**allocate_memory_to_map(char *file)
{
	t_mapdata	mapdata;
	t_point		size;

	size.y = count_lines_map(file);
	if (size.y <= 0)
	{
		handle_errors("Open or reading the map file. The file may not exist.");
		return (NULL);
	}
	mapdata.map = malloc(sizeof(char *) * (size.y + 1));
	if (!mapdata.map)
	{
		handle_errors("On allocate memory on **map");
		return (NULL);
	}
	return (mapdata.map);
}

/*This function will use the function allocate_memory_to_map in order to 
allocate memory to the array **map with memory.
Then, I will use the function get next line in order to save each line 
in the map array*/

char	**read_map(char *file)
{
	t_mapdata	mapdata;
	int			fd;
	int			i;
	t_point		size;
	char		*str;

	i = 0;
	mapdata.map = allocate_memory_to_map(file);
	size.y = count_lines_map(file);
	fd = open(file, O_RDONLY);
	while (i < size.y)
	{
		str = get_next_line(fd);
		mapdata.map[i] = ft_strtrim(str, "\n");
		free(str);
		i++;
	}
	mapdata.map[i] = 0;
	close(fd);
	return (mapdata.map);
}

t_mapdata	map(char *file)
{
	t_mapdata	mapdata;

	mapdata.map = read_map(file);
	mapdata.size.y = count_lines_map(file);
	mapdata.size.x = count_column_map(mapdata);
	mapdata.exit = nb_exit(mapdata.map, file);
	mapdata.player = nb_player(mapdata.map, file);
	mapdata.collect = nb_collectible(mapdata.map, file);
	mapdata.can_exit = 0;
	mapdata.pp.x = 0;
	mapdata.pp.y = 0;
	init_player(&mapdata);
	return (mapdata);
}

/*In order to test the last functions, I use the following main.*/

/*int	main()
{
	int	i;
	t_mapdata	mapdata;

	i = 0;
	mapdata= map("maps/map.ber");
	while (i < 5)
	{
		printf("%s\n", mapdata.map[i]);
		i++;
	}
	printf("lines %i\n", mapdata.size.y);
	printf("Columns %i\n", mapdata.size.x);
	printf("player %i\n", mapdata.player);
	printf("exit %i\n", mapdata.exit);
	printf("collect %i\n", mapdata.collect);
	printf("point x %i\n", mapdata.point.x);
	printf("point y %i\n", mapdata.point.y);
	return (0);
}*/