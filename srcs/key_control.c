/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:26:13 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/07 17:59:42 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#define KEY_ESC		    	53
#define KEY_Q		    	12
#define KEY_W		    	13
#define KEY_E		    	14
#define KEY_R		    	15
#define KEY_A		    	0
#define KEY_S		    	1
#define KEY_D			    2
#define X_EVENT_KEY_EXIT	17

char	*search_element_addr(t_game *game, char element)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	while (y++ < (game->map.row - 1))
	{
		while (x++ < (game->map.col - 1))
		{
			if (game->map.content[y][x] == element)
				return (&game->map.content[y][x]);
		}
		x = -1;
	}
	ft_error("There is no element!");
	return (NULL);
}

void	move_player(t_game *game)
{
	int	next_x;
	int	next_y;

	next_x = game->map.player_x + game->move_x;
	next_y = game->map.player_y + game->move_y;
	if (game->map.content[next_y][next_x] == '1')
		return ;
	game->map.content[game->map.player_y][game->map.player_x] = '0';
	game->map.player_x = next_x;
	game->map.player_y = next_y;
	if (game->map.content[next_y][next_x] == 'E')
	{
		game->map.content[game->map.player_y][game->map.player_x] = 'P';
		destroy_window(game);
	}
	else
		game->map.content[game->map.player_y][game->map.player_x] = 'P';
}

void	key_press_proc(t_game *game)
{
	if (game->move_x || game->move_y)
	{
		move_player(game);
	}
}

int	key_press(int keycode, t_game *game)
{
	game->move_x = 0;
	game->move_y = 0;
	if (keycode == KEY_D)
		game->move_x = 1;
	else if (keycode == KEY_A)
		game->move_x = -1;
	else if (keycode == KEY_S)
		game->move_y = 1;
	else if (keycode == KEY_W)
		game->move_y = -1;
	else if (keycode == KEY_ESC)
		destroy_window(game);
	key_press_proc(game);
	return (0);
}
