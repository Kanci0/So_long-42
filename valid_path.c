/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:06:20 by dtoszek           #+#    #+#             */
/*   Updated: 2024/05/30 14:16:34 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	map_malloc_path(t_game *game, int fd)
{
	int		i;
	char	*c;
	int		y;

	i = 0;
	y = game->line + 1;
	game->map_floodfill = (char **)malloc(sizeof(char *) * y);
	if (!game->map_floodfill)
		free_img(game);
	while (i < y)
	{
		c = get_next_line(fd);
		game->map_floodfill[i] = ft_strtrim(c, "\n");
		i++;
		free(c);
	}
}

bool	fill(t_game *game, char c, int line, int col)
{
	static bool		exit = false;
	static int		cols = 0;

	if (line < 0 || col < 0 || line >= game->line || col >= game->col)
		return (false);
	else if (game->map_floodfill[line][col] == 'X')
		return (false);
	else if (game->map_floodfill[line][col] == '1')
		return (false);
	else if (game->map_floodfill[line][col] == 'E')
		exit = true;
	if (game->map_floodfill[line][col] == 'C')
		cols++;
	game->map_floodfill[line][col] = 'X';
	fill(game, c, line + 1, col);
	fill(game, c, line, col + 1);
	fill(game, c, line - 1, col);
	fill(game, c, line, col - 1);
	return (cols == game->score && exit);
}

int	floodfill(t_game *game)
{
	char	b;
	int		line;
	int		col;
	bool	valid;

	b = game->map_floodfill[game->player_y][game->player_x];
	line = game->player_y;
	col = game->player_x;
	valid = fill(game, b, line, col);
	return (valid);
}

void	valid_path(t_game *game, int fd)
{
	map_malloc_path(game, fd);
	if (!floodfill(game))
	{
		ft_printf("Error\nInvalid path on map\n");
		free_img(game);
		close(fd);
	}
	free_map_floodfill(game);
}
