/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouz <yel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:35:20 by yel-bouz          #+#    #+#             */
/*   Updated: 2025/07/25 09:36:43 by yel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*n;

	i = start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	n = malloc(sizeof(char) * (len + 1));
	if (!n)
		return (NULL);
	while (s && s[i] && i < (len + start))
	{
		n[i - start] = s[i];
		i++;
	}
	n[i - start] = 0;
	return (n);
}
