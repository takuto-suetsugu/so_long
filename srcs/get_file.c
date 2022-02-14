/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:25:50 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/02/14 18:15:01 by tsuetsug         ###   ########.fr       */
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

void	sizeof_file(t_map *map)
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
			if ((prev_col != 0) && (map->row > prev_col))
				ft_error("Row length is not same");
			map->col++;
			i++;
		}
		prev_col = map->col;
		i++;
		map->row++;
	}
}

void	import_map(t_map *map)
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
	while (i++ < (map->row - 1))
	{
		map->content[i] = malloc(sizeof(char) * map->col);
		while (j++ < (map->col - 1))
		{
			map->content[i][j] = map->str[k];
			k++;
		}
		map->content[i][j] = '\0';
		j = -1;
		k++;
	}
}
