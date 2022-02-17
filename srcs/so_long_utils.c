/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:24:55 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/02/17 12:28:12 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(char *error_message)
{
	printf("\x1b[31m");
	printf("\nError: %s\n", error_message);
    printf("\x1b[39m");
	exit(1);
}

void	download_images(void *mlx, t_data *img)
{
	int		width;
	int		height;

	img->astronaut = mlx_xpm_file_to_image(mlx,
			"images/astronaut.xpm", &width, &height);
	img->background = mlx_xpm_file_to_image(mlx,
			"images/background.xpm", &width, &height);
	img->planet = mlx_xpm_file_to_image(mlx,
			"images/planet.xpm", &width, &height);
	img->earth = mlx_xpm_file_to_image(mlx,
			"images/earth.xpm", &width, &height);
	img->blackhole = mlx_xpm_file_to_image(mlx,
			"images/blackhole.xpm", &width, &height);
	img->height = height;
	img->width = width;
}
