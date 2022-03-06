/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:31:33 by estrong           #+#    #+#             */
/*   Updated: 2022/03/06 13:31:37 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_img(t_game *game)
{
	mlx_destroy_images(game->mlx, game->wall.img);
	mlx_destroy_images(game->mlx, game->floor.img);
	mlx_destroy_images(game->mlx, game->collection.img);
	mlx_destroy_images(game->mlx, game->exit.img);
	mlx_destroy_images(game->mlx, game->character.img);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free_map(game);
	free(game->mlx);
}

char	error(t_game *game, char *mes)
{
	ft_printf("%s\n", mes);
	destroy_img(game);
	exit(1);
	return(0);
}

void	end_game(t_game *game)
{
	destroy_img(game);
	exit(0);
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