/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:02:23 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/02/14 18:15:01 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(t_map	*map, t_data *img, void *mlx, void *mlx_win)
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
				mlx_put_image_to_window(mlx, mlx_win, img->background,
					x * img->width, y * img->height);
			else if (map->content[y][x] == '1')
				mlx_put_image_to_window(mlx, mlx_win, img->blackhole,
					x * img->width, y * img->height);
			else if (map->content[y][x] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, img->planet,
					x * img->width, y * img->height);
			else if (map->content[y][x] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, img->astronaut,
					x * img->width, y * img->height);
			else if (map->content[y][x] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, img->earth,
					x * img->width, y * img->height);
			else
				ft_error("There is an unspecified character");
		}
		x = -1;
	}
}

int	main(int argc, char **argv)
{	
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_map	map;

	mlx = mlx_init();
	if (mlx == NULL || argc < 2)
		return (0);
	mlx_win = mlx_new_window(mlx, 2200, 400, "so_long");
	img.astronaut = mlx_new_image(mlx, 400, 1000);
	img.addr = mlx_get_data_addr(img.astronaut, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	download_images(mlx, &img);
	read_file(argv[1], &map);
	sizeof_file(&map);
	import_map(&map);
	print_map(&map, &img, mlx, mlx_win);
	mlx_loop(mlx);
	return (0);
}
