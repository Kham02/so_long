#ifndef SO_LONG_UTILS_H
#define SO_LONG_UTILS_H

typedef struct s_vector
{
	int	x;
	int	y;
}t_vector;

typedef struct s_img
{
	/* data */
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
	t_vector	position;
	t_map		picture;
	
};


#endif