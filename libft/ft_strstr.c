/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 19:57:58 by anekhaen          #+#    #+#             */
/*   Updated: 2019/06/18 22:01:34 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*i;
	char	*j;

	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1)
	{
		i = (char *)s1;
		j = (char *)s2;
		while (*j && *i == *j)
		{
			i++;
			j++;
		}
		if (*j == '\0')
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
