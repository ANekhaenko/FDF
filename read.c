/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:40:30 by anekhaen          #+#    #+#             */
/*   Updated: 2019/10/17 15:46:32 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		read_file(t_main *m_struct)
{
	get_width(m_struct);
	get_height(m_struct);
	m_struct->z_matrix = (int **)malloc(sizeof(int*) * (m_struct->height + 1));
	m_struct->i = 0;
	while (m_struct->i <= m_struct->height)
		m_struct->z_matrix[m_struct->i++] = (int *)malloc(sizeof(int)
		* (m_struct->width + 1));
	m_struct->i = 0;
	m_struct->fd = open(m_struct->filename, O_RDONLY, 0);
	while (get_next_line(m_struct->fd, &m_struct->line))
	{
		fill_matrix(m_struct->z_matrix[m_struct->i++], m_struct->line);
		free(m_struct->line);
	}
	close(m_struct->fd);
}

void		get_height(t_main *m_struct)
{
	m_struct->height = 0;
	m_struct->fd = open(m_struct->filename, O_RDONLY, 0);
	while (get_next_line(m_struct->fd, &m_struct->line))
	{
		m_struct->height++;
		free(m_struct->line);
	}
	close(m_struct->fd);
}

void		get_width(t_main *m_struct)
{
	m_struct->width = 0;
	m_struct->w_sum = 0;
	m_struct->fd = open(m_struct->filename, O_RDONLY);
	while (get_next_line(m_struct->fd, &m_struct->line) == 1)
	{
		m_struct->width = count_width(m_struct->line);
		m_struct->w_sum += m_struct->width;
		free(m_struct->line);
	}
	if (m_struct->w_sum % m_struct->width != 0)
	{
		write(1, "Found wrong line length. Exiting.\n", 34);
		exit(-1);
	}
	close(m_struct->fd);
}

size_t		count_width(char const *line)
{
	size_t	c;

	c = 0;
	while (*line)
	{
		if (*line != ' ')
		{
			if (*(line + 1) == ' ' || *(line + 1) == '\0')
				c++;
		}
		line++;
	}
	return (c);
}

void		fill_matrix(int *num_line, char *line)
{
	char	**num_arr;
	int		i;

	i = 0;
	num_arr = ft_strsplit(line, ' ');
	while (num_arr[i])
	{
		num_line[i] = ft_atoi(num_arr[i]);
		free(num_arr[i]);
		i++;
	}
	free(num_arr);
}
