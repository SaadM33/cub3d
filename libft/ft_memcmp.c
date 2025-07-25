/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouz <yel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:17:07 by yel-bouz          #+#    #+#             */
/*   Updated: 2025/07/25 09:27:00 by yel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*s;
	char	*k;
	size_t	i;

	s = (char *)s1;
	k = (char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s && k && i < n)
	{
		if (s[i] != k[i])
			return ((unsigned char)s[i] - (unsigned char)k[i]);
		i++;
	}
	return (0);
}
