/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coco.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:13:47 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/01 05:15:07 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"
#include "minilibx/mlx.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int	x;
	int	y;
	int	x0;
	int	y0;
	int	buttondown;
}	t_data;

/*
int	on_mouse_down (int button, int x, int y, t_data *param)
{
	param->x0 = x;
	param->y0 = y;
	param->buttondown = 1;
	return (0);
}

int	on_mouse_move (int x, int y, t_data *param)
{
	if (param->buttondown == 1)
	{
		printf("%i  %i\n", x - param->x0, y - param->y0);
	}
	param->x0 = x;
	param->y0 = y;
	return (0);
}

int	on_mouse_up (int button, int x, int y, t_data *param)
{
	param->buttondown = 0;
	return (0);
}
*/

int	close(t_data *param)
{
	printf("coucou\n");
	mlx_destroy_window(param->mlx, param->win);
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	exit(0);
}

int	handle_no_event(t_data *param)
{
	return (0);
}

int	main(void)
{
	t_data	param;
	
	param.buttondown = 0;
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 1000, 1000, "Window");
	//mlx_loop_hook(param.mlx, &handle_no_event, &param);
	//mlx_hook(param.win, 4, 1L<<2, &on_mouse_down, &param);
	//mlx_hook(param.win, 5, 1L<<3, &on_mouse_up, &param);
	//mlx_hook(param.win, 6, 1L<<6, &on_mouse_move, &param);
	mlx_hook(param.win, 17, 0, close, &param);
	
	mlx_loop(param.mlx);

	return (0);
}
