#include "so_long.h"
#include "so_long_utils.h"

void	init_chrct_cllc(t_game *game)
{
	int	i;
	int	n;

	i = 0;
	while (game->picture.map[i])
	{
		n = 0;
		while (game->picture.map[i][n])
		{
			if (game->picture.map[i][n] == "P")
				draw(&game, i, n);
			if (game->picture.map[i][n] == "C")
				draw(&game, i, n);
			n++;
		}
		i++;
	}
}

void	draw(t_game *game, int i, int n)
{
	int	kol;

	kol = 0;
	if (game->picture.map[i][n] == "P")
	{
		game->chrct.height = i;
		game->chrct.width = n;
		game->chrct.img = mlx_xpm_file_to_image(game->mlx, "", i, n);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->chrct, n, int i);
	}
	if (game->picture.map[i][n] == "C")
	{
		game->collect.height[kol] = i;
		game->collect.width[kol] = n;
		game->collect.img = mlx_xpm_file_to_image(game->mlx, "", i, n);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->collection, n, int i);
	}
	kol++;
}