/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:50:35 by anekhaen          #+#    #+#             */
/*   Updated: 2019/06/18 21:58:05 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dstr;
	const char	*sstr;

	if (dst == NULL && src == NULL)
		return (NULL);
	dstr = dst;
	sstr = src;
	while (n > 0)
	{
		*dstr++ = *sstr++;
		n--;
	}
	return (dst);
}
