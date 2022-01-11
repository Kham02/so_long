#ifndef SO_LONG_UTILS_H
#define SO_LONG_UTILS_H

typedef struct s_img
{
	int	x;
	int	y;
	int	size;
	
}t_img;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	char	*len;
}t_map;


typedef struct s_game
{
	t_map	picture;
	t_img	collection;
	t_img	start;
	t_img	exit;
	t_img	wall;
	t_img	floor;
	t_img	character;
}t_game;


#endif