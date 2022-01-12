#include "so_long.h"
#include "so_long_utils.h"

int	check_len(char **map)
{
	int	i;
	int	n;
	int len;

	len = ft_strlen(map[0]);
	n = 0;
	i = 0;
	while (map[i])
	{
		n = ft_strlen(map[i]);
		if (len != n)
			error("invalid map (length mismatch)");
		i++;
	}
	return(len);
}

static void check_wall(t_count count, char **map, int width, int height)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (map[height][n] && map[0][n] != '\n')
	{
		if (map[height][n] && map[0][n] == "0")
			error("invalid map (wall)");
		n++;
	}
	n = 0;
	while (map[i][0] && map[i][width] != NULL)
	{
		if (map[i][0] && map[i][width] == "0")
			error("invalid map (wall)");
		i++;
	}
}

static int	counter(t_game game, char *line)
{
	t_count	count;

	count = 0;
	count.start = 0;
	count.exit = 0;
	count.collect = 0;
	count.floor = 0;
	while (line[i] != '\0')
	{
		if (line[i] == "C")
			count.collect++;
		if (line[i] == "E")
			count.exit++;
		if (line[i] == "P")
			count.start++;
			if (line[i] == "0")
			count.floor++;
		i++;
	}
	if (count.collect < 1 || count.exit < 1 || count.start != 1 || count.floor < 3)
		error("invalid map (C, E, P, 0)");
	return(count);
}

void	map_valid(char *av, t_game game)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error("invalid file");
	game->picture.line1 = ft_strdup("");
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
	game->count = counter(game, game->picture.line2);
	game->picture.map = ft_split(game->picture.line2, '\n');
	free(game->picture.line2);
	game->picture.width = check_len(game->picture.map);
	check_wall(game->count, game->picture.map, game->picture.width, game->picture.height);
}