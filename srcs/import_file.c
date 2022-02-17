/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:25:50 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/02/17 12:30:53 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	read_file(char *argv, t_map *map)
{
	int		fd;
	char	buff[2048 + 1];
	int		rc;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("File open error");
	rc = read(fd, buff, 2048);
	if (rc == -1)
		ft_error("File read error");
	else if (rc == 0)
		ft_error("No content");
	else
	{
		buff[rc] = '\0';
	}
	close(fd);
	map->str = ft_strdup(buff);
}

void	sizeof_col_row(t_map *map)
{
	int prev_col;
	int	i;

	i = 0;
	prev_col = 0;
	map->col = 0;
	map->row = 0;
	while (map->str[i])
	{
		map->col = 0;
		while ((map->str) && (map->str[i] != '\n'))
		{
			map->col++;
			i++;
		}
		if ((prev_col) && (map->col != prev_col))
			ft_error("Col length is not same");
		prev_col = map->col;
		i++;
		map->row++;
	}
	if ((map->col < 3 && map->row < 5)
		|| (map->col < 5 && map->row < 3))
		ft_error("Map is too small");
}

void	load_map(t_map *map)
{
	int		i;
	int		j;
	int		k;

	map->content = malloc(sizeof(char *) * (map->row));
	if (!map->content)
		ft_error("Map is not allocated");
	i = -1;
	j = -1;
	k = 0;
	while (++i < map->row)
	{
		map->content[i] = malloc(sizeof(char) * map->col);
		while (++j < map->col)
		{
			map->content[i][j] = map->str[k++];
		}
		map->content[i][j] = '\0';
		j = -1;
		k++;
	}
}

void	import_map(char *file_name, t_map *map)
{
	validate_file_name(file_name);
	read_file(file_name, map);
	sizeof_col_row(map);
	load_map(map);
	validate_map_content(map);
	validate_wall(map);
}
