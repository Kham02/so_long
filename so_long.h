#ifndef SO_LONG_H
#define SO_LONG_H

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
// #include "gnl/get_next_line.h"
#include "so_long_utils.h"

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>


int		main(int ac, char **av);
char	error(t_game *game, char *mes);
void	destroy_img(t_game *game);
void	end_game(t_game *game);
void	free_map(t_game *game);
void	end_game(t_game *game);
void	map_valid(char *av, t_game *game);
void	init_chrct_cllc(t_game *game);
void	draw(t_game *game, int i, int n);
void	create_window(t_game *game);
void	draw_map(t_game *game);
void	right(t_game *game);
void	up(t_game *game);
void	left(t_game *game);
void	down(t_game *game);
void	key(int key, t_game *game);

#endif