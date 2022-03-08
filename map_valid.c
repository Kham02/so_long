/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:30:14 by estrong           #+#    #+#             */
/*   Updated: 2022/03/08 21:02:59 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int check_len(t_game *game)
{
	int i;
	int n;
	int len;

	len = ft_strlen(game->picture.map[0]);
	n = 0;
	i = 0;
	while (game->picture.map[i])
	{
		n = ft_strlen(game->picture.map[i]);
		if (len != n)
			error("Error\n invalid map (length mismatch)");
		i++;
	}
	return (len);
}

static void check_wall(t_game *game, char **map, int width, int height)
{
	int n;

	n = 0;
	while (map[height][n] != '\n' && map[0][n] != '\n')
	{
		if (map[height][n] != '1' && map[0][n] != '1')
			error("Error\n invalid map (wall)");
		n++;
	}
	n = 0;
	while (map[n][0] && map[n][width])
	{
		if (map[n][0] != '1' && map[n][width] != '1')
			error("Error\n invalid map (wall)");
		n++;
	}
	if (game->picture.height == game->picture.width)
		error("Error\n not a rectangular map");
}

static int counter(t_game *game, char **map)
{
	int	i;
	int	n;

	i = 0;
	game->count.start = 0;
	game->count.exit = 0;
	game->count.collect = 0;
	game->count.floor = 0;
	while (map[i])
	{
		while (map[i][n])
		{
			n = 0;
			if (map[i][n] != '1' && map[i][n] != '0' && map[i][n] != 'P' && map[i][n] != 'C' && map[i][n] != 'E')
				error("Error\n extra objects");
			if (map[i][n] == 'C')
				game->count.collect++;
			if (map[i][n] == 'E')
				game->count.exit++;
			if (map[i][n] == 'P')
				game->count.start++;
		}
		i++;
	}
	if (game->count.collect < 1 || game->count.exit < 1 || game->count.start != 1)
		error("Error\n invalid map (C, E, P, 0)");
	return (0);
}

static void map_name(char *av)
{
	if (ft_strnstr(av, ".ber", ft_strlen(av)) == NULL)
	{
		printf("%s", av);
		error("Error\n incorrect map name");
		return ;
	}
}

void map_valid(char *av, t_game *game)
{
	int fd;

	map_name(av);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		error("Error\n invalid file");
	game->picture.line1 = ft_strdup("");
	game->picture.line2 = ft_strdup("");
	game->picture.height = 0;
	while (fd)
	{
		game->picture.line1 = get_next_line(fd);
		if (game->picture.line1 == NULL)
			break;
		game->picture.line2 = ft_strjoin(game->picture.line2, game->picture.line1);
		free(game->picture.line1);
		game->picture.height++;
	}
	game->picture.map = ft_split(game->picture.line2, '\n');
	counter(game, game->picture.map);
	free(game->picture.line2);
	game->picture.width = check_len(game);
	check_wall(game, game->picture.map, game->picture.width, game->picture.height);
}