/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_number_tiles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:03:05 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/22 19:15:35 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_numbers_5_9(t_data *data)
{
	data->img->numbers[5].tile = mlx_xpm_file_to_image(data->mlx, FIVE,
			&data->img->numbers[5].width, &data->img->numbers[5].height);
	data->img->numbers[6].tile = mlx_xpm_file_to_image(data->mlx, SIX,
			&data->img->numbers[6].width, &data->img->numbers[6].height);
	data->img->numbers[7].tile = mlx_xpm_file_to_image(data->mlx, SEVEN,
			&data->img->numbers[7].width, &data->img->numbers[7].height);
	data->img->numbers[8].tile = mlx_xpm_file_to_image(data->mlx, EIGHT,
			&data->img->numbers[8].width, &data->img->numbers[8].height);
	data->img->numbers[9].tile = mlx_xpm_file_to_image(data->mlx, NINE,
			&data->img->numbers[9].width, &data->img->numbers[9].height);
	if (data->img->numbers[5].tile)
		data->tiles[21] = 1;
	if (data->img->numbers[6].tile)
		data->tiles[22] = 1;
	if (data->img->numbers[7].tile)
		data->tiles[23] = 1;
	if (data->img->numbers[8].tile)
		data->tiles[24] = 1;
	if (data->img->numbers[9].tile)
		data->tiles[25] = 1;
	if (!data->img->numbers[5].tile || !data->img->numbers[6].tile
		|| !data->img->numbers[7].tile || !data->img->numbers[8].tile
		|| !data->img->numbers[9].tile)
		return (0);
	return (1);
}

int	init_numbers_0_4(t_data *data)
{
	data->img->numbers[0].tile = mlx_xpm_file_to_image(data->mlx, ZERO,
			&data->img->numbers[0].width, &data->img->numbers[0].height);
	data->img->numbers[1].tile = mlx_xpm_file_to_image(data->mlx, ONE,
			&data->img->numbers[1].width, &data->img->numbers[1].height);
	data->img->numbers[2].tile = mlx_xpm_file_to_image(data->mlx, TWO,
			&data->img->numbers[2].width, &data->img->numbers[2].height);
	data->img->numbers[3].tile = mlx_xpm_file_to_image(data->mlx, THREE,
			&data->img->numbers[3].width, &data->img->numbers[3].height);
	data->img->numbers[4].tile = mlx_xpm_file_to_image(data->mlx, FOUR,
			&data->img->numbers[4].width, &data->img->numbers[4].height);
	if (data->img->numbers[0].tile)
		data->tiles[16] = 1;
	if (data->img->numbers[1].tile)
		data->tiles[17] = 1;
	if (data->img->numbers[2].tile)
		data->tiles[18] = 1;
	if (data->img->numbers[3].tile)
		data->tiles[19] = 1;
	if (data->img->numbers[4].tile)
		data->tiles[20] = 1;
	if (!data->img->numbers[0].tile || !data->img->numbers[1].tile
		|| !data->img->numbers[2].tile || !data->img->numbers[3].tile
		|| !data->img->numbers[4].tile)
		return (0);
	return (1);
}

int	init_numbers(t_data *data)
{
	int	ret[2];

	ret[0] = init_numbers_0_4(data);
	ret[1] = init_numbers_5_9(data);
	if (!ret[0] || !ret[1])
		return (0);
	return (1);
}
