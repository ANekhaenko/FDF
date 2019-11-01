/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 21:25:35 by anekhaen          #+#    #+#             */
/*   Updated: 2019/06/19 16:34:43 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*source;
	size_t		i;

	source = (const char *)s;
	i = -1;
	while (++i < n)
		if (*(source + i) == (char)c)
			return ((void *)source + i);
	return (NULL);
}
