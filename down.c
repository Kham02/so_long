#include "so_long.h"
#include "so_long_utils.h"

void	down(t_game *game)
{
	if (game->picture.map[game->chrct.height + 1][game->chrct.width] != "1")
	{
		if (game->picture.map[game->chrct.height + 1][game->chrct.width] == "E")
			end_game(&game);
		if (game->picture.map[game->chrct.height][game->chrct.width + 1] == "C")
		{
			game->count.collect--;
			game->picture.map[game->chrct.height][game->chrct.width + 1] = "0";
		}
		game->count.mov += 1;
		game->chrct.height += 1;
		draw_map(&game);
	}
}