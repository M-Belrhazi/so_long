/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:23:08 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/15 18:23:23 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_image(data->mlx, data->img->tile->tile);
	mlx_destroy_image(data->mlx, data->img->player->tile);
	mlx_destroy_image(data->mlx, data->img->exit->tile);
	mlx_destroy_image(data->mlx, data->img->col->tile);
	mlx_destroy_image(data->mlx, data->img->wall1->tile);
	mlx_destroy_image(data->mlx, data->img->wall2->tile);
	free(data->img->tile);
	free(data->img->player);
	free(data->img->exit);
	free(data->img->col);
	free(data->img->wall1);
	mlx_destroy_window(data->mlx, data->win);
	free_map(data->map);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
