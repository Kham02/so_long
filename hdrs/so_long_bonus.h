#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

/* ~~~~~~~~~~~~ inc ~~~~~~~~~~~ */

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

# include "../Libft/libft.h"
# include "../srcs_b/get_next_line.h"

/* ~~~~~~~~~~~~ struct ~~~~~~~~~~~ */

typedef struct s_img
{
	void	*img;
	int		height;
	int		width;
}t_img;

typedef struct s_count
{
	int	start;
	int	exit;
	int	collect;
	int	floor;
	int	wall;
	int	mov;
	int	enemy;
}t_count;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	char	*line1;
	char	*line2;
}t_map;

typedef struct s_game
{
	t_map	picture;
	t_img	collection;
	t_img	exit;
	t_img	wall;
	t_img	floor;
	t_img	chrct;
	t_img	enemy;
	t_count	count;
	void	*mlx;
	void	*mlx_win;
	int		mov;
}t_game;

/* ~~~~~~~~~~~~ fun ~~~~~~~~~~~ */

char	error(char *mes, t_game *game, int i);
void	destroy_img(t_game *game);
void	free_map(t_game *game);
int		end_game(t_game *game);
void	map_valid(char *av, t_game *game);
void	init_chrct_cllc(t_game *game);
void	draw_mobile(t_game *game, int i, int n);
void	create_window(t_game *game);
void	images(t_game *game);
void	draw(t_game *game, int i, int n);
t_img	new_img(void *mlx, char *str);
int		key(int key, t_game *game);


#endif