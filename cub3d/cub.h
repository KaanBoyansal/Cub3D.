/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 04:10:45 by mboyansa          #+#    #+#             */
/*   Updated: 2024/02/29 19:28:13 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include "./get_next_line/get_next_line.h"
# include "./mlx/mlx.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define WIDTH 800
# define HEIGHT 600
# define BLOCK_SIZE 64
# define ESC 53
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define W 13
# define S 1
# define A 0
# define D 2
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.03
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define FOV 1.047198
# define ANGLE_STEP 0.001309
# define OFFSET 0.6
# define COLLIDE_MULTIPLIER 1.5

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	dir_radian;
	char	dir;
}	t_player;

typedef struct s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct s_ray
{
	t_point		ray_dir;
	t_point		side_dist;
	t_point		delta_dist;

	int			map_x;
	int			map_y;

	double		perp_wall_dist;

	int			step_x;
	int			step_y;

	int			side;
	int			hit;

	t_img		*texture;
	int			tex_x;
}			t_ray;

typedef enum s_side
{
	EAST_WEST,
	NORTH_SOUTH
}	t_side;


typedef struct s_circle_helper
{
	int		x;
	int		y;
	int		err;
	int		color;
}	t_circle_helper;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	char			rgb_flag;

	void			*no_img;
	void			*so_img;
	void			*ea_img;
	void			*we_img;

	struct s_img	*img_data;
	t_img			imgs[4];

	struct s_player	*player;

	int				*c;
	int				*f;

	int				key;
	int				rgb_f;
	int				rgb_c;

	int				ceiling_color;
	int				floor_color;

	int				fd;
	char			**map;
	int				count;
	char			**fd_map;
	int				map_len;
}	t_data;

void			exit_free(void);
int				is_valid_dir(t_data *data);
void			ft_move2(t_player *player, int dir, t_data *data);
int				is_collide(double new_x, double new_y, char **map);
void			init_hooks(t_data *data);
void			w_rgb_to_map(t_data *data);
int				render(t_data *data);
int				init_mlx(t_data *data);
int				loop(int i, char **line);
int				berror(int ernum);
int				if_func(char **tmp, t_data *data, char *line);
int				take_imgs(t_data *data);
int				init_mlx(t_data *data);
int				another_map(t_data *data);
void			free_arr(char **arr);
void			cpy_gamemap(t_data *data);
int				check_file(char *file);
int				ch_check(t_data *data, int start);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*ft_calloc(size_t nelem, size_t elsize);
int				is_in_arrray(char s1, char *set);
int				single_line_check(char **line, t_data *data);
int				check_lines(t_data *data);
int				check_values(char **vals, t_data *data);
char			*ft_strrtrim(char const *s1, char const *set);
int				check_map(t_data *data);
void			game_map(t_data *data, int start);
int				is_valid(t_data *data);
int				ft_atoi(const char *str);
void			cpy_map(t_data *data);
int				rgb_check(t_data *data);
char			**ft_split(char const *s, char c);
int				ft_str_len(char *str);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strdup(const char *s);
void			wall_image(t_data *data);
void			raycast(t_data *data);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
unsigned int	get_pixel_color(int tex_y, t_ray *ray);
void			fix_mirror(t_ray *ray);
int				get_tex_y(int y, t_ray *ray, int line_height);
void			calculate_texture_x(t_data *data, t_ray *ray);
int				safe_divide(int numerator, double denominator);
void			calculate_perpetual(t_data *data, t_ray *ray);
int				is_hit(t_ray *ray, t_data *data);
void			draw_textured_line(t_data *data, t_ray *ray,
					int x, int line_height);
void			draw_floor_ceiling(t_data *data, int x, int lineHeight);
void			init_ray(t_data *data, t_ray *ray, double angle);
void			calculate_step_and_dist(t_data *data, t_ray *ray);
void			ray_step(t_ray *ray);
int				is_boundary_violated(t_ray *ray, int map_size);
void			determine_texture(t_data *data, t_ray *ray);
void			routine(t_data *data);
int				render(t_data *data);
int				index_check(char **vals);
void			init_player(t_data *data);
void			set_dir(t_player *player);
void			wall_image(t_data *data);
int				ch_check(t_data *data, int start);
int				len_pt(char **arr);
void			ft_move(t_player *player, int dir, t_data *data);
void			ft_turn(t_player *player, char dir);
void			free_line_tmp(char *line, char **tmp);
int				rgb_next(t_data *data, char *line, char **values, char *tmp);
void			take_img_next(t_data *data, char **tmp, char *line, int size);
int				linebyline_next(t_data *data, int i, int j);
int				updown_next(t_data *data, int i, int j);
int				updown_if(t_data *data, int i, int j);

#endif