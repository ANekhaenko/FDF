/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:55:47 by anekhaen          #+#    #+#             */
/*   Updated: 2019/10/17 22:23:24 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key(int key, t_main *m_struct)
{
	mlx_clear_window(m_struct->mlx_ptr, m_struct->win_ptr);
	if (key == 53)
		exit(0);
	else if (key == 123)
		m_struct->new_x -= 5;
	else if (key == 124)
		m_struct->new_x += 5;
	else if (key == 126)
		m_struct->new_y -= 5;
	else if (key == 125)
		m_struct->new_y += 5;
	else if (key == 12)
		m_struct->altitude += 0.1;
	else if (key == 13)
		m_struct->altitude -= 0.1;
	else if (key == 27)
		m_struct->zoom -= 5;
	else if (key == 24)
		m_struct->zoom += 5;
	else
		key2(key, m_struct);
	draw(m_struct);
	return (0);
}

int			key2(int key, t_main *m_struct)
{
	if (key == 15)
		m_struct->old_color = 0x7d2424;
	else if (key == 5)
		m_struct->old_color = 0x247d58;
	else if (key == 11)
		m_struct->old_color = 0x24497d;
	else if (key == 8)
		m_struct->old_color += 2048;
	else if (key == 6)
		m_struct->view = 6;
	else if (key == 7)
		m_struct->view = 7;
	draw(m_struct);
	return (0);
}

void		help(t_main *m_struct)
{
	mlx_string_put(m_struct->mlx_ptr, m_struct->win_ptr, 10, 10, 0x247d58,
	"To change scale use + or - ");
	mlx_string_put(m_struct->mlx_ptr, m_struct->win_ptr, 10, 30, 0x247d58,
	"To change altitude use Q or W");
	mlx_string_put(m_struct->mlx_ptr, m_struct->win_ptr, 10, 50, 0x247d58,
	"To move use arrow buttons");
	mlx_string_put(m_struct->mlx_ptr, m_struct->win_ptr, 10, 70, 0x247d58,
	"To change colors use R G B or C");
	mlx_string_put(m_struct->mlx_ptr, m_struct->win_ptr, 10, 90, 0x247d58,
	"To change type of projection use Z or X");
}

void		make_window(t_main *m_struct)
{
	m_struct->mlx_ptr = mlx_init();
	m_struct->win_ptr = mlx_new_window(m_struct->mlx_ptr, 1920, 1200, "FDF");
	m_struct->new_x = 760;
	m_struct->new_y = 300;
	m_struct->view = 7;
	m_struct->color = 0x247d58;
	m_struct->old_color = 0x247d58;
	m_struct->zoom = 44;
	m_struct->altitude = 1;
}
