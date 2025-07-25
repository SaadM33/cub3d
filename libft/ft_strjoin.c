/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouz <yel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:00:46 by yel-bouz          #+#    #+#             */
/*   Updated: 2024/11/03 11:50:27 by yel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_onenull(const char *s1, char const *s2)
{
	if (!s1 && s2 != NULL)
		return (ft_strdup(s2));
	if (!s2 && s1 != NULL)
		return (ft_strdup(s1));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*n;
	int		l;
	int		i;

	if (!s1 || !s2)
		return (ft_onenull(s1, s2));
	l = ft_strlen(s1) + ft_strlen(s2);
	n = malloc(sizeof(char) * (l + 1));
	if (!n)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		n[i] = s1[i];
		i++;
	}
	l = 0;
	while (s2[l])
	{
		n[i + l] = s2[l];
		l++;
	}
	n[i + l] = 0;
	return (n);
}
