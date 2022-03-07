/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:24:55 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/07 15:19:15 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(char *error_message)
{
	printf("\x1b[31m");
	printf("Error: %s\n\n", error_message);
	printf("\x1b[39m");
	exit(1);
}

void	download_images(t_game *game)
{
	int		width;
	int		height;

	game->img.astronaut = mlx_xpm_file_to_image(game->mlx,
			"images/astronaut.xpm", &width, &height);
	game->img.background = mlx_xpm_file_to_image(game->mlx,
			"images/background.xpm", &width, &height);
	game->img.planet = mlx_xpm_file_to_image(game->mlx,
			"images/planet.xpm", &width, &height);
	game->img.earth = mlx_xpm_file_to_image(game->mlx,
			"images/earth.xpm", &width, &height);
	game->img.blackhole = mlx_xpm_file_to_image(game->mlx,
			"images/blackhole.xpm", &width, &height);
	game->img.height = height;
	game->img.width = width;
}
