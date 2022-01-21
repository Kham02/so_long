#ifndef SO_LONG_UTILS_H
#define SO_LONG_UTILS_H

typedef struct s_img
{
	void	*img; // адрес картинки
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
}t_count;

typedef struct s_collect
{
	void	*img;
	int		height[100];
	int		width[100];
}t_collect;

typedef struct s_chrc
{
	void	*img;
	int		height;
	int		width;
}t_chrct;

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
	t_map		picture;
	t_img		collection;
	t_img		exit;
	t_img		wall;
	t_img		floor;
	t_img		character;
	t_chrct		chrct;
	t_count		count;
	void		*mlx;
	void		*mlx_win;
	t_collect	collect;
	// t_obj	coord;
}t_game;


#endif