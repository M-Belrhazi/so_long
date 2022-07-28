/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tiles_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:54:48 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/28 14:52:35 by mbelrhaz         ###   ########.fr       */
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
	while (x_tile < tile->line_size * 32)
	{
		addon = (x * (tile->bpp / 8)) + i + y * (img->line_size);
		if (*(unsigned int *)(data_img + addon) != *(unsigned int *)
			(data_tile + x_tile))
			*(unsigned int *)(data_img + addon) = *(unsigned int *)
				(data_tile + x_tile);
		x_tile += (tile->bpp / 8);
		i += (tile->bpp / 8);
		if (i >= tile->line_size && y++)
			i = 0;
	}
}

void	render_broom(int x, int y, t_img *img, t_data *data)
{
	int			tiles[4];
	static int	time;
	static int	tile;
	static int	i;

	tiles[0] = 1;
	tiles[1] = 2;
	tiles[2] = 1;
	tiles[3] = 3;
	tile = tiles[i];
	time++;
	if (time % (int)(data->anim) == 0)
	{
		i++;
		if (i == 4)
			i = 0;
		tile = tiles[i];
	}
	put_tile_to_image(img, img->col[tile], x, y);
}

void	render_tile_continue(char c, int x, int y, t_data *data)
{
	t_img		*img;
	static int	broom_placed;

	img = data->img;
	if ((c == 'C' && broom_placed == 0) || c == 'B')
	{
		(data->map)[(y / 32) - 1][x / 32] = 'B';
		render_broom(x, y, img, data);
		broom_placed = 1;
	}
	else if (c == 'C')
		put_tile_to_image(img, img->col[0], x, y);
	if (c == 'P')
	{
		data->pos_x = x;
		data->pos_y = y;
		(data->map)[(y / 32) - 1][x / 32] = '0';
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
	y = (i + 1) * 32 ;
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
