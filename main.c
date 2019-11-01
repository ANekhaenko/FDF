/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:44:17 by anekhaen          #+#    #+#             */
/*   Updated: 2019/10/17 22:21:15 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_main		*m_struct;

	m_struct = (t_main*)malloc(sizeof(t_main));
	if (argc != 2)
	{
		write(1, "Don't forget about input file\n", 30);
		return (0);
	}
	if ((m_struct->fd = open(argv[1], O_RDONLY) <= 0))
	{
		write(1, "Error file\n", 11);
		return (-1);
	}
	m_struct->filename = argv[1];
	read_file(m_struct);
	make_window(m_struct);
	draw(m_struct);
	mlx_hook(m_struct->win_ptr, 2, 5, key, m_struct);
	mlx_loop(m_struct->mlx_ptr);
	close(m_struct->fd);
	free(m_struct);
	return (0);
}
