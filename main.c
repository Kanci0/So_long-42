/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:45:00 by dtoszek           #+#    #+#             */
/*   Updated: 2024/06/03 10:15:09 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static void	closefds(int fd, int fdx, int fdmap, int fdy)
{
	close(fd);
	close(fdx);
	close(fdy);
	close(fdmap);
}

static void	start_map(t_game *game)
{
	game->player_x = 0;
	game->player_y = 0;
	game->player_on_box = 0;
	game->exit = 0;
	game->player = 0;
	game->line = 0;
	game->col = 0;
	game->end_game = 0;
	game->move = 1;
	game->key = 0;
}

static void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->col * 64,
			game-> line * 64, "long");
	mlx_hook(game->win, 02, 1L, key_handler, game);
	mlx_hook(game->win, 17, 1L << 17, close_window, game);
	put_images(game);
	render_img(game);
	mlx_loop(game->mlx);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	int		fd;
	int		fd_x;
	int		fd_y;
	int		fd_map;

	if (argc != 2)
		return (0);
	fd_x = open(argv[1], O_RDONLY);
	fd_y = open(argv[1], O_RDONLY);
	fd_map = open(argv[1], O_RDONLY);
	check_args(&game, argc, argv);
	start_map(&game);
	game.score = collectible_counter(&game);
	game.line = get_line_size(&game, fd_y);
	game.col = get_col_size(&game, fd_x);
	fd = open(argv[1], O_RDONLY);
	get_map(&game, fd);
	validate(&game, fd_map);
	if (game.col == -1)
		ft_exit("Error\n", &game);
	closefds(fd, fd_x, fd_map, fd_y);
	player_position(&game);
	start_game(&game);
}
