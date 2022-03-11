/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:31:33 by estrong           #+#    #+#             */
/*   Updated: 2022/03/11 16:37:02 by estrong          ###   ########.fr       */
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
	mlx_destroy_window(game->mlx, game->mlx_win);
	free_map(game);
	free(game->mlx);
}

char	error(char *mes)
{
	write(2, mes, ft_strlen(mes));
	write(2, "\n", 1);
	exit(1);
	return(0);
}

int	end_game(t_game *game)
{
	destroy_img(game);
	exit(0);
	return (0);
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