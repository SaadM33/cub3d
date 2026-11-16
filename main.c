/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouz <yel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:48:53 by yel-bouz          #+#    #+#             */
/*   Updated: 2025/07/25 17:50:01 by yel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	**parsemap(char *file)
{
	(void)file;
	return (NULL);
}

int	close_win(int key, void *param)
{
	(void)key;
	t_game *game = (t_game * ) param;
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	main(int ac, char *av[])
{
	char **(parse_map) = NULL;
	if (ac > 2)
	{
		ft_putendl_fd("Not valid arguments", 2);
		return (1);
	}
	
	parse_map = parsemap(av[1]);
	(void)parse_map;
	t_game	*game = ft_calloc(1, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror(NULL);
		return (1);
	}
	game->win = mlx_new_window(game->mlx, 1000, 1000, "Hello");
	mlx_hook(game->win, 17, 1L<<17, close_win, game);
	mlx_hook(game->win, 2, 1L<<0, close_win, game);
	mlx_loop(game->mlx);
	return (0);
}
