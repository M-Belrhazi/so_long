/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:35:08 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/08 17:13:36 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct s_tile
{
	void	*tile;
	int		width;
	int		height;
	int		bpp;
	int		line_size;
	int		endian;
	char	*data;
}	t_tile;

typedef struct	s_img {
	void	*img;
	t_tile	*tile;
	t_tile	*player;
	t_tile	*wall;
	int		width;
	int		height;
	int		bpp;
	int		line_size;
	int		endian;
	char	*data;
}	t_img;


typedef struct s_data {
	void	*mlx;
	void	*win;
	t_img	*img;
}	t_data;
