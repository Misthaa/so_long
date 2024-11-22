/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:36:12 by madegryc          #+#    #+#             */
/*   Updated: 2024/01/18 21:41:45 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <memory.h>
# include "../ft_printf/ft_printf.h"
# include "../MacroLibX/includes/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	**img;
	void	**img2;
	char	**a;
	int		x;
	int		y;
	int		xx;
	int		yy;
	int		xm;
	int		ym;
	int		orientation;
	int		start_time;
	int		sprite_state;
	int		sprite_on;
	int		coin;
	int		coin_act;
	int		line;
	int		column;
	int		is_init;
	int		x_exit;
	int		y_exit;
	long	new_time_ms;
	int		time_monster;
	int		sound;
	int		score;
	int		check_mob;
	char	**avm;
}	t_data;

/*	-GET_NEXT_LINE-	*/

int		ft_line_break(char *str, char *buffer);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
char	*get_next_line(int fd);

/*	-SO_LONG-	*/

int		create_game(char *map_path, char **av);
char	*ft_strjoin_sys(char const *s1, char const *s2);
void	destroy_images(t_data *data);
void	close_win(t_data *data, int leave);
void	ft_free_map_checker(char **map, char **map2, t_data *data);
int		window_hook(int event, void *param);
int		ft_check_death(t_data *data);
int		ft_check_coin(t_data *data);
void	init_coin(t_data *data);
int		x_calc(char **a);
int		y_calc(char **a);

/*
	PARSING
*/

int		ft_value_map(int ac);
int		is_ber(char *str);
int		is_valid_map_c(char **str);
int		is_double_bl(char *str);
int		ft_count_line(char **str);
int		ft_count_column(char **str);
char	**flood_fill(char **str);
int		ft_checkall_file(char *map_path, char *strbl, char **str, t_data *data);
int		ft_checkall_map(char **str, t_data *data);
int		is_more_or_less_c(char **str);
int		ft_check_coin(t_data *data);
int		ft_check_death(t_data *data);
int		ft_nope(int y, int x, t_data *data);

/*
	SAVE MAP
*/

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);

int		x_calc(char **a);
int		y_calc(char **a);
void	key_hook(int keycode, t_data *data);
char	*ft_itoa(int n);

/*
	TEXTURE
*/

void	fileimage(t_data *data);
void	fileimage2(t_data *data);
void	fileimage_samou(t_data *data);
void	display_map(t_data *data);
void	random_wall(t_data data);
void	random_floor(t_data data);
void	random_floor_player(t_data data);
void	random_floor_monster(t_data data);

/* 
	ANIMATION
*/

void	sprite_anim_right(void *param);
void	sprite_anim_up(void *param);
void	sprite_anim_left(void *param);
void	sprite_anim_front(void *param);
void	sprite_anim_dash(t_data *data);
void	sprite_anim_soul(void *param);
int		sprite_anim_monstre(void *param);
int		sprite_anim(void *param);

/*
	MOOVE
*/

void	up(t_data *data);
void	down(t_data *data);
void	left(t_data *data);
void	right(t_data *data);

void	up_dash(t_data *data);
void	down_dash(t_data *data);
void	left_dash(t_data *data);
void	right_dash(t_data *data);

void	up_monster(t_data *data);
void	down_monster(t_data *data);
void	left_monster(t_data *data);
void	right_monster(t_data *data);

#endif