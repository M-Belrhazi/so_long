/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:24:36 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/26 19:04:57 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_data *data)
{
	lose_game(data, data->pos_x, data->pos_y - PIX);
	win_game(data, data->pos_x, data->pos_y - PIX);
	if (data->pos_y - PIX >= 0
		&& !no_move(data, data->pos_x, data->pos_y - PIX))
	{
		data->pos_y -= PIX;
		get_coll(data);
		if ((int)(data->pos_y + PIX) > (int)data->pos_y)
			ft_printf("nb of moves: %i\n", ++data->nb_moves);
	}
}

void	move_down(t_data *data)
{
	lose_game(data, data->pos_x, data->pos_y + PIX);
	win_game(data, data->pos_x, data->pos_y + PIX);
	if (data->pos_y + 31 + PIX < data->img->height
		&& !no_move(data, data->pos_x, data->pos_y + PIX))
	{
		data->pos_y += PIX;
		get_coll(data);
		if ((int)(data->pos_y - PIX) < (int)data->pos_y)
			ft_printf("nb of moves: %i\n", ++data->nb_moves);
	}
}

void	move_right(t_data *data)
{
	lose_game(data, data->pos_x + PIX, data->pos_y);
	win_game(data, data->pos_x + PIX, data->pos_y);
	if (data->pos_x + 31 + PIX < data->img->width
		&& !no_move(data, data->pos_x + PIX, data->pos_y))
	{
		data->pos_x += PIX;
		get_coll(data);
		if ((int)(data->pos_x - PIX) < (int)data->pos_x)
			ft_printf("nb of moves: %i\n", ++data->nb_moves);
	}
}

void	move_left(t_data *data)
{
	lose_game(data, data->pos_x - PIX, data->pos_y);
	win_game(data, data->pos_x - PIX, data->pos_y);
	if (data->pos_x - PIX >= 0
		&& !no_move(data, data->pos_x - PIX, data->pos_y))
	{
		data->pos_x -= PIX;
		get_coll(data);
		if ((int)(data->pos_x + PIX) > (int)data->pos_x)
			ft_printf("nb of moves: %i\n", ++data->nb_moves);
	}
}
