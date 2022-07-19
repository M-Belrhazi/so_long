/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:21:26 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/19 14:52:07 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_coll(t_data *data)
{
	size_t	x;
	size_t	y;

	y = data->pos_y + 14;
	x = data->pos_x + 14;
	while (y < (size_t)data->pos_y + 18)
	{
		x = data->pos_x + 14;
		while (x < (size_t)data->pos_x + 18)
		{
			if ((data->map)[y / 32][x / 32] == 'C'
				|| (data->map)[y / 32][x / 32] == 'B')
			{
				if ((data->map)[y / 32][x / 32] == 'B')
					data->broom = 1;
				(data->map)[y / 32][x / 32] = '0';
				data->colls = data->colls - 1;
				break ;
			}
			x++;
		}
		y++;
	}
}

int	no_move(t_data *data, size_t pos_x, size_t pos_y)
{
	size_t	x;
	size_t	y;

	y = pos_y;
	x = pos_x;
	while (y < (size_t)pos_y + 32)
	{
		x = pos_x;
		while (x < (size_t)pos_x + 32)
		{
			if ((data->map)[y / 32][x / 32] == '1')
			{
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	end_game(t_data *data, size_t pos_x, size_t pos_y)
{
	size_t	x;
	size_t	y;

	if (data->colls != 0)
		return ;
	y = pos_y;
	x = pos_x;
	while (y < (size_t)pos_y + 32)
	{
		x = pos_x;
		while (x < (size_t)pos_x + 32)
		{
			if ((data->map)[y / 32][x / 32] == 'E')
			{
				ft_printf("nb of moves = %i\n", ++data->nb_moves);
				ft_close(data);
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}
