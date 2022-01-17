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
}t_count;

typedef struct s_character
{
	int	x;
	int	y;
}t_character;

// typedef struct s_obj
// {
// 	int	x[100];
// 	int	y[100];
// }t_obj;


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
	t_img		start;
	t_img		exit;
	t_img		wall;
	t_img		floor;
	t_img		chrct;
	t_character	character;
	t_count		count;
	void		*mlx;
	// t_obj		coord;
}t_game;


#endif