#include "so_long.h"
#include "so_long_utils.h"

void	create_window(t_game game)
{	
	game->mlx_win = mlx_new_window(mlx, game->picture.width * 35, game->picture.height * 35, "so_long");

}