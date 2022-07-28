/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:24:36 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/28 03:16:22 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_data *data)
{
	float	pix;
	int		no_mv;

	pix = data->pix;
	lose_game(data, data->pos_x, data->pos_y - pix);
	win_game(data, data->pos_x, data->pos_y - pix);
	no_mv = no_move(data, data->pos_x, data->pos_y - pix);
	if (no_mv)
	{
		pix = ((int)data->pos_y) - (data->pos_wall_i * 32 + 32 + 32);
	}
	if (data->pos_y - pix >= 0 && pix > 0)
	{
		data->pos_y -= pix;
		get_coll(data);
		if ((int)(data->pos_y + pix) > (int)data->pos_y)
			ft_printf("nb of moves: %i\n", ++data->nb_moves);
	}
}

void	move_down(t_data *data)
{
	float	pix;
	int		no_mv;

	pix = data->pix;
	lose_game(data, data->pos_x, data->pos_y + pix);
	win_game(data, data->pos_x, data->pos_y + pix);
	if (pix < 1)
		no_mv = no_move(data, data->pos_x, data->pos_y + 1);
	else
		no_mv = no_move(data, data->pos_x, data->pos_y + pix);
	if (no_mv)
	{
		pix = (data->pos_wall_i * 32 + 32) - ((int)data->pos_y + 32);
	}
	if (data->pos_y + 31 + pix < data->img->height && pix > 0)
	{
		data->pos_y += pix;
		get_coll(data);
		if ((int)(data->pos_y - pix) < (int)data->pos_y)
			ft_printf("nb of moves: %i\n", ++data->nb_moves);
	}
}

void	move_right(t_data *data)
{
	float	pix;
	int		no_mv;

	pix = data->pix;
	lose_game(data, data->pos_x + pix, data->pos_y);
	win_game(data, data->pos_x + pix, data->pos_y);
	no_mv = no_move(data, data->pos_x + pix, data->pos_y);
	if (no_mv)
	{
		pix = (data->pos_wall_j * 32) - ((int)data->pos_x + 32);
	}
	if (data->pos_x + 31 + pix < data->img->width && pix > 0)
	{
		data->pos_x += pix;
		get_coll(data);
		if ((int)(data->pos_x - pix) < (int)data->pos_x)
			ft_printf("nb of moves: %i\n", ++data->nb_moves);
	}
}

void	move_left(t_data *data)
{
	float	pix;
	int		no_mv;

	pix = data->pix;
	lose_game(data, data->pos_x - pix, data->pos_y);
	win_game(data, data->pos_x - pix, data->pos_y);
	no_mv = no_move(data, data->pos_x - pix, data->pos_y);
	if (no_mv)
	{
		pix = (int)data->pos_x - (data->pos_wall_j * 32 + 32);
	}
	if (data->pos_x - pix >= 0 && pix > 0)
	{
		data->pos_x -= pix;
		get_coll(data);
		if ((int)(data->pos_x + pix) > (int)data->pos_x)
			ft_printf("nb of moves: %i\n", ++data->nb_moves);
	}
}
