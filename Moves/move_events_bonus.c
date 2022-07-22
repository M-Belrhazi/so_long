/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_events_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:21:26 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/22 18:01:56 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_coll(t_data *data)
{
	int	x;
	int	y;

	y = data->pos_y + 14;
	x = data->pos_x + 14;
	while (y < data->pos_y + 18)
	{
		x = data->pos_x + 14;
		while (x < data->pos_x + 18)
		{
			if ((data->map)[y / 32 - 1][x / 32] == 'C'
				|| (data->map)[y / 32 - 1][x / 32] == 'B')
			{
				if ((data->map)[y / 32 - 1][x / 32] == 'B')
					data->broom = 1;
				(data->map)[y / 32 - 1][x / 32] = '0';
				data->colls = data->colls - 1;
				break ;
			}
			x++;
		}
		y++;
	}
}

int	no_move(t_data *data, int pos_x, int pos_y)
{
	int	x;
	int	y;

	y = pos_y;
	x = pos_x;
	while (y < pos_y + 32)
	{
		x = pos_x;
		while (x < pos_x + 32)
		{
			if ((data->map)[y / 32 - 1][x / 32] == '1')
			{
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	lose_game(t_data *data, int pos_x, int pos_y)
{
	int	x;
	int	y;

	y = pos_y;
	x = pos_x;
	while (y < pos_y + 32)
	{
		x = pos_x;
		while (x < pos_x + 32)
		{
			if ((x >= data->pos_enemy_x && x <= data->pos_enemy_x + 31)
				&& (y >= data->pos_enemy_y && y <= data->pos_enemy_y + 31))
			{
				ft_printf("\n*** Total moves: %i ***\n\n", ++data->nb_moves);
				ft_printf("You lost ! :(\n\n");
				ft_close(data);
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}

void	win_game(t_data *data, int pos_x, int pos_y)
{
	int	x;
	int	y;

	if (data->colls != 0)
		return ;
	y = pos_y;
	x = pos_x;
	while (y < pos_y + 32)
	{
		x = pos_x;
		while (x < pos_x + 32)
		{
			if ((data->map)[y / 32 - 1][x / 32] == 'E')
			{
				ft_printf("\n*** Total moves: %i ***\n\n", ++data->nb_moves);
				ft_printf("You won ! :)\n\n");
				ft_close(data);
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}
