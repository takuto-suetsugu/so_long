/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_file_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:27:09 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/07 15:59:06 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	validate_file_name(char *file_name)
{
	while ((*file_name) && (*file_name != '.'))
		file_name++;
	if (ft_strncmp(file_name, ".ber\0", 5) != 0)
		ft_error("File type is not .ber");
}

void	validate_wall(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++j < game->map.col)
	{
		if (game->map.content[0][j] != '1')
			ft_error("Top wall has a hole");
		else if (game->map.content[(game->map.row) - 1][j] != '1')
			ft_error("Bottom wall has a hole");
	}
	while (++i < game->map.row)
	{
		if (game->map.content[i][0] != '1')
			ft_error("Left wall has a hole");
		else if (game->map.content[i][(game->map.col) - 1] != '1')
			ft_error("Right wall has a hole");
	}
}

/* 
int	count_map_components(char map_component, t_map *map)
{
	int		i;
	char	*p_component;
	int		components_count;

	i = 0;
	components_count = 0;
	while (i < game->map.row)
	{
		p_component = game->map.content[i];
		while (p_component != NULL)
		{
			p_component = ft_strchr(p_component, map_component);
			if (p_component)
				components_count++;
		}
		i++;
	}
	return (components_count);
}
 */

int	count_map_components(char map_components, t_game *game)
{
	int		i;
	int		j;
	int		char_count;

	i = 0;
	j = 0;
	char_count = 0;
	while (i < game->map.row)
	{
		while (j < game->map.col)
		{
			if (game->map.content[i][j] == map_components)
				char_count++;
			j++;
		}
		i++;
		j = -1;
	}
	return (char_count);
}

void	validate_map_components(t_game *game)
{
	int		p_count;
	int		e_count;
	int		c_count;

	p_count = count_map_components('P', game);
	if (p_count != 1)
		ft_error("Player’s starting position is invalid");
	e_count = count_map_components('E', game);
	if (e_count != 1)
		ft_error("Map exit is invalid");
	c_count = count_map_components('C', game);
	if (c_count < 1)
		ft_error("Collectible is invalid");
	validate_wall(game);
}
