/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:48:29 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/28 02:44:59 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_width_win(char **map)
{
	size_t	i;

	i = 0;
	while (map[0][i])
	{
		i++;
	}
	return (i * 32);
}

int	ft_height_win(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i * 32);
}

void	handle_moves(t_data *data)
{
	if (data->down[0] == 1)
		move_up(data);
	if (data->down[1] == 1)
		move_left(data);
	if (data->down[2] == 1)
		move_down(data);
	if (data->down[3] == 1)
		move_right(data);
}

void	render_enemy_player(t_data *data)
{
	render_enemy(data);
	render_player(data);
}

int	render_map(t_data *data)
{
	t_img	*img;
	int		i;
	int		j;
	char	**map;
	t_bool	first_digit;

	handle_moves(data);
	img = data->img;
	map = data->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			render_tile(map[i][j], i, j, data);
			j++;
		}
		i++;
	}
	first_digit = TRUE;
	render_score(data, data->nb_moves, &first_digit);
	render_enemy_player(data);
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
	return (0);
}
