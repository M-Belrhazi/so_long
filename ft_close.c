/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:23:08 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/17 21:28:26 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_image(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_image(data->mlx, data->img->tile->tile);
	mlx_destroy_image(data->mlx, data->img->player[0]->tile);
	mlx_destroy_image(data->mlx, data->img->player[1]->tile);
	mlx_destroy_image(data->mlx, data->img->player[2]->tile);
	mlx_destroy_image(data->mlx, data->img->player[3]->tile);
	mlx_destroy_image(data->mlx, data->img->player_br[0]->tile);
	mlx_destroy_image(data->mlx, data->img->player_br[1]->tile);
	mlx_destroy_image(data->mlx, data->img->player_br[2]->tile);
	mlx_destroy_image(data->mlx, data->img->player_br[3]->tile);
	mlx_destroy_image(data->mlx, data->img->exit->tile);
	mlx_destroy_image(data->mlx, data->img->col[0]->tile);
	mlx_destroy_image(data->mlx, data->img->col[1]->tile);
	mlx_destroy_image(data->mlx, data->img->wall[0]->tile);
	mlx_destroy_image(data->mlx, data->img->wall[1]->tile);
}

int	ft_close(t_data *data)
{
	ft_destroy_image(data);
	free(data->img->tile);
	free(data->img->player[0]);
	free(data->img->player_br[0]);
	free(data->img->exit);
	free(data->img->col[0]);
	free(data->img->wall[0]);
	mlx_destroy_window(data->mlx, data->win);
	free_map(data->map);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
