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

