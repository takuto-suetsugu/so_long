/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:02:23 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/07 16:06:17 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#define KEY_ESC			53
#define KEY_Q			12
#define KEY_W			13
#define KEY_E			14
#define KEY_R			15
#define KEY_A			0
#define KEY_S			1
#define KEY_D			2
#define X_EVENT_KEY_EXIT		17

void	print_map(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (y++ < (game->map.row - 1))
	{
		while (x++ < (game->map.col - 1))
		{
			if (game->map.content[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img.background,
					x * game->img.width, y * game->img.height);
			else if (game->map.content[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img.blackhole,
					x * game->img.width, y * game->img.height);
			else if (game->map.content[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img.planet,
					x * game->img.width, y * game->img.height);
			else if (game->map.content[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img.astronaut,
					x * game->img.width, y * game->img.height);
			else if (game->map.content[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img.earth,
					x * game->img.width, y * game->img.height);
			else
				ft_error("There is an unspecified character");
		}
		x = -1;
	}
}


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

void	key_press_proc(t_game *game)
{	
	char	*P_addr;
	char	*E_addr;

	P_addr = search_element_addr(game, 'P');
	printf("%c", *P_addr);
	printf("%d", game->move_x);
	E_addr = search_element_addr(game, 'E');
	if (game->move_x == 1)
	{
		*P_addr = '0';
		*(P_addr + 1) = 'P';
	}
	else if (game->move_x == -1)
	{
		*P_addr = '0';
		*(P_addr - 1) = 'P';
	}
	else if (game->move_y == 1)
	{
		*P_addr = '0';
		*(P_addr + game->map.col) = 'P';
	}
	else if (game->move_y == -1)
	{
		*P_addr = '0';
		*(P_addr - game->map.col) = 'P';
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		game->move_y = 1;
		printf("KEY_W\n");
	}
	else if (keycode == KEY_S)
	{
		game->move_y = -1;
		printf("KEY_S\n");
	}
	else if (keycode == KEY_D)
	{
		game->move_x = 1;
		printf("KEY_D\n");
	}
	else if (keycode == KEY_A)
	{
		game->move_x = -1;
		printf("KEY_A\n");
	}
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	key_press_proc(game);
	return (0);
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_error("mlx is not valid");
	game->move_x = 0;
	game->move_y = 0;
}

int		main_loop(t_game *game)
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
	game.win = mlx_new_window(game.mlx, 1000, 400, "so_long");
	download_images(&game);
	import_map(argv[1], &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
