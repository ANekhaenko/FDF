/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 00:24:53 by anekhaen          #+#    #+#             */
/*   Updated: 2019/06/18 19:47:04 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		s;
	int		sign;
	int		temp;
	char	*arr;

	sign = 0;
	if (n < 0)
		sign = 1;
	temp = n;
	s = 1;
	while ((temp /= 10))
		s++;
	arr = ft_strnew(s + sign);
	if (arr == NULL)
		return (NULL);
	if (sign)
		arr[0] = '-';
	while (s--)
	{
		arr[s + sign] = (sign ? -(n % 10) : (n % 10)) + '0';
		n /= 10;
	}
	return (arr);
}
