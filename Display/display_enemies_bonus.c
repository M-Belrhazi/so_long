/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_enemies_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:30:01 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/22 13:41:28 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_enemy_to_image(t_img *img, int x, int y, char *data_tile)
{
	char	*data_img;
	int		x_tile;
	int		addon;
	int		i;

	i = 0;
	x_tile = 0;
	data_img = mlx_get_data_addr(img->img, &img->bpp, &img->line_size,
			&img->endian);
	while (x_tile < img->enemy->line_size * 32)
	{
		addon = (x * (img->enemy->bpp / 8)) + i + y * (img->line_size);
		if (*(unsigned int *)(data_tile + x_tile) != 0x595959 &&
			*(unsigned int *)(data_tile + x_tile) != 0x414141)
			*(unsigned int *)(data_img + addon) = *(unsigned int *)
				(data_tile + x_tile);
		x_tile += (img->enemy->bpp / 8);
		i += (img->enemy->bpp / 8);
		if (i >= img->enemy->line_size && y++)
			i = 0;
	}
}

char	*create_new_data(t_tile *enemy, t_tile *new_enemy)
{
	char	*data_tile;
	char	*new_d_tile;
	int		x_tile;
	int		i;
	int		og_x;

	data_tile = mlx_get_data_addr(enemy->tile, &enemy->bpp,
			&enemy->line_size, &enemy->endian);
	new_d_tile = mlx_get_data_addr(new_enemy->tile, &new_enemy->bpp,
			&new_enemy->line_size, &new_enemy->endian);
	x_tile = enemy->x_tile * 32 * (enemy->bpp / 8);
	i = 0;
	og_x = x_tile;
	while (i < 32 * enemy->bpp * 4)
	{
		*(unsigned int *)(new_d_tile + i) = *(unsigned int *)
			(data_tile + x_tile);
		i += enemy->bpp / 8;
		x_tile += enemy->bpp / 8;
		if (i % (32 * enemy->bpp / 8) == 0)
			x_tile = og_x + (enemy->line_size * (i / (32 * enemy->bpp / 8)));
	}
	enemy->line_size = 32 * (enemy->bpp / 8);
	return (new_d_tile);
}

void	exec_move_enemy(t_data *data, int nb)
{
	if (nb == 2)
		move_enemy_up(data);
	if (nb == 3)
		move_enemy_left(data);
	if (nb == 4)
		move_enemy_down(data);
	if (nb == 5)
		move_enemy_right(data);
}

void	render_enemy_continue(t_data *data)
{
	static int	x_tile;
	static int	time;
	t_img		*img;
	t_tile		*enemy;

	time++;
	if (time % 50 == 0)
		x_tile++;
	if (x_tile == 15)
		x_tile = 0;
	data->img->enemy->x_tile = x_tile;
	img = data->img;
	enemy = img->enemy;
	put_enemy_to_image(img, data->pos_enemy_x, data->pos_enemy_y,
		create_new_data(enemy, img->new_enemy));
}

void	render_enemy(t_data *data)
{
	static int	rand_value;
	static int	time;
	int			sd_index;

	sd_index = SD1;
	if (data->img->width + data->img->width > 1000)
		sd_index = SD2;
	if (data->img->width + data->img->width > 5000)
		sd_index = SD3;
	if (time == 0 || time % 1500 == 0)
		rand_value = rand() % 5 + 1;
	if (time % sd_index == 0)
		exec_move_enemy(data, rand_value);
	render_enemy_continue(data);
	time++;
}
