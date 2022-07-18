/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:04:34 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/17 21:15:44 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_player_tiles(t_data *data)
{
	t_tile	*player;

	player = malloc(sizeof(t_tile) * 4);
	if (!player)
		return (0);
	player[0].tile = mlx_xpm_file_to_image(data->mlx, "imgs/player/player.xpm",
			&player[0].width, &player[0].height);
	player[1].tile = mlx_xpm_file_to_image(data->mlx,
			"imgs/player/kitty_up.xpm", &player[1].width, &player[1].height);
	player[2].tile = mlx_xpm_file_to_image(data->mlx,
			"imgs/player/kitty_left.xpm", &player[2].width, &player[2].height);
	player[3].tile = mlx_xpm_file_to_image(data->mlx,
			"imgs/player/kitty_right.xpm", &player[3].width, &player[3].height);
	if (!player[0].tile || !player[1].tile
		|| !player[2].tile || !player[3].tile)
		return (free(player), 0);
	data->img->player[0] = &player[0];
	data->img->player[1] = &player[1];
	data->img->player[2] = &player[2];
	data->img->player[3] = &player[3];
	return (1);
}

int	init_player_br_tiles(t_data *data)
{
	t_tile	*player_br;

	player_br = malloc(sizeof(t_tile) * 4);
	if (!player_br)
		return (0);
	player_br[0].tile = mlx_xpm_file_to_image(data->mlx,
			"imgs/player/player_broom.xpm",
			&player_br[0].width, &player_br[0].height);
	player_br[1].tile = mlx_xpm_file_to_image(data->mlx,
			"imgs/player/kitty_up_broom.xpm",
			&player_br[1].width, &player_br[1].height);
	player_br[2].tile = mlx_xpm_file_to_image(data->mlx,
			"imgs/player/kitty_left_broom.xpm",
			&player_br[2].width, &player_br[2].height);
	player_br[3].tile = mlx_xpm_file_to_image(data->mlx,
			"imgs/player/kitty_right_broom.xpm",
			&player_br[3].width, &player_br[3].height);
	if (!player_br[0].tile || !player_br[1].tile
		|| !player_br[2].tile || !player_br[3].tile)
		return (free(player_br), 0);
	data->img->player_br[0] = &player_br[0];
	data->img->player_br[1] = &player_br[1];
	data->img->player_br[2] = &player_br[2];
	data->img->player_br[3] = &player_br[3];
	return (1);
}

int	init_col_tiles(t_data *data)
{
	t_tile	*col;

	col = malloc(sizeof(t_tile) * 2);
	if (!col)
		return (0);
	col[0].tile = mlx_xpm_file_to_image(data->mlx, "imgs/coll/col.xpm",
			&col[0].width, &col[0].height);
	col[1].tile = mlx_xpm_file_to_image(data->mlx, "imgs/coll/broom.xpm",
			&col[1].width, &col[1].height);
	if (!col[0].tile || !col[1].tile)
		return (free(col), 0);
	data->img->col[0] = &col[0];
	data->img->col[1] = &col[1];
	return (1);
}

int	init_tiles(t_data *data)
{
	t_tile	*tile;
	t_tile	*wall;
	t_tile	*exit;

	tile = malloc(sizeof(t_tile));
	wall = malloc(sizeof(t_tile) * 2);
	exit = malloc(sizeof(t_tile));
	tile->tile = mlx_xpm_file_to_image(data->mlx, "imgs/tile.xpm",
			&tile->width, &tile->height);
	exit->tile = mlx_xpm_file_to_image(data->mlx, "imgs/exit.xpm",
			&exit->width, &exit->height);
	wall[0].tile = mlx_xpm_file_to_image(data->mlx, "imgs/walls/blue.xpm",
			&wall[0].width, &wall[0].height);
	wall[1].tile = mlx_xpm_file_to_image(data->mlx, "imgs/walls/blue2.xpm",
			&wall[1].width, &wall[1].height);
	if (!wall[1].tile || !tile->tile || !wall[0].tile || !exit->tile
		|| !init_player_tiles(data) || !init_col_tiles(data)
		|| !init_player_br_tiles(data))
		return (free(tile), free(wall), free(exit), 0);
	data->img->tile = tile;
	data->img->wall[0] = &wall[0];
	data->img->wall[1] = &wall[1];
	data->img->exit = exit;
	return (1);
}
