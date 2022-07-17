/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:54:48 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/17 21:08:29 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_tile_to_image(t_img *img, t_tile *tile, int x, int y)
{
	char	*data_img;
	char	*data_tile;
	int		x_tile;
	int		i;
	int		addon;

	x_tile = 0;
	i = 0;
	data_img = mlx_get_data_addr(img->img, &img->bpp, &img->line_size,
			&img->endian);
	data_tile = mlx_get_data_addr(tile->tile, &tile->bpp,
			&tile->line_size, &tile->endian);
	while (*(unsigned int *)(data_tile + x_tile))
	{
		addon = (x * 4) + i + y * (img->line_size);
		*(unsigned int *)(data_img + addon) = *(unsigned int *)
			(data_tile + x_tile);
		x_tile += 4;
		i += 4;
		if (i >= tile->line_size)
		{
			i = 0;
			y++;
		}
	}
}

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
		if (i >= player->line_size)
		{
			i = 0;
			y++;
		}
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

void	render_tile_continue(char c, int x, int y, t_data *data)
{
	t_img		*img;
	static int	broom_placed;

	img = data->img;
	if ((c == 'C' && broom_placed == 0) || c == 'B')
	{
		(data->map)[y / 32][x / 32] = 'B';
		put_tile_to_image(img, img->col[1], x, y);
		broom_placed = 1;
	}
	else if (c == 'C')
		put_tile_to_image(img, img->col[0], x, y);
	if (c == 'P')
	{
		data->pos_x = x;
		data->pos_y = y;
		(data->map)[y / 32][x / 32] = '0';
		put_tile_to_image(img, img->tile, x, y);
	}
	if (c == 'E')
		put_tile_to_image(img, img->exit, x, y);
}

void	render_tile(char c, size_t i, size_t j, t_data *data)
{
	t_img	*img;
	int		x;
	int		y;

	img = data->img;
	x = j * 32;
	y = i * 32;
	if (c == '0')
		put_tile_to_image(img, img->tile, x, y);
	if (c == '1')
	{
		if (i >= 1 && (data->map)[i - 1][j] == '1')
			put_tile_to_image(img, img->wall[0], x, y);
		else
			put_tile_to_image(img, img->wall[1], x, y);
	}
	render_tile_continue(c, x, y, data);
}
