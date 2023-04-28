/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-maj <ouel-maj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:34:37 by ouel-maj          #+#    #+#             */
/*   Updated: 2023/03/02 11:05:43 by ouel-maj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H 

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct t_data {
	void	*mlx;
	void	*win;
	int		coin;
	int		coin2;
	int		check_e;
	int		check_p;
	int		i;
	int		j;
	int		x;
	int		y;
	int		move_count;
	int		loop;
	int		random;
	void	*map;
	int		width;
	int		height;
	int		end;
	char	**matrix;
	char	**matrix_path_find;
	char	**matrix_coin_find;
	void	**path;
	void	**img;
	int		start;
	int		move;
}				t_data;

char	**ft_split(char const *s, char c, t_data *my_struct);
char	*get_next_line(int fd);
void	initialize(t_data *my_struct);
void	create_img(t_data *my_struct);
int		matrix_filling(t_data *my_struct);
void	put_img(t_data *my_struct, int i, int j);
void	put_map(t_data *my_struct);
int		error_display(int error_num, int nb_argc);
int		error_argc2(int argc, char **argv);
int		verif_ber(char *str);
int		ft_verif(char *str);
int		check(int keycode, t_data *my_struct);
void	quit(t_data *my_struct);
void	move_right(t_data *my_struct);
void	move_left(t_data *my_struct);
void	move_up(t_data *my_struct);
void	move_down(t_data *my_struct);
bool	check_walls(t_data my_struct);
bool	check_different(t_data my_struct);
bool	check_exit_player_coin(t_data *my_struct);
int		check_rectangle(t_data my_struct);
void	destroy_img(t_data *my_struct);
int		path_find(t_data *my_struct, int i, int j);
int		exit_window(t_data *my_struct);
void	path_img(t_data *my_struct);
void	move_right_utils(t_data *my_struct);
void	move_down_utils(t_data *my_struct);
void	move_up_utils(t_data *my_struct);
void	move_left_utils(t_data *my_struct);
int		coin_find(t_data *my_struct, int i, int j);
void	count_player_exit_coin(t_data *my_struct);
#endif