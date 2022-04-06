#include "so_long.h"

void	draw_mov(t_game *game, int m)
{
	int	i;
	int	n;

	i = 0;
	images(game, m);
	while (game->picture.map[i] != NULL)
	{
		n = 0;
		while (game->picture.map[i][n])
		{
			if (game->picture.map[i][n] == '1')
				draw_map_mov(game, i, n);
			if (game->picture.map[i][n] == '0')
				draw_map_mov(game, i, n);
			if (game->picture.map[i][n] == 'E')
				draw_map_mov(game, i, n);
			if (game->picture.map[i][n] == 'P')
				draw_map_mov(game, i, n);
			if (game->picture.map[i][n] == 'C')
				draw_map_mov(game, i, n);
			n++;
		}
		i++;
	}
	// init_chrct_cllc(game);
}

void	draw_map_mov(t_game *game, int i, int n)
{
	if (game->picture.map[i][n] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall.img, \
		n * 32, i * 32);
	if (game->picture.map[i][n] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor.img, \
		n * 32, i * 32);
	if (game->picture.map[i][n] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit.img, \
		n * 32, i * 32);
	if (game->picture.map[i][n] == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->chrct.img, \
		n * 32, i * 32);
	if (game->picture.map[i][n] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->collection.img, \
		n * 32, i * 32);
}

t_img	new_img_mov(void *mlx, char *str)
{
	t_img	imgs;

	imgs.img = mlx_xpm_file_to_image(mlx, str, &imgs.height, &imgs.width);
	return (imgs);
}

void	images(t_game *gamen int m)
{
	game->floor = new_img(game->mlx, "img/floor.xpm");
	game->wall = new_img(game->mlx, "img/tree.xpm");
	game->exit = new_img(game->mlx, "img/portal.xpm");
	game->collection = new_img(game->mlx, "img/potion2.xpm");
	if (m == 1)
		game->chrct = new_img(game->mlx, "img/right.xpm");
	else if (m == 2)
		game->chrct = new_img(game->mlx, "img/left.xpm");
	else if (m == 3)
		game->chrct = new_img(game->mlx, "img/up.xpm");
	else if (m == 4)
		game->chrct = new_img(game->mlx, "img/down.xpm");
}

void	create_window(t_game *game)
{
	game->count.mov = 0;
	game->mlx_win = mlx_new_window(game->mlx, game->picture.width * 32, \
	game->picture.height * 32, "so_long");
	draw_mov(game);
}