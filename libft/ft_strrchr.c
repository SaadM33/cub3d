/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouz <yel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:27:04 by yel-bouz          #+#    #+#             */
/*   Updated: 2025/07/25 09:36:18 by yel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*b;

	b = (char *)s;
	if (!s)
		return (NULL);
	while (*b)
		b++;
	while (b != s && *b != c)
		b--;
	if (b == s && *b != c)
		return (NULL);
	return (b);
}
