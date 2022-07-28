/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_enemy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:24:36 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/27 17:17:58 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_enemy_up(t_data *data)
{
	float	pix;

	pix = data->pix;
	if (data->pos_enemy_y - pix >= 0
		&& !no_move(data, data->pos_enemy_x, data->pos_enemy_y - pix))
	{
		data->pos_enemy_y -= pix;
		lose_game(data, data->pos_x, data->pos_y);
	}
}

void	move_enemy_down(t_data *data)
{
	float	pix;

	pix = data->pix;
	if (data->pos_enemy_y + 31 + pix < data->img->height
		&& !no_move(data, data->pos_enemy_x, data->pos_enemy_y + pix))
	{
		data->pos_enemy_y += pix;
		lose_game(data, data->pos_x, data->pos_y);
	}
}

void	move_enemy_right(t_data *data)
{
	float	pix;

	pix = data->pix;
	if (data->pos_enemy_x + 31 + pix < data->img->width
		&& !no_move(data, data->pos_enemy_x + pix, data->pos_enemy_y))
	{
		data->pos_enemy_x += pix;
		lose_game(data, data->pos_x, data->pos_y);
	}
}

void	move_enemy_left(t_data *data)
{
	float	pix;

	pix = data->pix;
	if (data->pos_enemy_x - pix >= 0
		&& !no_move(data, data->pos_enemy_x - pix, data->pos_enemy_y))
	{
		data->pos_enemy_x -= pix;
		lose_game(data, data->pos_x, data->pos_y);
	}
}
