/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouz <yel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:06:47 by yel-bouz          #+#    #+#             */
/*   Updated: 2025/07/25 09:36:32 by yel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	istrim(char c, const char *set)
{
	int	i;

	i = 0;
	while (set && set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		st;
	int		en;
	int		i;
	char	*n;

	st = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[st] && istrim(s1[st], set))
		st++;
	en = ft_strlen(s1) - 1;
	while (&s1[en] != s1 && istrim(s1[en], set))
		en--;
	if (st > en)
		return (ft_strdup(""));
	n = malloc(sizeof(char) * (en - st + 2));
	if (!n)
		return (NULL);
	while (st <= en)
		n[i++] = s1[st++];
	n[i] = '\0';
	return (n);
}
