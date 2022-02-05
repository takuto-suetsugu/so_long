/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:02:23 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/02/05 17:07:36 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

typedef struct	s_data {
	void	*img;
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

void    print_map(void *mlx, t_data img)
{
    int map;
    int map[15][20] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,C,C,C,C,C,C,C,1,0,0,0,0,0,1},
    {1,0,0,0,0,0,C,C,C,C,C,C,C,1,0,0,0,0,0,1},
    {1,0,0,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1},
    {1,C,C,0,1,0,C,C,C,1,C,C,C,0,0,0,0,C,C,1},
    {1,C,C,0,1,0,C,C,C,1,C,C,C,0,0,0,0,C,C,1},
    {1,C,C,0,0,0,C,C,C,0,C,C,C,0,0,0,0,C,C,1},
    {1,C,C,0,0,0,1,1,1,1,1,1,1,1,0,0,0,C,C,1},
    {1,C,C,0,0,0,C,C,C,0,C,C,C,0,0,0,0,C,C,1},
    {1,C,C,0,0,0,C,C,C,1,C,C,C,0,1,0,0,C,C,1},
    {1,C,C,0,0,0,C,C,C,1,C,C,C,0,1,0,0,C,C,1},
    {1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,0,C,C,1},
    {1,0,0,0,0,1,C,C,C,C,C,C,C,0,0,0,0,0,0,1},
    {1,0,0,0,0,1,C,C,C,C,C,C,C,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    };
}

int	main(void)
{	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
    if (mlx == NULL)
        return 0;
	mlx_win = mlx_new_window(mlx, 1600, 800, "Hello world!");
	img.img = mlx_new_image(mlx, 1600, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    print_map(mlx, &img);
    int i=0;
    int j=0;
    while (i++ < 300)
    {
        while (j++ < 300)   
            my_mlx_pixel_put(&img, i, j, 0x00FF0000);
        j = 0;
    }
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
    return 0;
}
