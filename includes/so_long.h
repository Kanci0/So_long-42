/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:55:47 by dtoszek           #+#    #+#             */
/*   Updated: 2024/06/01 13:51:41 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

# define FRONT "./png/front.xpm"
# define RIGHT "./png/rightside.xpm"
# define LEFT "./png/leftside.xpm"
# define BACK "./png/backwards.xpm"
# define EXIT "./png/exit.xpm"
# define WALL "./png/background.xpm"
# define COL "./png/collectabilites.xpm"
# define FLOOR "./png/floor.xpm"
# define STACKED "./png/on_box.xpm"

# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_imgs
{
	void	*collectible;
	void	*front;
	void	*right;
	void	*left;
	void	*back;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*on_box;
}	t_imgs;

typedef struct s_game
{
	t_imgs	img;
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_floodfill;
	char	temp;
	char	key;
	int		line;
	int		col;
	int		exit;
	int		score;
	int		player;
	int		player_on_box;
	int		player_y;
	int		player_x;
	int		end_game;
	int		move;
}	t_game;

// finis_game.c
void	free_img(t_game *game);
void	ft_exit(char *s, t_game *game);
int		close_window(t_game *game);
void	free_map_floodfill(t_game *game);
void	free_map(t_game *game);

// keys
int		key_handler(int keycode, t_game *game);

// valids
void	check_args(t_game *game, int argc, char *argv[]);
void	valid_map(t_game *game);
void	check_map(t_game *game);

// sizes
int		get_line_size(t_game *game, int fd);
int		get_col_size(t_game *game, int fd);

// load maps chars
void	get_map(t_game *game, int fd);

// rendering chosen img
int		render_img(t_game *game);

// flood fill
void	map_malloc_path(t_game *game, int fd);
bool	fill(t_game *game, char c, int line, int col);
int		floodfill(t_game *game);
void	valid_path(t_game *game, int fd);

void	put_images(t_game *game);
int		collectible_counter(t_game *game);
void	player_position(t_game *game);
void	put_map(int x, int y, char c, t_game *game);
void	validate(t_game *game, int fd);

#endif
