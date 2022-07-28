/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:21:34 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/28 14:50:25 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_nb_colls(char **map)
{
	int		i;
	int		j;
	int		nb_colls;

	i = 0;
	nb_colls = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'B')
				nb_colls++;
			j++;
		}
		i++;
	}
	return (nb_colls);
}

void	ft_init_pos_enemy(t_data *data, char **map)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (exit == 1 && map[i][j] == '0')
				break ;
			if (map[i][j] == 'E')
				exit = 1;
			j++;
		}
		if (exit == 1 && map[i][j] == '0')
			break ;
		i++;
	}
	data->pos_enemy_x = j * 32;
	data->pos_enemy_y = i * 32;
}

void	ft_init_data(t_data *data, char **map, t_img *img)
{
	data->down[0] = 0;
	data->down[1] = 0;
	data->down[2] = 0;
	data->down[3] = 0;
	data->map = map;
	data->colls = get_nb_colls(map);
	data->pix = PIX * (img->width * img->height) / (260 * 300);
	data->anim = ANIM * (300 * 400) / (img->height * img->width);
	ft_init_pos_enemy(data, map);
	data->nb_moves = 0;
	data->broom = 0;
}

int	ft_mlx(char **map)
{
	t_data	data;
	t_img	img;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (0);
	img.width = ft_width_win(map);
	img.height = ft_height_win(map);
	data.win = mlx_new_window(data.mlx, img.width,
			img.height, "Kitty and maleficat");
	if (!data.win)
		return (ft_close_mlx(&data), 0);
	img.img = mlx_new_image(data.mlx, img.width, img.height);
	ft_init_data(&data, map, &img);
	data.img = &img;
	if (!data.img->img)
		return (ft_close_window(&data), ft_close_mlx(&data), 0);
	if (!ft_init_tiles(&data))
		return (write(2, "mlx or img file error\n", 22), ft_close(&data), 0);
	mlx_loop_hook(data.mlx, &render_map, &data);
	mlx_hook(data.win, 2, 1L << 0, &handle_keypress, &data);
	mlx_hook(data.win, 3, 1L << 1, &handle_keyrelease, &data);
	mlx_hook(data.win, 17, 0, &ft_close, &data);
	mlx_loop(data.mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	char	**map;
	int		i;

	i = 0;
	map = &argv[1];
	if (argc != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		return (1);
	}
	if (find_error(argv[1]))
		return (2);
	if (parse(argv[1], &map))
		return (3);
	if (!ft_mlx(map))
		return (free_map(map), write(2, "mlx or img file error\n", 22), 4);
	return (0);
}
