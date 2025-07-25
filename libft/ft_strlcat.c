/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouz <yel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:46:51 by yel-bouz          #+#    #+#             */
/*   Updated: 2024/11/03 15:18:45 by yel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	j = 0;
	if (!dst && !size)
		return (slen);
	dlen = ft_strlen(dst);
	i = dlen;
	if (size <= dlen)
		return (slen + size);
	while ((src[j] != '\0') && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (slen + dlen);
}
