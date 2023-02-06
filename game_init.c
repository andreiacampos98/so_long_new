/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:52:20 by anaraujo          #+#    #+#             */
/*   Updated: 2023/01/28 21:06:15 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

/*This function initiate the struct game.*/
t_game	game_init(t_mapdata *map)
{
	t_game	game;

	game.moves = 0;
	game.collect = 0;
	game.map = (*map);
	game.window_size.x = map->size.x * IMG_SIZE;
	game.window_size.y = map->size.y * IMG_SIZE;
	return (game);
}

/*Initializes the MLX library. Must be called before ANY other function. 
Will return NULL if initialization failed.*/
/*Creates a new window instance. It will return a window instance pointer. 
This should be saved for future reference.*/
int	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (0);
	game->window = mlx_new_window(game->mlx, game->window_size.x,
			game->window_size.y, "so_long");
	if (game->window == NULL)
	{
		free(game->window);
		return (0);
	}
	return (1);
}
