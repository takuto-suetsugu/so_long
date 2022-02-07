/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:02:23 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/02/07 16:32:29 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

typedef struct	s_data {
	void	*wall_img;
	void	*floor_img;
	void	*coin_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    print_map(t_data *img, void *mlx)
{
/* 	char	*wall_path = "images/wall.xpm";
	char	*floor_path = "images/floor.xpm";
	char	*coin_path = "images/coin.xpm"; */
	int		img_width;
	int		img_height;
	
	int map[15][20] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,2,2,2,2,2,2,2,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,2,2,1,0,0,0,0,0,1},
	{1,0,0,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1},
	{1,2,2,0,1,0,2,2,2,1,2,2,2,0,0,0,0,2,2,1},
	{1,2,2,0,1,0,2,2,2,1,2,2,2,0,0,0,0,2,2,1},
	{1,2,2,0,0,0,2,2,2,0,2,2,2,0,0,0,0,2,2,1},
	{1,2,2,0,0,0,1,1,1,1,1,1,1,1,0,0,0,2,2,1},
	{1,2,2,0,0,0,2,2,2,0,2,2,2,0,0,0,0,2,2,1},
	{1,2,2,0,0,0,2,2,2,1,2,2,2,0,1,0,0,2,2,1},
	{1,2,2,0,0,0,2,2,2,1,2,2,2,0,1,0,0,2,2,1},
	{1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,0,2,2,1},
	{1,0,0,0,0,1,2,2,2,2,2,2,2,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,2,2,2,2,2,2,2,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};

	img->wall_img = mlx_xpm_file_to_image(mlx, "images/wall.xpm", &img_width, &img_height);
	img->floor_img = mlx_xpm_file_to_image(mlx, "images/floor.xpm", &img_width, &img_height);
	img->coin_img = mlx_xpm_file_to_image(mlx, "images/coin.xpm", &img_width, &img_height);
	
	int i=0;
	int j=0;
	while (i++ < 15)
	{
		while (j++ < 20)
		{
			if (map[i][j] == 0)
				my_mlx_pixel_put(img, i, j, 0x000000FF);
			else if (map[i][j] == 1)
				my_mlx_pixel_put(img, i, j, 0x0000FF00);
			else if (map[i][j] == 2)
				my_mlx_pixel_put(img, i, j, 0x00FF0000);
			else
			{
				printf("Error/n");
				return ;
			}
		}
		j = 0;
	} 
/* 	while (i++ < 15)
	{
		while (j++ < 20)
		{
			if (map[i][j] == 0)
				my_mlx_pixel_put(img, i, j, 0x000000FF);
			else if (map[i][j] == 1)
				my_mlx_pixel_put(img, i, j, 0x0000FF00);
			else if (map[i][j] == 2)
				my_mlx_pixel_put(img, i, j, 0x00FF0000);
			else
			{
				printf("Error/n");
				return ;
			}
		}
		j = 0;
	} 
	*/
}

int	main(void)
{	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	if (mlx == NULL)
		return 0;
	mlx_win = mlx_new_window(mlx, 2000, 1600, "so_long");
	img.wall_img = mlx_new_image(mlx, 2000, 1600);
	img.addr = mlx_get_data_addr(img.wall_img, &img.bits_per_pixel, &img.line_length,
								&img.endian);	

	print_map(&img, mlx);
	int	i = 0;
	while(i < 1000)
	{
		mlx_put_image_to_window(mlx, mlx_win, img.wall_img, i, 0);
		i += 300;
	}
	mlx_loop(mlx);
	return 0;
}
