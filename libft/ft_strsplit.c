/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 00:26:48 by anekhaen          #+#    #+#             */
/*   Updated: 2019/06/18 19:44:52 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_string(char *s, int *i, char c)
{
	int		n;
	char	*nstr;

	n = 0;
	nstr = (char *)malloc(sizeof(char) * ft_strsize((char *)&s[*i], c) + 1);
	while (s[*i] != c && s[*i] != '\0')
	{
		nstr[n] = s[*i];
		n++;
		(*i)++;
	}
	nstr[n] = '\0';
	return (nstr);
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	int		i;
	int		j;
	int		n;
	char	**newarray;

	if (!s)
		return (NULL);
	n = 0;
	i = 0;
	j = 0;
	words = ft_strcount((char *)s, c);
	if (!(newarray = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i])
			newarray[n++] = create_string((char *)s, &i, c);
	}
	newarray[n] = NULL;
	return (newarray);
}
