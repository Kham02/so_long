#include "so_long.h"
#include "so_long_utils.h"

char	*error(t_game *game, char *mes)
{
	printf("%s\n", mes);
	exit(1);
	return(0);
}

void	end_game(t_game *game)
{
	exit(0);
	return(0);
}