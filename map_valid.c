#include "so_long.h"
#include "so_long_utils.h"

static int	check_len(t_game *game)
{
	int	i;
	int	n;
	int len;

	len = ft_strlen(game->picture.map[0]);
	n = 0;
	i = 0;
	while (game->picture.map[i])
	{
		n = ft_strlen(game->picture.map[i]);
		if (len != n)
			error(game, "invalid map (length mismatch)");
		i++;
	}
	return(len);
}

static void check_wall(t_game *game, char **map, int width, int height)
{
	int	n;

	n = 0;
	while (map[height][n]  != '\n' && map[0][n] != '\n')
	{
		if (map[height][n] != '1' && map[0][n] != '1')
			error(&game, "invalid map (wall)");
		n++;
	}
	n = 0;
	while (map[n][0] != NULL && map[n][width] != NULL)
	{
		if (map[n][0] != '1' && map[n][width] != '1')
			error(game, "invalid map (wall)");
		n++;
	}
	if (game->picture.height == game->picture.width)
		error(&game, "not a rectangular map");
}

static int	counter(t_game *game, char *line)
{
	int	i;

	i = 0;
	game->count.start = 0;
	game->count.exit = 0;
	game->count.collect = 0;
	game->count.floor = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' || line[i] != '0' || line[i] != 'P' || line[i] != 'C' || line[i] != 'E')
			error(game, "extra objects");
		if (line[i] == 'C')
			game->count.collect++;
		if (line[i] == 'E')
			game->count.exit++;
		if (line[i] == 'P')
			game->count.start++;
		i++;
	}
	if (game->count.collect < 1 || game->count.exit < 1 || game->count.start != 1)
		error(&game, "invalid map (C, E, P, 0)");
	return(0);
}

static int	map_name(char *av)
{
	int	i;
	char	*str;

	i = 0;
	str = ft_strrchr(av[2], ".");
	s = ft_strdup(".ber");
	while (str[i] && s[i])
	{
		if (str[i] != s[i])
			return(0);
		i++;
	}
	return(1);
}

void	map_valid(char *av, t_game *game)
{
	int	fd;

	if (map_name(av) != 1)
		error(&game, "incorrect map name");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error(&game, "invalid file");
	game->picture.line1 = ft_strdup("");
	game->picture.line2 = ft_strdup("");
	game->picture.height = 0;
	while (fd)
	{
		game->picture.line1 = get_next_line(fd);
		if (game->picture.line1 == NULL)
			break;
		game->picture.line2 = g_ft_strjoin(game->picture.line2, game->picture.line1);
		free(game->picture.line1);
		game->picture.height++;
	}
	counter(&game, game->picture.line2);
	game->picture.map = ft_split(game->picture.line2, '\n');
	free(game->picture.line2);
	game->picture.width = check_len(game->picture.map);
	check_wall(&game, game->picture.map, game->picture.width, game->picture.height);
}