#ifndef SO_LONG_H
#define SO_LONG_H

#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>


int		main(int ac, char *av);
char	error(t_game *game, char *mes);
void	destroy_img(t_game *game);
void	end_game(t_game *game);
void	free_map(t_game *game);
void	map_valid(char *av, t_game *game);
void	init_chrct_cllc(t_game *game);
void	end_game(t_game *game);
void	create_window(t_game *game);


#endif