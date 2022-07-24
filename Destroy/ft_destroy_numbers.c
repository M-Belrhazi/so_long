/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:44:13 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/24 19:44:43 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_destroy_numbers(t_data *data)
{
	if (data->tiles[16])
		mlx_destroy_image(data->mlx, data->img->numbers[0].tile);
	if (data->tiles[17])
		mlx_destroy_image(data->mlx, data->img->numbers[1].tile);
	if (data->tiles[18])
		mlx_destroy_image(data->mlx, data->img->numbers[2].tile);
	if (data->tiles[19])
		mlx_destroy_image(data->mlx, data->img->numbers[3].tile);
	if (data->tiles[20])
		mlx_destroy_image(data->mlx, data->img->numbers[4].tile);
	if (data->tiles[21])
		mlx_destroy_image(data->mlx, data->img->numbers[5].tile);
	if (data->tiles[22])
		mlx_destroy_image(data->mlx, data->img->numbers[6].tile);
	if (data->tiles[23])
		mlx_destroy_image(data->mlx, data->img->numbers[7].tile);
	if (data->tiles[24])
		mlx_destroy_image(data->mlx, data->img->numbers[8].tile);
	if (data->tiles[25])
		mlx_destroy_image(data->mlx, data->img->numbers[9].tile);
}
