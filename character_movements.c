#include "so_long.h"
#include "so_long_utils.h"

void	init_character(t_game game)
{
	int	i;
	int	n;

	i = 0;
	while (game->picture.map[i])
	{
		n = 0;
		while (game->picture.map[i][n])
		{
			if (game->picture.map[i][n] == "P")
			{
				game->character.y = i;
				game->character.x = n;
				
			}
			n++;
		}
		i++;
	}
}

void	chr_left()
{

}

void	chr_right()
{

}

void	chr_up()
{

}

void	chr_down()
{
	
}