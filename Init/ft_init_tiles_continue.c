/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tiles_continue.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:31:02 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/22 14:32:03 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_tile(t_data *data)
{
	t_tile	*tile;

	tile = malloc(sizeof(t_tile));
	data->img->tile = tile;
	if (!tile)
		return (0);
	tile->tile = mlx_xpm_file_to_image(data->mlx, "imgs/tile.xpm",
			&tile->width, &tile->height);
	if (!tile->tile)
		return (0);
	return (data->tiles[0] = 1, 1);
}

int	init_exit(t_data *data)
{
	t_tile	*exit;

	exit = malloc(sizeof(t_tile));
	data->img->exit = exit;
	if (!exit)
		return (0);
	exit->tile = mlx_xpm_file_to_image(data->mlx, "imgs/exit.xpm",
			&exit->width, &exit->height);
	if (!exit->tile)
		return (0);
	return (data->tiles[1] = 1, 1);
}

int	init_wall(t_data *data)
{
	t_tile	*wall;

	wall = malloc(sizeof(t_tile) * 2);
	data->img->wall[0] = &wall[0];
	data->img->wall[1] = &wall[1];
	if (!wall)
		return (data->tiles[2] = 0, data->tiles[3] = 0, 0);
	wall[0].tile = mlx_xpm_file_to_image(data->mlx, "imgs/walls/blue.xpm",
			&wall[0].width, &wall[0].height);
	wall[1].tile = mlx_xpm_file_to_image(data->mlx, "imgs/walls/blue2.xpm",
			&wall[1].width, &wall[1].height);
	if (wall[0].tile)
		data->tiles[2] = 1;
	if (wall[1].tile)
		data->tiles[3] = 1;
	if (!wall[0].tile || !wall[1].tile)
		return (0);
	return (1);
}

int	init_col(t_data *data)
{
	t_tile	*col;

	col = malloc(sizeof(t_tile) * 2);
	data->img->col[0] = &col[0];
	data->img->col[1] = &col[1];
	if (!col)
		return (data->tiles[4] = 0, data->tiles[5] = 0, 0);
	col[0].tile = mlx_xpm_file_to_image(data->mlx, "imgs/coll/col.xpm",
			&col[0].width, &col[0].height);
	col[1].tile = mlx_xpm_file_to_image(data->mlx, "imgs/coll/broom.xpm",
			&col[1].width, &col[1].height);
	if (col[0].tile)
		data->tiles[4] = 1;
	if (col[1].tile)
		data->tiles[5] = 1;
	if (!col[0].tile || !col[1].tile)
		return (0);
	return (1);
}
