
#ifndef SO_LONG_H
# define SO_LONG_H
# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include   <errno.h>
#include    <fcntl.h>

# include "../libft/libft.h"
# include "../minilibx_mms_20200219/mlx.h"

typedef struct s_data {
	void	*astronaut;
	void	*background;
	void	*planet;
	void	*earth;
	void	*blackhole;
	int		width;
	int		height;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map {
	char	*str;
	char	**content;
	int		col;
	int		row;
}				t_map;

void	ft_error(char *error_message);
void	download_images(void *mlx, t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	read_file(char *argv, t_map *map);
void	import_map(char *file_name, t_map *map);
void	sizeof_col_row(t_map *map);
void	validate_file_name(char *argv);
void	validate_wall(t_map *map);
void	validate_map_content(t_map *map);

#endif