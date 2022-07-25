/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:04:34 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/25 18:08:52 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_data_tab_tiles(t_data *data)
{
	int	i;

	i = 0;
	while (i < 28)
	{
		data->tiles[i] = 0;
		i++;
	}
}

int	init_enemy(t_data *data)
{
	t_tile	*enemy;

	enemy = malloc(sizeof(t_tile));
	data->img->enemy = enemy;
	if (!enemy)
		return (0);
	enemy->tile = mlx_xpm_file_to_image(data->mlx, "imgs/black_cat.xpm",
			&enemy->width, &enemy->height);
	if (!enemy->tile)
		return (0);
	return (data->tiles[6] = 1, 1);
}

int	init_new_enemy(t_data *data)
{
	t_tile	*new_enemy;

	new_enemy = malloc(sizeof(t_tile));
	if (!new_enemy)
		return (0);
	new_enemy->tile = mlx_xpm_file_to_image(data->mlx, "imgs/cato.xpm",
			&new_enemy->width, &new_enemy->height);
	if (!new_enemy->tile)
		return (0);
	data->img->new_enemy = new_enemy;
	return (data->tiles[7] = 1, 1);
}

int	ft_init_tiles(t_data *data)
{
	int	ret_init[9];
	int	i;

	ft_init_data_tab_tiles(data);
	ret_init[0] = init_tile(data);
	ret_init[1] = init_col(data);
	ret_init[2] = init_exit(data);
	ret_init[3] = init_enemy(data);
	ret_init[4] = init_new_enemy(data);
	ret_init[5] = init_wall(data);
	ret_init[6] = init_player(data);
	ret_init[7] = init_player_br(data);
	ret_init[8] = init_numbers(data);
	i = 0;
	while (i < 9)
	{
		if (ret_init[i] == 0)
			return (0);
		i++;
	}
	return (1);
}
