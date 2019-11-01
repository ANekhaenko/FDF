/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:42:21 by anekhaen          #+#    #+#             */
/*   Updated: 2019/10/17 21:54:22 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include "math.h"
# include <fcntl.h>

typedef struct		s_main
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				height;
	int				width;
	int				w_sum;
	int				new_x;
	int				new_y;
	char			*filename;
	char			*line;
	int				color;
	int				old_color;
	int				view;
	int				i;
	int				fd;
	int				**z_matrix;
	int				zoom;
	float			altitude;
	float			x;
	float			y;
	float			z;
	float			x1;
	float			y1;
	float			z1;
	float			x_o;
	float			y_o;
	float			x1_o;
	float			y1_o;
}					t_main;

void				make_window(t_main *m_struct);
int					key(int key, t_main *m_struct);
int					key2(int key, t_main *m_struct);
size_t				count_width(char const *str);
void				get_height(t_main *m_struct);
void				get_width(t_main *m_struct);
void				fill_matrix(int *num_line, char *line);
void				read_file(t_main *m_struct);
void				bresenham(t_main *m_struct);
void				draw(t_main *m_struct);
void				iso(t_main *m_struct);
void				flat(t_main *m_struct);
void				save_xyz(t_main *m_struct);
void				help(t_main *m_struct);
#endif
