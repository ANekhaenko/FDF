/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:28:57 by anekhaen          #+#    #+#             */
/*   Updated: 2019/05/30 01:26:05 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *a, const char *b, size_t len)
{
	size_t	i;
	size_t	j;

	if (*b == '\0')
		return ((char *)a);
	i = 0;
	while (a[i] && i < len)
	{
		j = 0;
		while (b[j] && b[j] == a[i + j] && i + j <= len)
			j++;
		if (b[j] == '\0')
			return ((char *)a + i);
		i++;
	}
	return (NULL);
}
