/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:29:54 by estrong           #+#    #+#             */
/*   Updated: 2022/06/15 23:53:41 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

void	draw_mini(t_game *game)
{
	int	i;
	int	n;

	i = 0;
	while (game->picture.map[i] != NULL)
	{
		n = 0;
		while (game->picture.map[i][n])
		{
			if (game->picture.map[i][n] == '1')
				draw2(game, i, n);
			if (game->picture.map[i][n] == '0')
				draw2(game, i, n);
			if (game->picture.map[i][n] == 'E')
				draw2(game, i, n);
			if (game->picture.map[i][n] == 'C')
				draw2(game, i, n);
			if (game->picture.map[i][n] == 'P')
				draw2(game, i, n);
			n++;
		}
		i++;
	}
}

void	draw2(t_game *game, int i, int n)
{
	if (game->picture.map[i][n] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall.img, \
		n * 32, i * 32);
	if (game->picture.map[i][n] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor.img, \
		n * 32, i * 32);
	if (game->picture.map[i][n] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit.img, \
		n * 32, i * 32);
	if (game->picture.map[i][n] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->collection.img, n * 32, i * 32);
		game->collection.height = i;
		game->collection.width = n;
	}
	if (game->picture.map[i][n] == 'P')
	{
		draw_chr2(game);
		game->chrct.height = i;
		game->chrct.width = n;
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->chrct.img, n * 32, i * 32);
	}
}

void	draw_chr2(t_game *game)
{
	mlx_destroy_image(game->mlx, game->chrct.img);
	if (game->mov == 3)
		game->chrct.img = mlx_xpm_file_to_image(game->mlx, "img/down.xpm", \
		&game->chrct.height, &game->chrct.width);
	else if (game->mov == 2)
		game->chrct.img = mlx_xpm_file_to_image(game->mlx, "img/left.xpm", \
		&game->chrct.height, &game->chrct.width);
	else if (game->mov == 1)
		game->chrct.img = mlx_xpm_file_to_image(game->mlx, "img/up.xpm", \
		&game->chrct.height, &game->chrct.width);
	else
		game->chrct.img = mlx_xpm_file_to_image(game->mlx, "img/right.xpm", \
		&game->chrct.height, &game->chrct.width);
}
