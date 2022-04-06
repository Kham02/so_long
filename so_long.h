/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:31:11 by estrong           #+#    #+#             */
/*   Updated: 2022/03/11 19:22:29 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "get_next_line.h"

# include "so_long_utils.h"

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

int		main(int ac, char **av);
char	error(char *mes);
void	destroy_img(t_game *game);
void	free_map(t_game *game);
int		end_game(t_game *game);
void	map_valid(char *av, t_game *game);
// void	init_chrct_cllc(t_game *game);
// void	draw_mobile(t_game *game, int i, int n);
void	create_window(t_game *game);
// void	draw_map(t_game *game);
void	right(t_game *game);
void	up(t_game *game);
void	left(t_game *game);
void	down(t_game *game);
int		key(int key, t_game *game);
void	images(t_game *game, int m);
// void	draw(t_game *game, int i, int n);
// t_img	new_img(void *mlx, char *str);

void	draw_mov(t_game *game, int m);
void	draw_map_mov(t_game *game, int i, int n);
t_img	new_img_mov(void *mlx, char *str);


#endif
