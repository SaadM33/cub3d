/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouz <yel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:00:24 by yel-bouz          #+#    #+#             */
/*   Updated: 2025/07/25 09:26:48 by yel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	*ft_r(const unsigned char *s, unsigned char c, size_t n)
{
	size_t	i;

	i = 0;
	while (s && i < n)
	{
		if (s[i] == c)
			return ((unsigned char *)&s[i]);
		i++;
	}
	return (NULL);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*d;

	d = (char *)s;
	return (ft_r((const unsigned char *)d, c, n));
}
