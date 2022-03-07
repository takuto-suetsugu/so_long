/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_file_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:27:09 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/07 13:14:53 by tsuetsug         ###   ########.fr       */
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

void	validate_wall(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++j < map->col)
	{
		if (map->content[0][j] != '1')
			ft_error("Top wall has a hole");
		else if (map->content[(map->row) - 1][j] != '1')
			ft_error("Bottom wall has a hole");
	}
	while (++i < map->row)
	{
		if (map->content[i][0] != '1')
			ft_error("Left wall has a hole");
		else if (map->content[i][(map->col) - 1] != '1')
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
	while (i < map->row)
	{
		p_component = map->content[i];
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

int	count_map_components(char map_components, t_map *map)
{
	int		i;
	int		j;
	int		char_count;

	i = 0;
	j = 0;
	char_count = 0;
	while (i < map->row)
	{
		while (j < map->col)
		{
			if (map->content[i][j] == map_components)
				char_count++;
			j++;
		}
		i++;
		j = -1;
	}
	return (char_count);
}

void	validate_map_components(t_map *map)
{
	int		p_count;
	int		e_count;
	int		c_count;

	p_count = count_map_components('P', map);
	if (p_count != 1)
		ft_error("Player’s starting position is invalid");
	e_count = count_map_components('E', map);
	if (e_count != 1)
		ft_error("Map exit is invalid");
	c_count = count_map_components('C', map);
	if (c_count < 1)
		ft_error("Collectible is invalid");
	validate_wall(map);
}
