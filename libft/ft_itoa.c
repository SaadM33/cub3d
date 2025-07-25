/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouz <yel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:25:22 by yel-bouz          #+#    #+#             */
/*   Updated: 2024/10/27 08:54:16 by yel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	divis(long n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_abs(int n)
{
	return (n * ((n > 0) - (n < 0)));
}

char	*ft_itoa(int n)
{
	char	*s;
	long	l;
	int		i;

	l = n;
	s = malloc(sizeof(char) * (divis(l) + (n < 0) + 1));
	if (!s)
		return (NULL);
	if (l < 0)
		s[0] = '-';
	if (l == 0)
		s[0] = '0';
	i = divis(l) + (n < 0);
	s[divis(l) + (n < 0)] = 0;
	while (i-- && l)
	{
		s[i] = ft_abs(l % 10) + 48;
		l /= 10;
	}
	return (s);
}
