/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-maj <ouel-maj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:33:22 by ouel-maj          #+#    #+#             */
/*   Updated: 2023/03/02 11:00:09 by ouel-maj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Incl/so_long.h"

int	matrix_filling(t_data *my_struct)
{
	int		fd;
	char	*line;

	my_struct->width = 0;
	my_struct->end = 0;
	fd = open(my_struct->map, O_RDONLY);
	line = get_next_line(fd);
	my_struct->matrix = ft_split(line, '\n', my_struct);
	my_struct->matrix_path_find = ft_split(line, '\n', my_struct);
	my_struct->matrix_coin_find = ft_split(line, '\n', my_struct);
	while (my_struct->matrix[0][my_struct->width] != '\0')
		my_struct->width++;
	if (!check_walls(*my_struct) || !check_exit_player_coin(my_struct)
		|| !check_different(*my_struct) || !check_rectangle(*my_struct))
		exit(EXIT_FAILURE);
	if (coin_find(my_struct, my_struct->i, my_struct->j) < 0
		|| path_find(my_struct, my_struct->i, my_struct->j) < 0)
	{
		ft_printf("Error\nSortie/Piece non accessible");
		exit (EXIT_FAILURE);
	}
	close(fd);
	free(line);
	return (1);
}

int	coin_find(t_data *my_struct, int i, int j)
{
	char	up;
	char	down;
	char	left;
	char	right;

	up = my_struct->matrix_coin_find[i - 1][j];
	down = my_struct->matrix_coin_find[i + 1][j];
	left = my_struct->matrix_coin_find[i][j - 1];
	right = my_struct->matrix_coin_find[i][j + 1];
	if (my_struct->coin2 == 0)
		return (0);
	if (my_struct->matrix_coin_find[i][j] == 'C')
		my_struct->coin2--;
	my_struct->matrix_coin_find[i][j] = '9';
	if (up != '1' && up != '9')
		coin_find(my_struct, i - 1, j);
	if (down != '1' && down != '9')
		coin_find(my_struct, i + 1, j);
	if (left != '1' && left != '9')
		coin_find(my_struct, i, j - 1);
	if (right != '1' && right != '9')
		coin_find(my_struct, i, j + 1);
	if (my_struct->coin2 == 0)
		return (0);
	return (-1);
}
