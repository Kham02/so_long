/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:31:11 by estrong           #+#    #+#             */
/*   Updated: 2022/06/15 23:54:52 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../srcs/get_next_line.h"

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../minilibx_opengl/mlx.h"

typedef struct s_img
{
	void	*img;
	int		height;
	int		width;
}t_img;

typedef struct s_count
{
	int	start;
	int	exit;
	int	collect;
	int	floor;
	int	wall;
	int	mov;
}t_count;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	char	*line1;
	char	*line2;
}t_map;

typedef struct s_game
{
	t_map	picture;
	t_img	collection;
	t_img	exit;
	t_img	wall;
	t_img	floor;
	t_img	chrct;
	t_count	count;
	void	*mlx;
	void	*mlx_win;
	int		mov;
}t_game;

int		main(int ac, char **av);
char	error(char *mes, t_game *game, int i);
void	destroy_img(t_game *game);
void	free_map(t_game *game);
int		end_game(t_game *game);
void	map_valid(char *av, t_game *game);
void	init_chrct_cllc(t_game *game);
void	draw_mobile(t_game *game, int i, int n);
void	create_window(t_game *game);
void	draw_map(t_game *game);
void	right(t_game *game);
void	up(t_game *game);
void	left(t_game *game);
void	down(t_game *game);
int		key(int key, t_game *game);
void	images(t_game *game);
void	draw(t_game *game, int i, int n);
t_img	new_img(void *mlx, char *str);
void	draw_mini(t_game *game);
void	chr_draw(t_game *game);
void	draw_chr2(t_game *game);
void	draw2(t_game *game, int i, int n);

#endif
