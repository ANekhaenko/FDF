/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:41:36 by anekhaen          #+#    #+#             */
/*   Updated: 2019/10/17 21:55:02 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define MAX(a, b) (a > b ? a : b)
#define MOD(a) ((a < 0 ) ? -a : a)

void		draw(t_main *m_struct)
{
	help(m_struct);
	m_struct->y_o = 0;
	while (m_struct->y_o < m_struct->height)
	{
		m_struct->x_o = 0;
		while (m_struct->x_o < m_struct->width)
		{
			if (m_struct->x_o < m_struct->width - 1)
			{
				m_struct->x1_o = m_struct->x_o + 1;
				m_struct->y1_o = m_struct->y_o;
				bresenham(m_struct);
			}
			if (m_struct->y_o < m_struct->height - 1)
			{
				m_struct->x1_o = m_struct->x_o;
				m_struct->y1_o = m_struct->y_o + 1;
				bresenham(m_struct);
			}
			m_struct->x_o++;
		}
		m_struct->y_o++;
	}
}

void		bresenham(t_main *m_struct)
{
	float	dx;
	float	dy;
	int		max;

	save_xyz(m_struct);
	m_struct->color = (m_struct->z != 0 || m_struct->z1 != 0) ?
	m_struct->old_color + m_struct->z * 6 : 0xffffff;
	if (m_struct->view == 7)
		iso(m_struct);
	else
		flat(m_struct);
	dx = m_struct->x1 - m_struct->x;
	dy = m_struct->y1 - m_struct->y;
	max = MAX(MOD(dx), MOD(dy));
	dx /= max;
	dy /= max;
	while ((int)(m_struct->x - m_struct->x1)
		|| (int)(m_struct->y - m_struct->y1))
	{
		mlx_pixel_put(m_struct->mlx_ptr, m_struct->win_ptr,
		m_struct->x, m_struct->y, m_struct->color);
		m_struct->x += dx;
		m_struct->y += dy;
	}
}

void		save_xyz(t_main *m_struct)
{
	m_struct->z = m_struct->z_matrix[(int)m_struct->y_o][(int)m_struct->x_o]
	* m_struct->altitude;
	m_struct->z1 = m_struct->z_matrix[(int)m_struct->y1_o][(int)m_struct->x1_o]
	* m_struct->altitude;
	m_struct->x = m_struct->x_o;
	m_struct->x1 = m_struct->x1_o;
	m_struct->y = m_struct->y_o;
	m_struct->y1 = m_struct->y1_o;
}

void		iso(t_main *m_struct)
{
	m_struct->x = (m_struct->x - m_struct->y) * cos(1.1);
	m_struct->y = (m_struct->x + m_struct->y) * sin(0.5) - m_struct->z / 2;
	m_struct->x1 = (m_struct->x1 - m_struct->y1) * cos(1.1);
	m_struct->y1 = (m_struct->x1 + m_struct->y1) * sin(0.5) - m_struct->z1 / 2;
	m_struct->x *= m_struct->zoom;
	m_struct->x1 *= m_struct->zoom;
	m_struct->y *= m_struct->zoom;
	m_struct->y1 *= m_struct->zoom;
	m_struct->x += m_struct->new_x;
	m_struct->y += m_struct->new_y;
	m_struct->x1 += m_struct->new_x;
	m_struct->y1 += m_struct->new_y;
}

void		flat(t_main *m_struct)
{
	m_struct->x /= cos(1.1);
	m_struct->y /= sin(0.5);
	m_struct->x1 /= cos(1.1);
	m_struct->y1 /= sin(0.5);
	m_struct->x *= m_struct->zoom / 4;
	m_struct->x1 *= m_struct->zoom / 4;
	m_struct->y *= m_struct->zoom / 4;
	m_struct->y1 *= m_struct->zoom / 4;
	m_struct->x += m_struct->new_x;
	m_struct->y += m_struct->new_y;
	m_struct->x1 += m_struct->new_x;
	m_struct->y1 += m_struct->new_y;
}
