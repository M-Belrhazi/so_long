/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_score_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:32:47 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/24 19:28:32 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_number(t_data *data, int nb, t_bool first_digit)
{
	static int	x;

	if (first_digit == TRUE)
		x = 0;
	put_tile_to_image(data->img, &data->img->numbers[nb], x, 0);
	x += data->img->numbers[nb].line_size / (data->img->numbers[nb].bpp / 8);
}

void	render_score(t_data *data, int score, t_bool *first_digit)
{
	if (score / 10 == 0)
	{
		display_number(data, score, *first_digit);
		*first_digit = FALSE;
	}
	else
	{
		render_score(data, score / 10, first_digit);
		display_number(data, score % 10, *first_digit);
	}
}
