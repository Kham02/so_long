#ifndef SO_LONG_H
#define SO_LONG_H

#include "libft/libft.h"
#include "gnl/get_next_line.h"

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>


int		main(int ac, char *av);
char	*error(char *mes)
void	map_valid(char *av, t_game geme);
int		check_len(char **map);

#endif