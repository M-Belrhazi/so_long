/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:23:08 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/22 14:56:35 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_player(t_data *data)
{
	if (data->tiles[8])
		mlx_destroy_image(data->mlx, data->img->player[0]->tile);
	if (data->tiles[9])
		mlx_destroy_image(data->mlx, data->img->player[1]->tile);
	if (data->tiles[10])
		mlx_destroy_image(data->mlx, data->img->player[2]->tile);
	if (data->tiles[11])
		mlx_destroy_image(data->mlx, data->img->player[3]->tile);
	if (data->tiles[12])
		mlx_destroy_image(data->mlx, data->img->player_br[0]->tile);
	if (data->tiles[13])
		mlx_destroy_image(data->mlx, data->img->player_br[1]->tile);
	if (data->tiles[14])
		mlx_destroy_image(data->mlx, data->img->player_br[2]->tile);
	if (data->tiles[15])
		mlx_destroy_image(data->mlx, data->img->player_br[3]->tile);
}

void	ft_destroy_image(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	ft_destroy_player(data);
	if (data->tiles[0])
		mlx_destroy_image(data->mlx, data->img->tile->tile);
	if (data->tiles[1])
		mlx_destroy_image(data->mlx, data->img->exit->tile);
	if (data->tiles[6])
		mlx_destroy_image(data->mlx, data->img->enemy->tile);
	if (data->tiles[7])
		mlx_destroy_image(data->mlx, data->img->new_enemy->tile);
	if (data->tiles[4])
		mlx_destroy_image(data->mlx, data->img->col[0]->tile);
	if (data->tiles[5])
		mlx_destroy_image(data->mlx, data->img->col[1]->tile);
	if (data->tiles[2])
		mlx_destroy_image(data->mlx, data->img->wall[0]->tile);
	if (data->tiles[3])
		mlx_destroy_image(data->mlx, data->img->wall[1]->tile);
}

void	ft_close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
}

void	ft_close_mlx(t_data *data)
{
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

int	ft_close(t_data *data)
{
	ft_destroy_image(data);
	free(data->img->tile);
	free(data->img->player[0]);
	free(data->img->player_br[0]);
	free(data->img->exit);
	free(data->img->enemy);
	free(data->img->new_enemy);
	free(data->img->col[0]);
	free(data->img->wall[0]);
	free_map(data->map);
	ft_close_window(data);
	ft_close_mlx(data);
	exit(0);
	return (0);
}
