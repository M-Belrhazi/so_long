/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:51:20 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/18 16:33:27 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ret_1_write(void)
{
	write(2, "malloc error\n", 13);
}

void	ret_2_write(void)
{
	write(2, "File empty/not a file\n", 22);
}

void	ret_3_write(void)
{
	write(2, "Error\nmap not a rectangle\n", 26);
}

void	ret_4_write(void)
{
	write(2, "Error\nmap cut\n", 14);
}

void	ret_write(int return_nb)
{
	void	(*ft[5])(void);

	if (return_nb <= 0 || return_nb >= 5)
		return ;
	ft[1] = ret_1_write;
	ft[2] = ret_2_write;
	ft[3] = ret_3_write;
	ft[4] = ret_4_write;
	(ft[return_nb])();
}
