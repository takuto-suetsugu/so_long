
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
	char	*p_addr;
	int		col;
	int		row;
}				t_map;

typedef struct s_game {
	void	*mlx;
	void	*win;
	int		move_x;
	int		move_y;
	t_map	map;
	t_data	img;
}				t_game;

/* so_long_utils.c */
void	ft_error(char *error_message);
void	download_images(t_game *game);

/* ft_mlx.c */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/* import_file.c */
void	read_file(char *file_name, t_game *game);
void	import_map(char *file_name, t_game *game);
void	convert_map_2D_array(t_game *game);
void	sizeof_col_row(t_game *game);

/* import_file_error.c */
void	validate_file_name(char *file_name);
void	validate_wall(t_game *game);
void	validate_map_components(t_game *game);

#endif