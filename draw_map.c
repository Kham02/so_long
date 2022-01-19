#include "so_long.h"
#include "so_long_utils.h"

static void	draw_map(t_game *game)
{
	int	i;
	int	n;

	i = 0;
	images(&game);
	while (game->picture.map[i] != NULL)
	{
		n = 0;
		while (game->picture.map[i][n])
		{
			if (game->picture.map[i][n] == "1")
				draw(&game, i, n);
			if (game->picture.map[i][n] == "0")
				draw(&game i, n);
			if (game->picture.map[i][n] == "E")
				draw(&game i, n);
			n++;
		}
		i++;
	}
}

static void	draw(t_game *game, int i, int n)
{
	if (game->picture.map[i][n] == "1")
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, n, int i);
	if (game->picture.map[i][n] == "0")
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor, n, int i);
	if (game->picture.map[i][n] == "E")
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit, n, int i);
	init_chrct_cllc(&game);
}
static t_img	new_img(void *mlx, char *str)
{
	t_img	imgs;

	imgs = mlx_xpm_file_to_image(mlx, str, &img.height, &img.width);
	return (imgs);
}

static void	images(t_game *game)
{
	game->collection = new_img(mlx, "");
	game->floor = new_img(mlx, "");
	game->wall = new_img(mlx, "");
	game->exit = new_img(mlx, "");
	game->chrct = new_img(mlx, "");
}

void	create_window(t_game *game)
{	
	game->mlx_win = mlx_new_window(game->mlx, game->picture.width * 35, game->picture.height * 35, "so_long");
	draw_map(&game);
}