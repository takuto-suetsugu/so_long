/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:02:23 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/02/14 16:23:35 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

typedef struct	s_data {
	void	*astronaut_img;
	void	*background_img;
	void	*planet_img;
	void	*earth_img;
	void	*blackhole_img;
	int		img_width;
	int		img_height;
	
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_map {
	char	**content;
	int		col;
	int		row;
}				t_map;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	download_images(void *mlx, t_data *img)
{
	int		img_width;
	int		img_height;
	
	img->astronaut_img = mlx_xpm_file_to_image(mlx, "images/astronaut.xpm", &img_width, &img_height);
	img->background_img = mlx_xpm_file_to_image(mlx, "images/background.xpm", &img_width, &img_height);
	img->planet_img = mlx_xpm_file_to_image(mlx, "images/planet.xpm", &img_width, &img_height);
	img->earth_img = mlx_xpm_file_to_image(mlx, "images/earth.xpm", &img_width, &img_height);
	img->blackhole_img = mlx_xpm_file_to_image(mlx, "images/blackhole.xpm", &img_width, &img_height);
	img->img_height = img_height;
	img->img_width = img_width;
}

char	*read_file()
{
	int     fd;
	char    buff[2048+1];
	int     rc;
	char	*str;

	fd = open("maps.ber", O_RDONLY);
	if (fd == -1)
	{
			printf("File open error\n");
			return(NULL);
	}
	rc = read(fd, buff, 2048);
	if (rc == -1)
	{
			printf("File read error\n");
	}
	else
			buff[rc] = '\0';
	close(fd);
	str = ft_strdup(buff);
	return (str);
}

t_map	*import_map(t_map	*map)
{
	char	*buff;
	int		i;
	int		j;
	int		k;
	
	map->col = 34;
	map->row = 6;
	buff = read_file();
	map->content = malloc(sizeof(char*) *(map->row));
	if (!map->content)
	{
		printf("Memory allocation error\n");
		return (0);
	}
	i = 0;
	j = 0;
	k = 0;
	while (i < map->row)
	{
		map->content[i] = malloc(sizeof(char) * map->col);
		while(j < map->col)
		{
			map->content[i][j] = buff[k];
			j++;
			k++;
		}
		map->content[i][j] = '\0';
		printf("%s\n", map->content[i]);
		i++;
		j = 0;
		k++;
	}
	return (map);
}

void    print_map(t_map	*map, t_data *img, void *mlx, void *mlx_win)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < map->row)
	{
		while (x < map->col)
		{
			if (map->content[y][x] == '0')
				mlx_put_image_to_window(mlx, mlx_win, img->background_img, x*img->img_width, y*img->img_height);
			else if (map->content[y][x] == '1')
				mlx_put_image_to_window(mlx, mlx_win, img->blackhole_img, x*img->img_width, y*img->img_height);
			else if (map->content[y][x] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, img->planet_img, x*img->img_width, y*img->img_height);
			else if (map->content[y][x] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, img->astronaut_img, x*img->img_width, y*img->img_height);
			else if (map->content[y][x] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, img->earth_img, x*img->img_width, y*img->img_height);
			else
			{
				printf("\nError\n");
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	} 
}

int	main(void)
{	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_map	map;

	mlx = mlx_init();
	if (mlx == NULL)
		return 0;
	mlx_win = mlx_new_window(mlx, 1400, 1000, "so_long");
	img.astronaut_img = mlx_new_image(mlx, 1400, 1000);
	img.addr = mlx_get_data_addr(img.astronaut_img, &img.bits_per_pixel, &img.line_length,
								&img.endian);	
	download_images(mlx, &img);
	import_map(&map);
	print_map(&map, &img, mlx, mlx_win);
	mlx_loop(mlx);
	return 0;
}
