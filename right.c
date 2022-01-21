#include "so_long.h"
#include "so_long_utils.h"

void	right(t_game *game)
{
	if (game->picture.map[game->chrct.height][game->chrct.width + 1] != "1")
	{
		if (game->picture.map[game->chrct.height][game->chrct.width + 1] == "E" && game->count.collect == '0')
			end_game(&game);
		if (game->picture.map[game->chrct.height][game->chrct.width + 1] == "C")
		{
			game->count.collect--;
			game->picture.map[game->chrct.height][game->chrct.width + 1] = "0";
		}
		game->count.mov += 1;
		game->chrct.width += 1;
		draw_map(&game);
	}
}