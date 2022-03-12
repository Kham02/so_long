/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:30:24 by estrong           #+#    #+#             */
/*   Updated: 2022/03/11 19:20:57 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_game *game)
{
	int	i;
	int	n;

	i = 0;
	images(game);
	while (game->picture.map[i] != NULL)
	{
		n = 0;
		while (game->picture.map[i][n])
		{
			if (game->picture.map[i][n] == '1')
				draw(game, i, n);
			if (game->picture.map[i][n] == '0')
				draw(game, i, n);
			if (game->picture.map[i][n] == 'E')
				draw(game, i, n);
			n++;
		}
		i++;
	}
	init_chrct_cllc(game);
}

void	draw(t_game *game, int i, int n)
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
}

t_img	new_img(void *mlx, char *str)
{
	t_img	imgs;

	imgs.img = mlx_xpm_file_to_image(mlx, str, &imgs.height, &imgs.width);
	return (imgs);
}

void	images(t_game *game)
{
	game->floor = new_img(game->mlx, "img/floor.xpm");
	game->wall = new_img(game->mlx, "img/tree.xpm");
	game->exit = new_img(game->mlx, "img/portal.xpm");
	game->collection = new_img(game->mlx, "img/potion2.xpm");
	game->chrct = new_img(game->mlx, "img/right_1__.xpm");
}

void	create_window(t_game *game)
{
	game->count.mov = 0;
	game->mlx_win = mlx_new_window(game->mlx, game->picture.width * 32, \
	game->picture.height * 32, "so_long");
	draw_map(game);
}
