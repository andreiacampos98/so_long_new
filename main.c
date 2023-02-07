/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:23:22 by anaraujo          #+#    #+#             */
/*   Updated: 2023/02/07 18:28:53 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "includes/so_long.h"

/*In this function, I will check all the requirements.*/
int	valid_map(char *file, t_mapdata mapdata)
{
	if (!valid_components(mapdata))
		return (0);
	if (!map_surrounded_by_walls(mapdata))
	{
		matrix_delete((mapdata).map);
		handle_errors("The map isn't surrounded by walls.");
		return (0);
	}
	if (!line_length_equal(mapdata, file))
	{
		matrix_delete((mapdata).map);
		handle_errors("The map isn't rectangular.");
		return (0);
	}
	if (!has_valid_path(&mapdata))
	{
		matrix_delete((mapdata).map);
		handle_errors("Invalid path!");
		return (0);
	}
	return (1);
}

void	init_player(t_mapdata *mapdata)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mapdata->map[i])
	{
		while (mapdata->map[i][j])
		{
			if (mapdata->map[i][j] == PLAYER)
			{
				mapdata->pp.x = j;
				mapdata->pp.y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

/*In the main, I will call the funtion I will call the funtion valid map 
in order to check if the map is valid. 
Then, I will call the funtion game_start_map in order to fill the struct game.
To initiate a loop, we call the mlx_loop function with the mlx instance as only 
parameter.Now for each frame it requires, it will call the function update with 
the parameter YourStruct. */
int	main(int argc, char **argv)
{
	t_game		game;
	t_mapdata	mapdata;

	if (!valid_file(argc, argv[1]))
		return (0);
	mapdata = map(argv[1]);
	if (!valid_map(argv[1], mapdata))
		return (0);
	game = game_init(&mapdata);
	if (!init_window(&game))
		return (0);
	init_images(&game);
	render(&game);
	loop_images(game);
	destroy_images(&game);
	if (game.map.map)
		matrix_delete(game.map.map);
	return (0);
}
