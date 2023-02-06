/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:58:58 by anaraujo          #+#    #+#             */
/*   Updated: 2023/02/06 20:58:47 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

/*This function initiate the images.*/
void	init_images(t_game *game)
{
	game->img.size.x = IMG_SIZE;
	game->img.size.y = IMG_SIZE;
	game->img.player = mlx_xpm_file_to_image(game->mlx, "imgs/11.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "imgs/13.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.ground = mlx_xpm_file_to_image(game->mlx, "imgs/10.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "imgs/8.xpm",
			&(game->img.size.x), &(game->img.size.y));
	game->img.coin = mlx_xpm_file_to_image(game->mlx, "imgs/12.xpm",
			&(game->img.size.x), &(game->img.size.y));
}

/*In this funcion, I will take the game and mapdata. 
Then I will do a loop, where while exist mapdata, I will call the function
parse_char, in order to build my map with the images.*/
int	render(t_game *game)
{
	int		i;
	int		j;

	if (game->window == NULL)
		return (0);
	i = 0;
	j = 0;
	while (game->map.map[i])
	{
		while (game->map.map[i][j] && game->map.map[i][j] != '\n')
		{
			parse_chars(game, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

/*This function takes the mapdata and put the image in the window*/
void	parse_chars(t_game *game, int i, int j)
{
	if (game->map.map[i][j] == WALL)
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (game->map.map[i][j] == EMPTY)
		mlx_put_image_to_window(game->mlx, game->window, game->img.ground,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (game->map.map[i][j] == PLAYER)
		mlx_put_image_to_window(game->mlx, game->window, game->img.player,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (game->map.map[i][j] == EXIT)
		mlx_put_image_to_window(game->mlx, game->window, game->img.exit,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (game->map.map[i][j] == COLLECTABLE)
		mlx_put_image_to_window(game->mlx, game->window, game->img.coin,
			j * IMG_SIZE, i * IMG_SIZE);
}

/*mlx_loop
Loop over the given MLX pointer. 
Each hook that was registered prior to this will be called accordingly by order 
of registration.*/
/*mlx_loop_hook
Hook into the loop.*/
/*2 - KeyPress*/
/*1L<<0 - KeyPressMask*/

/*33 - ClientMessage*/
/*1L<<5 - LeaveWindowMask*/
void	loop_images(t_game game)
{
	mlx_loop_hook(game.mlx, &render, &game);
	mlx_hook(game.window, KeyPress, KeyPressMask, &handle_keypress, &game);
	mlx_hook(game.window, ClientMessage, LeaveWindowMask,
		&handle_btnrealease, &game);
	mlx_hook(game.window, 17, (1L << 0), ft_exit, &game);
	mlx_loop(game.mlx);
}

void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.ground);
	mlx_destroy_image(game->mlx, game->img.player);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.coin);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}
