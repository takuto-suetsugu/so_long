/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:02:23 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/07 13:30:41 by tsuetsug         ###   ########.fr       */
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

void	print_map(t_map	*map, t_data *img, t_vars *vars)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (y++ < (map->row - 1))
	{
		while (x++ < (map->col - 1))
		{
			if (map->content[y][x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, img->background,
					x * img->width, y * img->height);
			else if (map->content[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, img->blackhole,
					x * img->width, y * img->height);
			else if (map->content[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, img->planet,
					x * img->width, y * img->height);
			else if (map->content[y][x] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, img->astronaut,
					x * img->width, y * img->height);
			else if (map->content[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, img->earth,
					x * img->width, y * img->height);
			else
				ft_error("There is an unspecified character");
		}
		x = -1;
	}
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_W)
	{
		vars->move_y = 1;
		printf("KEY_W\n");
	}
	else if (keycode == KEY_S)
	{
		vars->move_y = -1;
		printf("KEY_S\n");
	}
	else if (keycode == KEY_D)
	{
		vars->move_x = 1;
		printf("KEY_D\n");
	}
	else if (keycode == KEY_A)
	{
		vars->move_x = -1;
		printf("KEY_A\n");
	}
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

char	*search_element_addr(t_map *map, char element)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	while (y++ < (map->row - 1))
	{
		while (x++ < (map->col - 1))
		{
			if (map->content[y][x] == element)
				return (&map->content[y][x]);
		}
		x = -1;
	}
	ft_error("There is no element!");
	return (NULL);
}

void	key_press_proc(t_map *map, t_vars *vars)
{	
	char	*P_addr;
	char	*E_addr;

	P_addr = search_element_addr(map, 'P');
	E_addr = search_element_addr(map, 'E');

	if (vars->move_x == 1)
	{
		*P_addr = '0';
		*(P_addr + 1) = 'P';
	}
	else if (vars->move_x == -1)
	{
		*P_addr = '0';
		*(P_addr - 1) = 'P';
	}
	else if (vars->move_y == 1)
	{
		*P_addr = '0';
		*(P_addr + map->col) = 'P';
	}
	else if (vars->move_y == -1)
	{
		*P_addr = '0';
		*(P_addr - map->col) = 'P';
	}
}

void	vars_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		ft_error("mlx is not valid");
	vars->move_x = 0;
	vars->move_y = 0;
}


int	main(int argc, char **argv)
{	
	t_vars			vars;
	t_data			img;
	t_map			map;

	if (argc != 2)
		ft_error("argc is not 2");
	vars_init(&vars);
	vars.win = mlx_new_window(vars.mlx, 1000, 400, "so_long");
	download_images(&vars, &img);
	import_map(argv[1], &map);
	print_map(&map, &img, &vars);

	while ()
	{
		mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
		key_press_proc(&map, &vars);
	}
	mlx_loop(vars.mlx);
	return (0);
}
