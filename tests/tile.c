/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 03:39:43 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/08 18:03:14 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tiles(t_img *img);

int	ft_close(t_data *param)
{
	mlx_destroy_image(param->mlx, param->img->img);
	mlx_destroy_image(param->mlx, param->img->tile->tile);
	mlx_destroy_window(param->mlx, param->win);
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	exit(0);
}

int	put_tile_to_image(t_img *img, t_tile *tile, int x, int y)
{
	char	*data_img;
	char	*data_tile;
	int		x_tile = 0;
	int		i = 0;
	int		addon;

	data_img = mlx_get_data_addr(img->img, &img->bpp, &img->line_size, &img->endian);
	data_tile = mlx_get_data_addr(tile->tile, &tile->bpp, &tile->line_size, &tile->endian);
	addon = (x * 4) + i + y * (img->line_size);
	while (*(unsigned int *)(data_tile + x_tile))
	{
		addon = (x * 4) + i + y * (img->line_size);
		*(unsigned int *)(data_img + addon) = *(unsigned int *)(data_tile + x_tile);
		x_tile += 4;
		i += 4;
		if (i >= tile->line_size)
		{
			i = 0;
			y++;
		}
	}
}

int	render(t_data *param)
{
	t_img	*img;
	int		x;
	int		y;

	img = param->img;
	mlx_put_image_to_window(param->mlx, param->win, img->img, 0, 0);
	y = 0;
	x = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			put_tile_to_image(img, img->tile, x, y);
			//mlx_put_image_to_window(param->mlx, param->win, img->tile->tile, x, y);
			x += img->tile->width;
		}
		y += img->tile->height;
	}
	put_tile_to_image(img, img->player, 0, 0);
	put_tile_to_image(img, img->wall, 32, 0);
	put_tile_to_image(img, img->wall, 32, 32);
	put_tile_to_image(img, img->wall, 64, 32);
	put_tile_to_image(img, img->wall, 64, 0);
	put_tile_to_image(img, img->wall, 96, 0);
	mlx_put_image_to_window(param->mlx, param->win, img->img, 0, 0);
	return (0);
}

int	handle_keypress(int key, t_data *param)
{
	printf("key = %i\n", key);
	if (key == 65307)
		ft_close(param);
	return (0);
}

int	main(void)
{
	t_data	param;
	t_img	img;
	t_tile	tile;
	t_tile	player;
	t_tile	wall;

	/* initializing the necessary things */
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 1920, 1280, "Hola");
	img.width = 1920;
	img.height = 1280;
	img.img = mlx_new_image(param.mlx, img.width, img.height);
	tile.tile = mlx_xpm_file_to_image(param.mlx, "tile.xpm", &tile.width, &tile.height);
	player.tile = mlx_xpm_file_to_image(param.mlx, "player.xpm", &player.width, &player.height);
	wall.tile = mlx_xpm_file_to_image(param.mlx, "blue2.xpm", &wall.width, &wall.height);
	param.img = &img;
	img.tile = &tile;
	img.player = &player;
	img.wall = &wall;
	//render(&param);

	/* handling events */
	mlx_loop_hook(param.mlx, &render, &param);
	mlx_hook(param.win, 2, 1L<<0, &handle_keypress, &param);
	mlx_hook(param.win, 17, 0, &ft_close, &param);
	mlx_loop(param.mlx);

	return (0);
}
