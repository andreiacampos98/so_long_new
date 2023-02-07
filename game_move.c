/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:34:03 by anaraujo          #+#    #+#             */
/*   Updated: 2023/02/07 21:32:19 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

/*This function it will check if the next position is a wall*/
int	check_next_positions(t_game *game, char move, char character_next_position)
{
	int	y;
	int	x;

	y = game->map.pp.y;
	x = game->map.pp.x;
	if ((move == 'w' && game->map.map[y - 1][x] == character_next_position)
		|| (move == 's' && game->map.map[y + 1][x] == character_next_position)
		|| (move == 'a' && game->map.map[y][x - 1] == character_next_position)
		|| (move == 'd' && game->map.map[y][x + 1] == character_next_position))
		return (1);
	return (0);
}

/*This function it will count the collectables that already catch.*/
void	count_collectables_catches(t_game *game, char move)
{
	int	y;
	int	x;

	y = game->map.pp.y;
	x = game->map.pp.x;
	if ((move == 'w' && game->map.map[y - 1][x] == COLLECTABLE)
		|| (move == 's' && game->map.map[y + 1][x] == COLLECTABLE)
		|| (move == 'a' && game->map.map[y][x - 1] == COLLECTABLE)
		|| (move == 'd' && game->map.map[y][x + 1] == COLLECTABLE))
		game->collect++;
}

/*This funtion it will quit the game when the player found the exit 
and have collect all the colectable.*/
int	win_game(t_game *game)
{
	if (game->map.can_exit == 1)
	{
		mlx_destroy_window(game->mlx, game->window);
		game->window = NULL;
		return (1);
	}
	else
		return (0);
}

/*This function it will be call everytime that the user click on ASDW.
If the next position is a wall or the next position is an exit and 
there is collectible, the function return 0.*/
/*The number of steps should increase. I will call the function 
count_ollectables_catches.*/
/*If the number of collectables is equal to the original number 
for collectables,we will change the value of can_exit for 1.*/
/*For each move, we will change the position*/
/*If can_exit = 1 and the position that we are is exit, we will call the 
funtion win_game.*/
/*Then we will put the player in that position.*/
void	movement(t_game *game, char move)
{
	if (move == 'd')
		game->map.np = (t_point){game->map.pp.x + 1, game->map.pp.y};
	else if (move == 'a')
		game->map.np = (t_point){game->map.pp.x - 1, game->map.pp.y};
	else if (move == 's')
		game->map.np = (t_point){game->map.pp.x, game->map.pp.y + 1};
	else if (move == 'w')
		game->map.np = (t_point){game->map.pp.x, game->map.pp.y - 1};
}

void	move_player(t_game *game, char move)
{
	static t_components	previous = EMPTY;

	if (check_next_positions(game, move, WALL) == 1)
		return ;
	game->map.map[game->map.pp.y][game->map.pp.x] = previous;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	if (game->collect == game->map.collect)
		game->map.can_exit = 1;
	count_collectables_catches(game, move);
	movement(game, move);
	if (check_next_positions(game, move, COLLECTABLE) == 0)
		previous = game->map.map[game->map.np.y][game->map.np.x];
	else
		previous = EMPTY;
	if (game->map.can_exit == 1
		&& game->map.map[game->map.np.y][game->map.np.x] == EXIT)
		win_game(game);
	game->map.map[game->map.np.y][game->map.np.x] = PLAYER;
	game->map.pp = game->map.np;
}
