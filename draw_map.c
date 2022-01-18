#include "so_long.h"
#include "so_long_utils.h"

void	draw_map(t_game game)
{
	int	i;
	int	n;

	i = 0;
	while (game->picture.map[i] != NULL)
	{
		n = 0;
		while (game->picture.map[i][n])
		{
			if (game->picture.map[i][n] == "1")
				draw_wall(game);
			if (game->picture.map[i][n] == "0")
				draw_floor(game);
			if (game->picture.map[i][n] == "C")
				draw_collect(game);
			if (game->picture.map[i][n] == "E")
				draw_exit(game);
			n++;
		}
		i++;
	}
}

void	new_img(void *mlx, char *str)
{
	t_img	imgs;

	imgs = mlx_xpm_file_to_image(mlx, str, &img.height, &img.width);
	return (imgs);
}

void	images(t_game game)
{
	game->collection = new_img(mlx, "");
	game->floor = new_img(mlx, "");
	game->wall = new_img(mlx, "");
	game->exit = new_img(mlx, "");
	game->chrct = new_img(mlx, "");
}
