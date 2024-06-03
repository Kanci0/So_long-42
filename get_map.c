/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:18:42 by dtoszek           #+#    #+#             */
/*   Updated: 2024/06/03 10:19:56 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	get_map(t_game *game, int fd)
{
	int		i;
	int		y;
	char	*c;

	i = 0;
	y = game->line + 1;
	game->map = (char **)malloc(sizeof(char *) * y);
	if (!game->map)
		ft_exit("Error\n", game);
	while (i < y)
	{
		c = get_next_line(fd);
		game->map[i] = ft_strtrim(c, "\n");
		i++;
		free(c);
	}
}
