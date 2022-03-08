/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:02:23 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/08 12:10:22 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#define X_EVENT_KEY_EXIT		17

void	put_image_to_window(t_game *game, int x, int y, void *component)
{
	mlx_put_image_to_window(game->mlx, game->win, component,
		x * game->img.width, y * game->img.height);
}

void	print_map(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < game->map.row)
	{
		while (++x < game->map.col)
		{
			if (game->map.content[y][x] == '0')
				put_image_to_window(game, x, y, game->img.background);
			else if (game->map.content[y][x] == '1')
				put_image_to_window(game, x, y, game->img.blackhole);
			else if (game->map.content[y][x] == 'C')
				put_image_to_window(game, x, y, game->img.planet);
			else if (game->map.content[y][x] == 'P')
				put_image_to_window(game, x, y, game->img.astronaut);
			else if (game->map.content[y][x] == 'E')
				put_image_to_window(game, x, y, game->img.earth);
			else
				ft_error("There is an unspecified character");
		}
		x = -1;
	}
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_error("mlx is not valid");
	game->move_x = 0;
	game->move_y = 0;
	game->move_count = 0;
}

int	main_loop(t_game *game)
{
	print_map(game);
	mlx_hook(game->win, 2, 0, key_press, game);
	return (0);
}

int	main(int argc, char **argv)
{	
	t_game			game;

	if (argc != 2)
		ft_error("argc is not 2");
	game_init(&game);
	game.win = mlx_new_window(game.mlx, 2300, 400, "so_long");
	download_images(&game);
	import_map(argv[1], &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &destroy_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
