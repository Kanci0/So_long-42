/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:35:40 by dtoszek           #+#    #+#             */
/*   Updated: 2024/06/03 10:19:39 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	get_line_size(t_game *game, int fd)
{
	char	*c;
	int		x;

	x = 0;
	(void)game;
	while (1)
	{
		c = get_next_line(fd);
		if (!c)
			break ;
		x++;
		free(c);
	}
	if (x == 0)
	{
		ft_printf("Error\nFile empty or does not exist.");
		exit(0);
	}
	return (x);
}

int	get_col_size(t_game *game, int fd)
{
	char	*c;
	int		y;
	int		temp;

	(void)game;
	c = get_next_line(fd);
	y = ft_strlen(c) - 1;
	temp = y;
	(void)temp;
	free(c);
	if (fd < 0)
		ft_exit("Error\nEmpty fd", game);
	while (1)
	{
		c = get_next_line(fd);
		if (!c)
			break ;
		y = ft_strlen(c) - 1;
		if (y != temp)
			y = temp;
		free(c);
	}
	return (y);
}
