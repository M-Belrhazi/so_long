/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:30:01 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/17 21:34:01 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_player_to_image(t_img *img, int x, int y, t_tile *player)
{
	char	*data_img;
	char	*data_tile;
	int		x_tile;
	int		addon;
	int		i;

	i = 0;
	x_tile = 0;
	data_img = mlx_get_data_addr(img->img, &img->bpp, &img->line_size,
			&img->endian);
	data_tile = mlx_get_data_addr(player->tile, &player->bpp,
			&player->line_size, &player->endian);
	while (*(unsigned int *)(data_tile + x_tile))
	{
		addon = (x * (player->bpp / 8)) + i + y * (img->line_size);
		if (*(unsigned int *)(data_tile + x_tile) != 0x595959 &&
			*(unsigned int *)(data_tile + x_tile) != 0x414141)
			*(unsigned int *)(data_img + addon) = *(unsigned int *)
				(data_tile + x_tile);
		x_tile += (player->bpp / 8);
		i += (player->bpp / 8);
		if (i >= player->line_size && y++)
			i = 0;
	}
}

void	render_player_br(t_data *data)
{
	t_tile	*player;

	if (data->down[0] == 1)
		player = data->img->player_br[1];
	else if (data->down[1] == 1)
		player = data->img->player_br[2];
	else if (data->down[2] == 1)
		player = data->img->player_br[0];
	else if (data->down[3] == 1)
		player = data->img->player_br[3];
	else
		player = data->img->player_br[0];
	put_player_to_image(data->img, data->pos_x, data->pos_y, player);
}

void	render_player(t_data *data)
{
	t_tile	*player;

	if (data->broom == 1)
	{
		render_player_br(data);
		return ;
	}
	if (data->down[0] == 1)
		player = data->img->player[1];
	else if (data->down[1] == 1)
		player = data->img->player[2];
	else if (data->down[2] == 1)
		player = data->img->player[0];
	else if (data->down[3] == 1)
		player = data->img->player[3];
	else
		player = data->img->player[0];
	put_player_to_image(data->img, data->pos_x, data->pos_y, player);
}
