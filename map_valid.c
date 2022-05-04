/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:30:14 by estrong           #+#    #+#             */
/*   Updated: 2022/05/04 18:46:04 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_len(t_game *game)
{
	int	i;
	int	n;
	int	len;

	len = ft_strlen(game->picture.map[0]);
	n = 0;
	i = 0;
	while (game->picture.map[i])
	{
		n = ft_strlen(game->picture.map[i]);
		if (len != n)
			error("Error\n invalid map (length mismatch)", game, 1);
		i++;
	}
	return (len);
}

static void	check_wall(t_game *game, char **map, int width, int height)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (n < width && map[i][n] != '\0')
	{
		if (map[height - 1][n] != '1' || map[0][n] != '1')
			error("Error\n invalid map (wall)", game, 1);
		n++;
	}
	n = 0;
	while (n < height && map[i][n] != '\0')
	{
		if (map[n][0] != '1' || map[n][width - 1] != '1')
			error("Error\n invalid map (wall)", game, 1);
		n++;
	}
	if (game->picture.height == game->picture.width)
		error("Error\n not a rectangular map", game, 1);
}

static void	counter(t_game *game)
{
	int	i;

	i = 0;
	game->count.start = 0;
	game->count.exit = 0;
	game->count.collect = 0;
	game->count.floor = 0;
	while (game->picture.line2[i++])
	{
		if (game->picture.line2[i] == '\n')
			i++;
		if (game->picture.line2[i] != '1' && game->picture.line2[i] != '0' && \
		game->picture.line2[i] != 'P' && game->picture.line2[i] != 'C' \
		&& game->picture.line2[i] != 'E')
			error("Error\n extra objects", game, 0);
		if (game->picture.line2[i] == 'C')
			game->count.collect++;
		if (game->picture.line2[i] == 'E')
			game->count.exit++;
		if (game->picture.line2[i] == 'P')
			game->count.start++;
	}
	if (game->count.collect < 1 || game->count.exit < 1 || \
	game->count.start != 1)
		error("Error\n invalid map (C, E, P, 0)", game, 0);
}

static void	map_name(char *av, t_game *game)
{
	if (ft_strnstr(av, ".ber", ft_strlen(av)) == NULL)
	{
		error("Error\n incorrect map name", game, 0);
		return ;
	}
}

void	map_valid(char *av, t_game *game)
{
	int	fd;

	map_name(av, game);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		error("Error\n invalid file", game, 0);
	game->picture.line1 = ft_strdup("");
	game->picture.line2 = ft_strdup("");
	game->picture.height = 0;
	while (fd >= 0)
	{
		game->picture.line1 = get_next_line(fd);
		if (game->picture.line1 == NULL)
			break ;
		game->picture.line2 = ft_strjoin(game->picture.line2, \
		game->picture.line1);
		free(game->picture.line1);
		game->picture.height++;
	}
	counter(game);
	game->picture.map = ft_split(game->picture.line2, '\n');
	free(game->picture.line2);
	game->picture.width = check_len(game);
	check_wall(game, game->picture.map, game->picture.width, \
	game->picture.height);
}
