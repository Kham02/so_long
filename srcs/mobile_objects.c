/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mobile_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:30:17 by estrong           #+#    #+#             */
/*   Updated: 2022/06/15 23:53:44 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

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
	if (game->picture.map[i][n] == 'P')
	{
		game->chrct.height = i;
		game->chrct.width = n;
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->chrct.img, n * 32, i * 32);
	}
	if (game->picture.map[i][n] == 'C')
	{
		game->collection.height = i;
		game->collection.width = n;
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->collection.img, n * 32, i * 32);
	}
}
