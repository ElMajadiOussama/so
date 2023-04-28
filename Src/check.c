/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-maj <ouel-maj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:33:05 by ouel-maj          #+#    #+#             */
/*   Updated: 2023/03/02 11:03:46 by ouel-maj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Incl/so_long.h"

bool	check_walls(t_data my_struct)
{
	int	i;

	i = -1;
	while (++i < my_struct.width)
	{
		if (my_struct.matrix[0][i] != '1'
		|| my_struct.matrix[my_struct.height - 1][i] != '1')
		{
			ft_printf("Error\nLa map n'est pas entourée de murs");
			return (false);
		}
	}
	i = 0;
	while (++i < my_struct.height - 1)
	{
		if (my_struct.matrix[i][0] != '1'
		|| my_struct.matrix[i][my_struct.width - 1] != '1')
		{
			ft_printf("Error\nLa map n'est pas entourée de murs");
			return (false);
		}
	}
	return (true);
}

bool	check_different(t_data my_struct)
{
	int	i;
	int	j;

	i = -1;
	while (++i < my_struct.height)
	{
		j = -1;
		while (++j < my_struct.width)
		{
			if (my_struct.matrix[i][j] != '1' && my_struct.matrix[i][j] != 'C'
			&& my_struct.matrix[i][j] != 'P'
			&& my_struct.matrix[i][j] != 'E' && my_struct.matrix[i][j] != '0')
			{
				ft_printf("Error\nCaractère non valide dans la map");
				return (false);
			}
		}
	}
	return (true);
}

int	check_rectangle(t_data my_struct)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < my_struct.height)
	{
		j = 0;
		while (my_struct.matrix[i][j] != '\0')
			j++;
		if (j != my_struct.width)
		{
			ft_printf("Error\nLa map n'est pas un rectangle");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (1);
}

bool	check_exit_player_coin(t_data *my_struct)
{
	my_struct->x = -1;
	while (++my_struct->x < my_struct->height)
	{
		my_struct->y = -1;
		while (++my_struct->y < my_struct->width)
		{
			count_player_exit_coin(my_struct);
		}
	}
	if (my_struct->check_p != 1 || my_struct->check_e != 1
		|| my_struct->coin == 0)
	{
		ft_printf("Error\nIl n'y a pas de joueur, de sortie ou de pièce");
		return (false);
	}
	return (true);
}

int	path_find(t_data *my_struct, int i, int j)
{
	char	up;
	char	down;
	char	left;
	char	right;

	up = my_struct->matrix_path_find[i - 1][j];
	down = my_struct->matrix_path_find[i + 1][j];
	left = my_struct->matrix_path_find[i][j - 1];
	right = my_struct->matrix_path_find[i][j + 1];
	if (my_struct->check_e == 0)
		return (0);
	if (my_struct->matrix_path_find[i][j] == 'E')
		my_struct->check_e--;
	my_struct->matrix_path_find[i][j] = '9';
	if (up != '1' && up != '9')
		path_find(my_struct, i - 1, j);
	if (down != '1' && down != '9')
		path_find(my_struct, i + 1, j);
	if (left != '1' && left != '9')
		path_find(my_struct, i, j - 1);
	if (right != '1' && right != '9')
		path_find(my_struct, i, j + 1);
	if (my_struct->check_e == 0)
		return (0);
	return (-1);
}
