/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:21:26 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/19 14:46:35 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int key, t_data *data)
{
	if (key == 65307)
		ft_close(data);
	if (key == 'w' || key == 65362)
		data->down[0] = 1;
	if (key == 'a' || key == 65361)
		data->down[1] = 1;
	if (key == 's' || key == 65364)
		data->down[2] = 1;
	if (key == 'd' || key == 65363)
		data->down[3] = 1;
	return (0);
}

int	handle_keyrelease(int key, t_data *data)
{
	if (key == 65307)
		ft_close(data);
	if (key == 'w' || key == 65362)
		data->down[0] = 0;
	if (key == 'a' || key == 65361)
		data->down[1] = 0;
	if (key == 's' || key == 65364)
		data->down[2] = 0;
	if (key == 'd' || key == 65363)
		data->down[3] = 0;
	return (0);
}
