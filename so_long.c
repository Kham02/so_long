#include "so_long.h"
#include "so_long_utils.h"

int	main(int ac, char *av)
{
	t_game	game;

	if (ac != 1)
		error("invalid number of parameters");
	map_valid(av[1], game);
}