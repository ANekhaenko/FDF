/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 20:45:12 by anekhaen          #+#    #+#             */
/*   Updated: 2019/06/19 16:57:13 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;

	if (!s)
		return (NULL);
	fresh = malloc(sizeof(char) * (len + 1));
	if (fresh)
	{
		while (start--)
			s++;
		ft_strncpy(fresh, s, len);
		fresh[len] = '\0';
	}
	return (fresh);
}
