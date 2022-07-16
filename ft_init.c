/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:04:34 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/14 19:08:28 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_tiles(t_data *data)
{
	t_tile	*tile;
	t_tile	*wall;
	t_tile	*player;
	t_tile	*exit;
	t_tile	*col;

	tile = malloc(sizeof(t_tile));
	wall = malloc(sizeof(t_tile) * 2);
	player = malloc(sizeof(t_tile));
	exit = malloc(sizeof(t_tile));
	col = malloc(sizeof(t_tile));
	tile->tile = mlx_xpm_file_to_image(data->mlx, "imgs/tile.xpm",
			&tile->width, &tile->height);
	if (!tile->tile)
		return (free(tile), free(wall), free(player), free(exit), free(col), 0);
	player->tile = mlx_xpm_file_to_image(data->mlx, "imgs/player/player.xpm",
			&player->width, &player->height);
	if (!player->tile)
		return (free(tile), free(wall), free(player), free(exit), free(col), 0);
	exit->tile = mlx_xpm_file_to_image(data->mlx, "imgs/exit.xpm",
			&exit->width, &exit->height);
	if (!exit->tile)
		return (free(tile), free(wall), free(player), free(exit), free(col), 0);
	col->tile = mlx_xpm_file_to_image(data->mlx, "imgs/coll/col.xpm",
			&col->width, &col->height);
	if (!col->tile)
		return (free(tile), free(wall), free(player), free(exit), free(col), 0);
	wall[0].tile = mlx_xpm_file_to_image(data->mlx, "imgs/walls/blue2.xpm",
			&wall[0].width, &wall[0].height);
	if (!wall[0].tile)
		return (free(tile), free(wall), free(player), free(exit), free(col), 0);
	wall[1].tile = mlx_xpm_file_to_image(data->mlx, "imgs/walls/blue.xpm",
			&wall[1].width, &wall[1].height);
	if (!wall[1].tile)
		return (free(tile), free(wall), free(player), free(exit), free(col), 0);
	data->img->tile = tile;
	data->img->wall1 = &wall[0];
	data->img->wall2 = &wall[1];
	data->img->player = player;
	data->img->exit = exit;
	data->img->col = col;
	return (1);
}
