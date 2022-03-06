/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mobile_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:30:17 by estrong           #+#    #+#             */
/*   Updated: 2022/03/06 14:15:14 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_chrct_cllc(t_game *game)
{
	int	i;
	int	n;

	i = 0;
	while (game->picture.map[i])
	{
		n = 0;
		while (game->picture.map[i][n])
		{
			if (game->picture.map[i][n] == 'P')
				draw_mobile(game, i, n);
			if (game->picture.map[i][n] == 'C')
				draw_mobile(game, i, n);
			n++;
		}
		i++;
	}
}

void	draw_mobile(t_game *game, int i, int n)
{
	int	height;
	int	width;
	int	kol;

	kol = 0;
	if (game->picture.map[i][n] == 'P')
	{
		game->chrct.height = i;
		game->chrct.width = n;
		game->chrct.img = mlx_xpm_file_to_image(game->mlx, "img/player_01.xpm", &width, &height);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->chrct.img, n * 35, i * 35);
	}
	if (game->picture.map[i][n] == 'C')
	{
		game->collection.height = i;
		game->collection.width = n;
		game->collection.img = mlx_xpm_file_to_image(game->mlx, "img/plant_03.xpm", &width, &height);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->collection.img, n * 35, i * 35);
	}
	kol++;
}
