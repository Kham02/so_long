#include "../hdrs/so_long_bonus.h"

int	key(int key, t_game *game)
{
	game->mov = 0;
	if (key == 53)
		end_game(game);
	else if (key == 1)
		down(game);
	else if (key == 13)
		up(game);
	else if (key == 0)
		left(game);
	else if (key == 2)
		right(game);
	return (0);
}

