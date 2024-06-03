/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:32:48 by dtoszek           #+#    #+#             */
/*   Updated: 2024/06/01 12:28:07 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static void	choose(int x, int y, void *c, t_game *game)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = "Movements : ";
	str2 = ft_itoa(game->move - 1);
	str3 = ft_strjoin(str1, str2);
	free(str2);
	mlx_put_image_to_window(game->mlx, game->win, c,
		x * 64, y * 64);
	mlx_string_put(game->mlx, game->win, 30, 30, 0xFFFFFF, str3);
	free(str3);
}

int	collectible_counter(t_game *game)
{
	int		x;
	int		y;
	int		c;

	x = 0;
	y = 0;
	c = 0;
	while (x < game->line)
	{
		while (y < game->col)
		{
			if (game->map[x][y] == 'C')
				c++;
			y++;
		}
		y = 0;
		x++;
	}
	return (c);
}

void	player_position(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (x < game->line)
	{
		while (y < game->col)
		{
			if (game->map[x][y] == 'P')
			{
				game->player_x = y;
				game->player_y = x;
			}
			y++;
		}
		y = 0;
		x++;
	}
}

void	put_images(t_game *game)
{
	int		len;

	len = 64;
	game->img.wall = mlx_xpm_file_to_image(game->mlx, WALL, &len, &len);
	game->img.front = mlx_xpm_file_to_image(game->mlx, FRONT, &len, &len);
	game->img.right = mlx_xpm_file_to_image(game->mlx, RIGHT, &len, &len);
	game->img.back = mlx_xpm_file_to_image(game->mlx, BACK, &len, &len);
	game->img.left = mlx_xpm_file_to_image(game->mlx, LEFT, &len, &len);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &len, &len);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, EXIT, &len, &len);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx, COL, &len, &len);
	game->img.on_box = mlx_xpm_file_to_image(game->mlx, STACKED, &len, &len);
}

void	put_map(int x, int y, char c, t_game *game)
{
	if (c == '1')
		choose(x, y, game->img.wall, game);
	if (c == '0')
		choose(x, y, game->img.floor, game);
	if (c == 'P' && game->key == 'W')
		choose(x, y, game->img.back, game);
	else if (c == 'P' && game->key == 'D')
		choose(x, y, game->img.right, game);
	else if (c == 'P' && game->key == 'S')
		choose(x, y, game->img.front, game);
	else if (c == 'P' && game->key == 'A')
		choose(x, y, game->img.left, game);
	else if (c == 'P')
		choose(x, y, game->img.front, game);
	if (c == 'E')
		choose(x, y, game->img.exit, game);
	if (c == 'C')
		choose(x, y, game->img.collectible, game);
	if (c == 'B')
		choose(x, y, game->img.on_box, game);
}
