/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 03:39:43 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/15 19:30:18 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct	s_img {
	void	*img;
	int	width;
	int	height;
	int	bpp;
	int	line_size;
	int	endian;
	char	*data;
}	t_img;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_img	*img;
	int		down;
}	t_data;

int	put_pxl_to_image(t_data *param, t_img *img, int x, int y);

int	render(t_data *param)
{
	t_img	*img;
	static int	y;

	img = param->img;
	if (param->down == 1)
	{
		put_pxl_to_image(param, param->img, 0, y);
		y += param->img->line_size;
	}
	mlx_put_image_to_window(param->mlx, param->win, img->img, 0, 0);
	return (0);
}

int	ft_close(t_data *param)
{
	mlx_destroy_image(param->mlx, param->img->img);
	mlx_destroy_window(param->mlx, param->win);
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	exit(0);
}

int	put_pxl_to_image(t_data *param, t_img *img, int x, int y)
{
	char	*data;
	char	*data_mod;

	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->line_size, &img->endian);
	//printf("line_size = %d\n", img->line_size);
	data = img->data;
	while (x < img->line_size && y <= img->line_size * img->height)
	{
		data_mod = data + x + y;
		*(unsigned int *)data_mod = 0x00ff0000;
		x += 4;
	}
	return (0);
}

int	handle_keyrelease(int key, t_data *param)
{
	param->down = 0;
	return (0);
}

int	handle_keypress(int key, t_data *param)
{
	//static int	y;

	printf("key = %i\n", key);
	if (key == 65307)
		ft_close(param);
	if (key == 32)
	{
		param->down = 1;
		// put_pxl_to_image(param, param->img, 0, y);
		// y += param->img->line_size;
	}
	return (0);
}

int	main(void)
{
	t_data	param;
	t_img	img;

	/* initializing the necessary things */
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 2000, 2000, "Hola");
	// img.width = 1000;
	// img.height = 1000;
	//img.img = mlx_new_image(param.mlx, img.width, img.height);
	img.img = mlx_xpm_file_to_image(param.mlx, "green.xpm", &img.width, &img.height);
	param.img = &img;
	param.down = 0;

	/* handling events */
	mlx_loop_hook(param.mlx, &render, &param);
	mlx_hook(param.win, 2, 1L<<0, &handle_keypress, &param);
	mlx_hook(param.win, 3, 1L<<1, &handle_keyrelease, &param);
	mlx_hook(param.win, 17, 0, &ft_close, &param);
	mlx_loop(param.mlx);

	return (0);
}
