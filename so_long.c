/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:30:28 by estrong           #+#    #+#             */
/*   Updated: 2022/04/01 19:14:25 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (ac != 2)
		error("Error\n invalid number of parameters");
	game->mlx = mlx_init();
	map_valid(av[1], game);
	create_window(game);
	mlx_hook(game->mlx_win, 2, (1L << 1), key, game);
	mlx_hook(game->mlx_win, 17, (1L << 0), end_game, game);
	mlx_loop(game->mlx);
	return (0);
}
