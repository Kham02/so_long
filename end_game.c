/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:31:33 by estrong           #+#    #+#             */
/*   Updated: 2022/05/04 18:44:19 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall.img);
	mlx_destroy_image(game->mlx, game->floor.img);
	mlx_destroy_image(game->mlx, game->collection.img);
	mlx_destroy_image(game->mlx, game->exit.img);
	mlx_destroy_image(game->mlx, game->chrct.img);
}

char	error(char *mes, t_game *game, int i)
{
	if (game->picture.line1)
		free(game->picture.line1);
	if (game->picture.line2)
		free(game->picture.line2);
	write(2, mes, ft_strlen(mes));
	write(2, "\n", 1);
	if (i != 0)
		free_map(game);
	free(game);
	game = NULL;
	exit(1);
}

int	end_game(t_game *game)
{
	destroy_img(game);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free(game->mlx);
	free_map(game);
	free(game);
	game = NULL;
	exit(0);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->picture.height)
	{
		free(game->picture.map[i]);
		game->picture.map[i] = NULL;
		i++;
	}
	free(game->picture.map);
	game->picture.map = NULL;
}
