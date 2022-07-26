/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:48:29 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/26 17:32:27 by mbelrhaz         ###   ########.fr       */
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

int	render_map(t_data *data)
{
	t_img	*img;
	size_t	i;
	size_t	j;
	char	**map;

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
	render_player(data);
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
	return (0);
}
