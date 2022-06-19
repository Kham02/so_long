/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:30:14 by estrong           #+#    #+#             */
/*   Updated: 2022/06/18 16:13:04 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long_bonus.h"

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
	if (game->count.collect < 1 || game->count.exit < 1 || \
	game->count.start != 1)
		error("Error\n invalid map (C, E, P, 0)", game, 0);
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

static void	counter(t_game *game, char *line2)
{
	int	i;

	i = 0;
	while (line2[i])
	{
		if (line2[i] == '\n')
			i++;
		if (line2[i] != '1' && line2[i] != '0' && line2[i] != 'P' \
		&& line2[i] != 'C' && line2[i] != 'E' && line2[i] != 'X')
		{
			free(game->picture.line2);
			error("Error\n extra objects", game, 0);
		}
		if (line2[i] == 'C')
			game->count.collect++;
		if (line2[i] == 'E')
			game->count.exit++;
		if (line2[i] == 'P')
			game->count.start++;
		if (line2[i] == 'X')
			game->count.enemy++;
		i++;
	}
}

static int	map_name(char *av, t_game *game)
{
	int	fd;

	if (ft_strnstr(av, ".ber", ft_strlen(av)) == NULL)
	{
		error("Error\n incorrect map name", game, 0);
		return ;
	}
	if (!fd = open(av, O_RDONLY))
		error("Error: invalid file\n", game, 0);
	if (fd < 0)
		error("Error\n invalid file", game, 0);
	game->count.start = 0;
	game->count.exit = 0;
	game->count.collect = 0;
	game->count.floor = 0;
	game->count.enemy = 0;
	return(fd);
}

void	map_valid(char *av, t_game *game)
{
	int	fd;

	fd = map_name(av, game);
	game->picture.line2 = ft_strdup("");
	game->picture.height = 0;
	while (fd)
	{
		game->picture.line1 = get_next_line(fd);
		if (game->picture.line1 == NULL)
			break ;
		game->picture.line2 = g_ft_strjoin(game->picture.line2, \
		game->picture.line1);
		free(game->picture.line1);
		game->picture.height++;
	}
	counter(game, game->picture.line2);
	game->picture.map = ft_split(game->picture.line2, '\n');
	free(game->picture.line2);
	game->picture.width = check_len(game);
	check_wall(game, game->picture.map, game->picture.width, \
	game->picture.height);
}
