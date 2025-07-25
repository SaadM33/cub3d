/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouz <yel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:32:35 by yel-bouz          #+#    #+#             */
/*   Updated: 2025/07/25 09:29:52 by yel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*b;

	if (!s)
		return (NULL);
	b = (char *)s;
	while (*b && *b != c)
		b++;
	if (*b == c)
		return (b);
	return (NULL);
}
