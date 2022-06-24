#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

/* ~~~~~~~~~~~~ inc ~~~~~~~~~~~ */

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include "../minilibx_opengl/mlx.h"

# include "../libft/libft.h"
# include "../srcs_b/get_next_line.h"

# define UP		119
# define DOWN	115
# define LEFT	97
# define RIGHT	100
# define ESC	65307
# define SPEED	5
# define RED	"\033[1m\033[31m"
# define GREEN	"\033[1m\033[32m"
# define ENDC	"\033[0m"

/* ~~~~~~~~~~~~ struct ~~~~~~~~~~~ */

enum e_direction
{
	down,
	left,
	right,
	up,
};

typedef struct s_counter
{
	int		empty;
	int		collectible;
	int		exit;
	int		start;
	int		movements;
	int		time;
}	t_counter;

typedef struct s_img
{
	void	*ptr;
	int		*pixels;
	int		mem;
	int		x;
	int		y;
	int		movements;
}	t_img;

typedef struct s_draw
{
	char	**map;
	int		height;
	int		length;
	char	*line;
	char	*temp;
}	t_draw;

typedef struct s_frames
{
	void	*frame0;
	void	*frame1;
	void	*frame2;
	void	*frame3;
	void	*frame4;
	void	*frame5;
	void	*frame6;
	void	*frame7;
	void	*frame8;
	void	*frame9;
}	t_frames;

typedef struct s_emydata
{
	int			direction;
	int			collectible;
	int			exit;
	int			start;
	int			movements;
	t_frames	enemy_a;
}	t_emydata;

typedef struct s_game
{
	void		*mlx_pointer;
	void		*window_pointer;
	t_counter	i;
	t_draw		plot;
	t_img		character;
	t_img		character_l;
	t_img		character_r;
	t_img		character_u;
	t_img		floor;
	t_img		wall;
	t_img		collect;
	t_img		portal;
	t_frames	portal_a;
	t_frames	down_a;
	t_frames	left_a;
	t_frames	right_a;
	t_frames	up_a;
	t_frames	collect_a;
	t_emydata	public;
}	t_game;

/* ~~~~~~~~~~~~ fun ~~~~~~~~~~~ */

void	map_maker(t_game	*game);
void	init_map(t_game *game, char *path);
int		key_check(int keycode, t_game *game);
void	print_moves(t_game *game);
void	move_right(t_game *parameter);
void	move_left(t_game *parameter);
void	move_up(t_game *parameter);
void	move_down(t_game *parameter);
void	player_init(t_game	*game);
int		len_map(char **map, t_game *game);
void	init_so_long(t_game *game);
void	init_images(t_game	*game);
t_img	new_sprite(void *mlx, char *path);
void	destroy_image(t_game *game);
void	free_map(t_game	*game);
int		red_cross(t_game *game);
int		mini_maker(t_game *game);
void	endgame(char *message, t_game *game, int i);
int		check_arg(const char *argv);
int		fix_image(t_game *game);
void	init_sprites(t_game	*game);
int		fix_pos(int keycode, t_game *game);
void	put_image(t_game *game, void *frame);
void	print_map_string(t_game *game);
void	print_potion(t_game *game, int y, int x);
void	print_e(t_game *game, int y, int x);
void	init_enemies(t_game *game, int i, int j);
void	destroy_enemies(t_game *game);
void	init_collec(t_game *game, int i, int j);
void	delay(int milliseconds);
void	init_link_down(t_game *game, int i, int j);
void	init_link_right(t_game *game, int i, int j);
void	init_link_left(t_game *game, int i, int j);
void	init_link_up(t_game *game, int i, int j);
void	init_collec(t_game *game, int i, int j);
void	print_portal(t_game *game);

#endif