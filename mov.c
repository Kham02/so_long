/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:30:06 by estrong           #+#    #+#             */
/*   Updated: 2022/04/01 19:12:10 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key(int key, t_game *game)
{
	if (key == 53)
		end_game(game);
	if (key == 1)
		down(game);
	if (key == 13)
		up(game);
	if (key == 0)
		left(game);
	if (key == 2)
		right(game);
	return (0);
}

void	right(t_game *game)
{
	if (game->picture.map[game->chrct.height][game->chrct.width + 1] \
	== 'E' && game->count.collect == 0)
		end_game(game);
	else if (game->picture.map[game->chrct.height][game->chrct.width + 1] \
	!= '1' && game->picture.map[game->chrct.height][game->chrct.width + 1] \
	!= 'E')
	{
		if (game->picture.map[game->chrct.height][game->chrct.width + 1] == 'C')
		{
			game->count.collect--;
			game->picture.map[game->chrct.height][game->chrct.width + 1] = '0';
		}
		game->picture.map[game->chrct.height][game->chrct.width] = '0';
		game->picture.map[game->chrct.height][game->chrct.width + 1] = 'P';
		game->count.mov += 1;
		ft_putnbr_fd(game->count.mov, 1);
		write(1, "\n", 1);
		game->chrct.width += 1;
		mlx_clear_window(game->mlx, game->mlx_win);
		draw_mov(game, 1);
	}
}

void	up(t_game *game)
{
	if (game->picture.map[game->chrct.height - 1][game->chrct.width] \
	== 'E' && game->count.collect == 0)
		end_game(game);
	else if (game->picture.map[game->chrct.height - 1][game->chrct.width] \
	!= '1' && game->picture.map[game->chrct.height - 1][game->chrct.width] \
	!= 'E')
	{
		if (game->picture.map[game->chrct.height - 1][game->chrct.width] == 'C')
		{
			game->count.collect--;
			game->picture.map[game->chrct.height - 1][game->chrct.width] = '0';
		}
		game->picture.map[game->chrct.height][game->chrct.width] = '0';
		game->picture.map[game->chrct.height - 1][game->chrct.width] = 'P';
		game->count.mov += 1;
		ft_putnbr_fd(game->count.mov, 1);
		write(1, "\n", 1);
		game->chrct.height -= 1;
		mlx_clear_window(game->mlx, game->mlx_win);
		draw_mov(game, 3);
	}
}

void	left(t_game *game)
{	
	if (game->picture.map[game->chrct.height][game->chrct.width - 1] \
	== 'E' && game->count.collect == 0)
		end_game(game);
	else if (game->picture.map[game->chrct.height][game->chrct.width - 1] \
	!= '1' && game->picture.map[game->chrct.height][game->chrct.width - 1] \
	!= 'E')
	{
		if (game->picture.map[game->chrct.height][game->chrct.width - 1] == 'C')
		{
			game->count.collect--;
			game->picture.map[game->chrct.height][game->chrct.width - 1] = '0';
		}
		game->picture.map[game->chrct.height][game->chrct.width] = '0';
		game->picture.map[game->chrct.height][game->chrct.width - 1] = 'P';
		game->count.mov += 1;
		ft_putnbr_fd(game->count.mov, 1);
		write(1, "\n", 1);
		game->chrct.width -= 1;
		mlx_clear_window(game->mlx, game->mlx_win);
		draw_mov(game, 2);
	}
}

void	down(t_game *game)
{
	if (game->picture.map[game->chrct.height + 1][game->chrct.width] \
	== 'E' && game->count.collect == 0)
		end_game(game);
	else if (game->picture.map[game->chrct.height + 1][game->chrct.width] \
	!= '1' && game->picture.map[game->chrct.height + 1][game->chrct.width] \
	!= 'E')
	{
		if (game->picture.map[game->chrct.height + 1][game->chrct.width] == 'C')
		{
			game->count.collect--;
			game->picture.map[game->chrct.height + 1][game->chrct.width] = '0';
		}
		game->picture.map[game->chrct.height][game->chrct.width] = '0';
		game->picture.map[game->chrct.height + 1][game->chrct.width] = 'P';
		game->count.mov += 1;
		ft_putnbr_fd(game->count.mov, 1);
		write(1, "\n", 1);
		game->chrct.height += 1;
		mlx_clear_window(game->mlx, game->mlx_win);
		draw_mov(game, 4);
	}
}
