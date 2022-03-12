/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:31:14 by estrong           #+#    #+#             */
/*   Updated: 2022/03/11 19:23:44 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_UTILS_H
# define SO_LONG_UTILS_H

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
}t_game;

#endif