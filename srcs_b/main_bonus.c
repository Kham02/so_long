#include "../hdrs/so_long_bonus.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		error("Error\n invalid number of parameters", &game, 0);
	game.mlx = mlx_init();
	map_valid(av[1], &game);
	create_window(&game);
	mlx_hook(game.mlx_win, 2, (1L << 1), key, &game);
	mlx_hook(game.mlx_win, 17, (1L << 0), end_game, &game);
	mlx_hook(game.mlx_win 12, (1L << 15), mini_maker, &game);
	mlx_loop(game.mlx);
	return (0);
}