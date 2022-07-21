/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player_tiles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:31:52 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/21 23:44:16 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_player_continue(t_data *data, t_tile *player)
{
	player[0].tile = mlx_xpm_file_to_image(data->mlx, "imgs/player/player.xpm",
			&player[0].width, &player[0].height);
	if (player[0].tile)
		data->tiles[8] = 1;
	player[1].tile = mlx_xpm_file_to_image(data->mlx,
			"imgs/player/kitty_up.xpm", &player[1].width, &player[1].height);
	if (player[1].tile)
		data->tiles[9] = 1;
	player[2].tile = mlx_xpm_file_to_image(data->mlx,
			"imgs/player/kitty_left.xpm", &player[2].width, &player[2].height);
	if (player[2].tile)
		data->tiles[10] = 1;
	player[3].tile = mlx_xpm_file_to_image(data->mlx,
			"imgs/player/kitty_right.xpm", &player[3].width, &player[3].height);
	if (player[3].tile)
		data->tiles[11] = 1;
	if (!player[0].tile || !player[1].tile
		|| !player[2].tile || !player[3].tile)
		return (0);
	return (1);
}

int	init_player(t_data *data)
{
	t_tile	*player;

	player = malloc(sizeof(t_tile) * 4);
	data->img->player[0] = &player[0];
	data->img->player[1] = &player[1];
	data->img->player[2] = &player[2];
	data->img->player[3] = &player[3];
	if (!player)
		return (0);
	return (init_player_continue(data, player));
}

int	init_player_br_continue(t_data *data, t_tile *player_br)
{
	player_br[0].tile = mlx_xpm_file_to_image(data->mlx,
			"imgs/player/player_broom.xpm",
			&player_br[0].width, &player_br[0].height);
	if (player_br[0].tile)
		data->tiles[12] = 1;
	player_br[1].tile = mlx_xpm_file_to_image(data->mlx,
			"imgs/player/kitty_up_broom.xpm",
			&player_br[1].width, &player_br[1].height);
	if (player_br[1].tile)
		data->tiles[13] = 1;
	player_br[2].tile = mlx_xpm_file_to_image(data->mlx,
			"imgs/player/kitty_left_broom.xpm",
			&player_br[2].width, &player_br[2].height);
	if (player_br[2].tile)
		data->tiles[14] = 1;
	player_br[3].tile = mlx_xpm_file_to_image(data->mlx,
			"imgs/player/kitty_right_broom.xpm",
			&player_br[3].width, &player_br[3].height);
	if (player_br[3].tile)
		data->tiles[15] = 1;
	if (!player_br[0].tile || !player_br[1].tile
		|| !player_br[2].tile || !player_br[3].tile)
		return (0);
	return (1);
}

int	init_player_br(t_data *data)
{
	t_tile	*player_br;

	player_br = malloc(sizeof(t_tile) * 4);
	data->img->player_br[0] = &player_br[0];
	data->img->player_br[1] = &player_br[1];
	data->img->player_br[2] = &player_br[2];
	data->img->player_br[3] = &player_br[3];
	if (!player_br)
		return (0);
	return (init_player_br_continue(data, player_br));
}
