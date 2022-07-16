/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:21:34 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/16 18:30:53 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_nb_colls(char **map)
{
	size_t	i;
	size_t	j;
	int		nb_colls;

	i = 0;
	nb_colls = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				nb_colls++;
			j++;
		}
		i++;
	}
	return (nb_colls);
}

void	ft_init_data(t_data *data, char **map)
{
	data->down[0] = 0;
	data->down[1] = 0;
	data->down[2] = 0;
	data->down[3] = 0;
	data->colls = get_nb_colls(map);
	data->nb_moves = 0;
}

int	ft_mlx(char **map)
{
	t_data	data;
	t_img	img;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (0);
	data.map = map;
	ft_init_data(&data, map);
	img.width = ft_width_win(map);
	img.height = ft_height_win(map);
	data.win = mlx_new_window(data.mlx, img.width, img.height, "HOHO");
	img.img = mlx_new_image(data.mlx, img.width, img.height);
	data.img = &img;
	if (!data.win || !data.img)
		return (0);
	if (!init_tiles(&data))
		return (0);
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
		return (free_map(map), write(2, "mlx or img file error\n", 10), 4);
	return (0);
}
