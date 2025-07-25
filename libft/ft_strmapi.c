/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouz <yel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:27:18 by yel-bouz          #+#    #+#             */
/*   Updated: 2025/07/25 09:30:55 by yel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*n;

	i = 0;
	while (s && s[i])
		i++;
	n = malloc((i + 1) * sizeof(char));
	if (!n)
		return (NULL);
	i = 0;
	while (s && s[i])
	{
		n[i] = f(i, s[i]);
		i++;
	}
	n[i] = 0;
	return (n);
}
