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
				game->character.height = i;
				game->character.width = n;
				game->character.img = mlx_xpm_file_to_image(mlx, "", &img.height, &img.width);
			}
			n++;
		}
		i++;
	}
}
