/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:41:55 by anekhaen          #+#    #+#             */
/*   Updated: 2019/07/25 18:25:24 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		new_line(char **line, char **stat_str, int fd)
{
	char	*tmp_str;
	int		length;

	length = 0;
	while (stat_str[fd][length] != '\n' && stat_str[fd][length] != '\0')
		length++;
	if (stat_str[fd][length] == '\n')
	{
		*line = ft_strsub(stat_str[fd], 0, length);
		tmp_str = ft_strdup(stat_str[fd] + length + 1);
		free(stat_str[fd]);
		stat_str[fd] = tmp_str;
	}
	else
	{
		*line = ft_strdup(stat_str[fd]);
		ft_strdel(&stat_str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int				check_engine;
	char			buf_str[BUFF_SIZE + 1];
	char			*tmp_str;
	static char		*stat_str[MAX_FD];

	if (fd < 0 || fd > MAX_FD || !line || \
		read(fd, buf_str, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (stat_str[fd] == NULL)
		stat_str[fd] = ft_strnew(1);
	while ((check_engine = read(fd, buf_str, BUFF_SIZE)) > 0)
	{
		buf_str[check_engine] = '\0';
		tmp_str = ft_strjoin(stat_str[fd], buf_str);
		free(stat_str[fd]);
		stat_str[fd] = tmp_str;
		if (ft_strchr(buf_str, '\n'))
			break ;
	}
	if (stat_str[fd][0] == '\0')
		return (0);
	return (new_line(line, stat_str, fd));
}
