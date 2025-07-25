/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouz <yel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:12:52 by yel-bouz          #+#    #+#             */
/*   Updated: 2025/07/25 09:29:11 by yel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_word(const char *s, char del)
{
	int	w;
	int	i;
	int	f;

	w = 0;
	i = 0;
	f = 0;
	while (s && s[i])
	{
		if (s[i] == del && f == 1)
		{
			f = 0;
		}
		else if (f == 0)
		{
			f = 1;
			w++;
		}
		i++;
	}
	return (w);
}

static int	len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_dup(const char *s, char del)
{
	char	*new;
	size_t	i;

	i = 0;
	new = malloc(sizeof(char) * (len((char *)s, del) + 1));
	if (!new)
		return (NULL);
	while (s && s[i] && !(s[i] == del))
	{
		new[i] = s[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

static char	**ft_freed(char **big)
{
	unsigned int	i;

	i = 0;
	while ((big)[i] != NULL)
	{
		free((big)[i++]);
	}
	free(big);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**big;
	int		i;
	int		str;

	big = malloc(sizeof(char *) * (c_word(s, c) + 1));
	if (!big)
		return (NULL);
	i = 0;
	str = 0;
	while (s && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			big[str] = ft_dup(&s[i], c);
			if (big[str] == NULL)
				return (ft_freed(big));
			str++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	big[str] = NULL;
	return (big);
}
