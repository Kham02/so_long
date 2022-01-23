#include "so_long.h"

void	key(int key, t_game *game)
{
	if (key == 53)
		end_game(&game);
	if (key == 1)
		down(&game);
	if (key == 13)
		up(&game);
	if (key == 0)
		left(&game);
	if (key == 2)
		right(&game);
}

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
		game->picture.map[game->chrct.height][game->chrct.width] = "0";
		game->count.mov += 1;
		game->chrct.width += 1;
		mlx_clear_window(game->mlx, game->mlx_win);
		draw_map(&game);
	}
}

void	up(t_game *game)
{
	if (game->picture.map[game->chrct.height - 1][game->chrct.width] != "1")
	{
		if (game->picture.map[game->chrct.height - 1][game->chrct.width] == "E")
			end_game(&game);
		if (game->picture.map[game->chrct.height][game->chrct.width + 1] == "C")
		{
			game->count.collect--;
			game->picture.map[game->chrct.height][game->chrct.width + 1] = "0";
		}
		game->picture.map[game->chrct.height][game->chrct.width] = "0";
		game->count.mov += 1;
		game->chrct.height -= 1;
		mlx_clear_window(game->mlx, game->mlx_win);
		draw_map(&game);
	}
}

void	left(t_game *game)
{
	if (game->picture.map[game->chrct.height][game->chrct.width - 1] != "1")
	{
		if (game->picture.map[game->chrct.height][game->chrct.width - 1] == "E")
			end_game(&game);
		if (game->picture.map[game->chrct.height][game->chrct.width + 1] == "C")
		{
			game->count.collect--;
			game->picture.map[game->chrct.height][game->chrct.width + 1] = "0";
		}
		game->picture.map[game->chrct.height][game->chrct.width] = "0";
		game->count.mov += 1;
		game->chrct.width -= 1;
		mlx_clear_window(game->mlx, game->mlx_win);
		draw_map(&game);
	}
}

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
		game->picture.map[game->chrct.height][game->chrct.width] = "0";
		game->count.mov += 1;
		game->chrct.height += 1;
		mlx_clear_window(game->mlx, game->mlx_win);
		draw_map(&game);
	}
}