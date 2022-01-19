#include "so_long.h"
#include "so_long_utils.h"

void	destroy_img(t_game *game)
{
	mlx_destroy_images(game->mlx, game->wall.img);
	mlx_destroy_images(game->mlx, game->floor.img);
	mlx_destroy_images(game->mlx, game->collection.img);
	mlx_destroy_images(game->mlx, game->exit.img);
	mlx_destroy_images(game->mlx, game->character.img);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free_map(&game);
	free(game->mlx);
}

char	error(t_game *game, char *mes)
{
	printf("%s\n", mes);
	destroy_img(&game);
	exit(1);
	return(0);
}

void	end_game(t_game *game)
{
	destroy_img(&game);
	exit(0);
	return(0);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->picture.map[i])
	{
		free(game->picture.map[i]);
		game->picture.map[i] = NULL;
		i++;
	}
	free(game->picture.map[i]);
}