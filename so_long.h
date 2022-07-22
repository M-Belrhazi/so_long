/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:36:10 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/07/22 19:37:37 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs/minilibx/mlx.h"
# include "libs/libftprintf/libftprintf.h"
# include "stdio.h"
# include "unistd.h"
# include "string.h"
# include "stdlib.h"
# include "time.h"
# include "sys/stat.h"
# include "fcntl.h"

/*############################################################################*/
/*                                DEFINITIONS                                 */
/*############################################################################*/

/*
	PIX is for the number of pixels per move of the player
*/

# ifndef PIX
#  define PIX 2
# endif

/*
	SD is for slow down, the higher SD is, the slower the player goes
	Definitions of multiple SDs for different map sizes
*/

# ifndef SD1
#  define SD1 14
# endif

# ifndef SD2
#  define SD2 2
# endif

# ifndef SD3
#  define SD3 1
# endif

# define ZERO "imgs/nb/0.xpm"
# define ONE "imgs/nb/1.xpm"
# define TWO "imgs/nb/2.xpm"
# define THREE "imgs/nb/3.xpm"
# define FOUR "imgs/nb/4.xpm"
# define FIVE "imgs/nb/5.xpm"
# define SIX "imgs/nb/6.xpm"
# define SEVEN "imgs/nb/7.xpm"
# define EIGHT "imgs/nb/8.xpm"
# define NINE "imgs/nb/9.xpm"

typedef struct s_tile
{
	void	*tile;
	int		width;
	int		height;
	int		bpp;
	int		line_size;
	int		endian;
	int		x_tile;
	char	*data;
}	t_tile;

typedef struct s_img {
	void	*img;
	t_tile	*tile;
	t_tile	*player_br[4];
	t_tile	*player[4];
	t_tile	*enemy;
	t_tile	*new_enemy;
	t_tile	*wall[2];
	t_tile	*col[2];
	t_tile	*exit;
	t_tile	numbers[10];
	int		width;
	int		height;
	int		bpp;
	int		line_size;
	int		endian;
	char	*data;
}	t_img;

typedef struct s_data {
	void	*mlx;
	int		tiles[26];
	int		pos_x;
	int		pos_y;
	int		pos_enemy_x;
	int		pos_enemy_y;
	int		colls;
	int		nb_moves;
	int		broom;
	int		down[4];
	void	*win;
	char	**map;
	t_img	*img;
}	t_data;

/*############################################################################*/
/*                             MAPPING FUNCTIONS                              */
/*############################################################################*/

int		fill_map(char ***map, char *ol_map);
char	*find_first_line(char *line, int fd);
int		fill_one_line_map(int fd, char ***map);
void	ft_free(char *line, char *ol_map);
size_t	ft_strlen_no_nl(char *str);
int		nl_ol_map(char *str);
void	free_map(char **map);
void	ret_write(int return_nb);
int		walls_map(char **map);
int		invalid_char_map(char **map);
int		exit_map(char **map);
int		col_map(char **map);
int		player_map(char **map);
void	ret_4_write(void);
void	ret_3_write(void);
void	ret_2_write(void);
void	ret_1_write(void);
void	ret_0_write(void);

/*############################################################################*/
/*                             DISPLAY FUNCTIONS                              */
/*############################################################################*/

int		render_map(t_data *data);
void	handle_moves(t_data *data);
int		ft_height_win(char **map);
int		ft_width_win(char **map);
void	render_tile(char c, size_t i, size_t j, t_data *data);
void	render_tile_continue(char c, int x, int y, t_data *data);
void	put_tile_to_image(t_img *img, t_tile *tile, int x, int y);
void	render_player(t_data *data);
void	render_player_br(t_data *data);
void	put_player_to_image(t_img *img, int x, int y, t_tile *player);

/*############################################################################*/
/*                             DESTROY FUNCTIONS                              */
/*############################################################################*/

int		ft_close(t_data *data);
void	ft_close_mlx(t_data *data);
void	ft_close_window(t_data *data);
void	ft_destroy_image(t_data *data);
void	ft_destroy_player(t_data *data);
void	ft_destroy_numbers(t_data *data);

/*############################################################################*/
/*                            TILE INIT FUNCTIONS                             */
/*############################################################################*/

int		ft_init_tiles(t_data *data);
int		init_player_br(t_data *data);
int		init_player(t_data *data);
int		init_new_enemy(t_data *data);
int		init_enemy(t_data *data);
int		init_col(t_data *data);
int		init_wall(t_data *data);
int		init_exit(t_data *data);
int		init_tile(t_data *data);
void	ft_init_data_tab_tiles(t_data *data);
int		init_player_continue(t_data *data, t_tile *player);
int		init_player_br_continue(t_data *data, t_tile *player_br);
int		init_numbers(t_data *data);
int		init_numbers_0_4(t_data *data);
int		init_numbers_5_9(t_data *data);

/*############################################################################*/
/*                             HANDLER FUNCTIONS                              */
/*############################################################################*/

int		handle_keyrelease(int key, t_data *data);
int		handle_keypress(int key, t_data *data);

/*############################################################################*/
/*                              MOVES FUNCTIONS                               */
/*############################################################################*/

void	move_right(t_data *data);
void	move_enemy_right(t_data *data);
void	move_left(t_data *data);
void	move_enemy_left(t_data *data);
void	move_down(t_data *data);
void	move_enemy_down(t_data *data);
void	move_up(t_data *data);
void	move_enemy_up(t_data *data);
void	win_game(t_data *data, int pos_x, int pos_y);
void	lose_game(t_data *data, int pos_x, int pos_y);
int		no_move(t_data *data, int pos_x, int pos_y);
void	get_coll(t_data *data);

/*############################################################################*/
/*                             PARSING FUNCTIONS                              */
/*############################################################################*/

int		parse(char *file, char ***map);
int		find_error(char *str);

/*############################################################################*/
/*                             INITIAL FUNCTIONS                              */
/*############################################################################*/

int		ft_mlx(char **map);
void	ft_init_data(t_data *data, char **map);
void	ft_init_pos_enemy(t_data *data, char **map);
int		get_nb_colls(char **map);

/*############################################################################*/
/*                              BONUS FUNCTIONS                               */
/*############################################################################*/

void	put_enemy_to_image(t_img *img, int x, int y, char *data_tile);
char	*create_new_data(t_tile *enemy, t_tile *new_enemy);
void	render_enemy(t_data *data);
void	render_enemy_continue(t_data *data);
void	exec_move_enemy(t_data *data, int nb);

#endif
