/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:37:45 by inowak--          #+#    #+#             */
/*   Updated: 2024/11/28 13:27:13 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/ft_printf/ft_printf.h"
# include "lib/gnl/get_next_line.h"
# include "lib/minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

//////////////////////
// define : display //
//////////////////////

# define TS 32

////////////////////
// struct : point //
////////////////////

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

////////////////////
// struct : data  //
////////////////////

typedef struct s_data
{
	char	**map;
	void	*wall;
	void	*empty;
	void	*object;
	void	*player;
	void	*exit;
	void	*mlx;
	void	*win;
	int		count_move;
	int		count_star;
	int		total_star;
	t_point	exit_position;
}			t_data;

////////////////////
// struct : count //
////////////////////

typedef struct s_count
{
	int		c;
	int		e;
	int		p;
}			t_count;

//////////////////////////////////////
//----------- ft_itoa.c ------------//
//////////////////////////////////////

char		*ft_itoa(int n);

//////////////////////////////////////
//------------ clean.c -------------//
//////////////////////////////////////

void		cleanup(t_data *data);
void		free_images(t_data *params);
char		**ft_free_map(char **map);
int			ft_check_fd(int fd);

//////////////////////////////////////
//----------- display.c ------------//
//////////////////////////////////////

// void	render_tile(t_data *params, int x, int y, char tile);
void		load_images(t_data *params);
void		init_window(t_data *params, char **argv);
void		render_map(t_data *params, char **map);

//////////////////////////////////////
//--------- move_player.c ----------//
//////////////////////////////////////

void		exit_map(t_data *data);
int			exit_hook(void *params);
t_point		ft_locate(char **map, char c);
// char	**ft_move(t_data *data, int x, int y);
int			key_press(int keycode, void *param);

//////////////////////////////////////
//---------- flood_fill.c ----------//
//////////////////////////////////////

// int flood_fill(char **map, t_point start);
int			ft_count_char(char **map, char c);
int			main_extension(char **argv);

//////////////////////////////////////
//-------- ft_check_len_3.c --------//
//////////////////////////////////////

int			ft_check_len_3(char **argv);

//////////////////////////////////////
//--------- ft_build_map.c ---------//
//////////////////////////////////////

size_t		ft_count_line(char **argv);
// char	*ft_map_extension(int j, char *line, char **map);
char		**ft_map(char **argv);

//////////////////////////////////////
//--------- ft_check_map.c ---------//
//////////////////////////////////////

// int		ft_check_line(char *line);
// int		ft_check_start_last(char **map);
// int		ft_check_len(char **map);
// int		ft_check_map_extension_1(char **map);
char		**ft_check_map(char **map, char **argv);

//////////////////////////////////////
//-------- ft_print_bonus.c --------//
//////////////////////////////////////

void		ft_print_bonus(t_data *params);

#endif