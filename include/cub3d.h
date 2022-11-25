/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranuytte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:37:16 by ranuytte          #+#    #+#             */
/*   Updated: 2022/06/06 14:51:42 by ranuytte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

# define _USE_MATH_DEFINES
# define WIDTH 			1920
# define HEIGHT 		1080
# define SPEED			0.15
# define ROTATE			0.10
# define A_KEY 			97
# define S_KEY			115
# define D_KEY			100
# define W_KEY			119
# define LEFT_ARROW		65361
# define RIGHT_ARROW	65363
# define ESCAPE			65307
# define NO_WALL			0
# define SO_WALL			1
# define EA_WALL			2
# define WE_WALL			3

typedef struct s_data		t_data;
typedef struct s_elem		t_elem;
typedef struct s_mlx		t_mlx;
typedef struct s_image		t_image;
typedef struct s_raycasting	t_raycasting;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_image;

typedef struct s_mlx
{
	void		*id;
	void		*id_win;
}				t_mlx;

typedef struct s_txts
{
	void			*img;
	unsigned int	*addr;
	unsigned int	*txt;
	int				bpp;
	int				endian;
	int				size_line;
	int				width;
	int				height;
	int				txts_x;
	char			*path;
}t_txts;

typedef struct s_elem
{
	char	*id;
	char	*path;
	int		rgb[3];
}t_elem;

typedef struct s_data
{
	int				key_w;
	int				key_a;
	int				key_s;
	int				key_d;
	int				key_rotate_left;
	int				key_rotate_right;
	int				y_max;
	int				res_x;
	int				res_y;
	char			**map;
	double			player_pos_x;
	double			player_pos_y;
	double			player_dir;
	t_elem			elem[6];
	t_mlx			*mlx;
	t_raycasting	*rc;
	t_image			*image_libx;
	t_txts			texture[4];	
}t_data;

typedef struct s_raycasting
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}t_raycasting;

/* INIT */
void	init_data(t_data *data);
void	init_mlx(t_data *data, t_mlx *mlx);
void	init_map(t_data *data, char *path);

/* PARSER */
int		open_file(char *pathname);
int		read_file(t_data *data, char *path);
int		element_parsing(t_data *data, int fd);
int		check_texture_path(char *path);
int		map_parsing(t_data *data, int fd);
void	free_map(t_data *data);
int		check_map(t_data *data);
int		check_around_space(t_data *data, int pos_i, int pos_j);
int		get_player_pos(t_data *data);
int		check_rgb(t_elem *elem);
int		substitute_coma(char *line);
int		check_nb_element_rgb(char **info);
int		get_int_value(t_elem *elem, char **str);
int		ft_strstr(char *s1, char *s2);
int		spaces_do_not_matter(char **line);
void	clean_free_tmp_split(char *tmp, char **split);
int		check_empty_spaces(t_data *data, int i, int j);

/* GAME */

void	init_plan(t_data *data);
void	init_ray_dir(t_data *data);
void	side_dist(t_raycasting *rc, t_data *data);
void	wall_dist(t_data *data);
int		game_launcher(t_data *data);
void	game_loop(t_data *data);
void	player_move(t_data *data, t_raycasting *rc);
int		raycasting(t_data *data, t_raycasting *rc);
int		which_texture(int side);
int		trgb_convertor(int t, int r, int g, int b);
int		loading_texts(t_data *data, t_txts *texture);
void	print_txts(int x, t_data *data, t_raycasting *rc);
void	modif_mlx_pixel_put(t_image *image_libx, int x, int y, int color);
int		modif_mlx_new_img(void *mlx_ptr, t_image *image_libx, \
		int res_x, int res_y);

/* UTILS */
void	free_split(char **split);
void	clean_exit(t_data *data, int fd_gnl, int fd, char *strerror);
void	free_all(t_data *data);
void	free_elem(t_data *data);
void	free_texture(t_data *data);

#endif
