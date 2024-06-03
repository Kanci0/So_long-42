/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:51:02 by dtoszek           #+#    #+#             */
/*   Updated: 2024/06/03 10:16:25 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	validate(t_game *game, int fd)
{
	ft_printf("Starting validations\n");
	check_map(game);
	valid_map(game);
	valid_path(game, fd);
}
