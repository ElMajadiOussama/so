/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-maj <ouel-maj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:33:32 by ouel-maj          #+#    #+#             */
/*   Updated: 2023/03/02 09:33:32 by ouel-maj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Incl/so_long.h"

void	move_right_utils(t_data *my_struct)
{
	if (my_struct->matrix[my_struct->i][my_struct->j] == 'X')
	{
		if (my_struct->matrix[my_struct->i][my_struct->j + 1] == 'C')
		{
			my_struct->coin--;
		}
		my_struct->matrix[my_struct->i][my_struct->j + 1] = 'P';
		my_struct->matrix[my_struct->i][my_struct->j] = 'E';
	}
}

void	move_left_utils(t_data *my_struct)
{
	if (my_struct->matrix[my_struct->i][my_struct->j] == 'X')
	{
		if (my_struct->matrix[my_struct->i][my_struct->j - 1] == 'C')
		{
			my_struct->coin--;
		}
		my_struct->matrix[my_struct->i][my_struct->j - 1] = 'P';
		my_struct->matrix[my_struct->i][my_struct->j] = 'E';
	}
}

void	move_up_utils(t_data *my_struct)
{
	if (my_struct->matrix[my_struct->i][my_struct->j] == 'X')
	{
		if (my_struct->matrix[my_struct->i - 1][my_struct->j] == 'C')
		{
			my_struct->coin--;
		}
		my_struct->matrix[my_struct->i - 1][my_struct->j] = 'P';
		my_struct->matrix[my_struct->i][my_struct->j] = 'E';
	}
}

void	move_down_utils(t_data *my_struct)
{
	if (my_struct->matrix[my_struct->i][my_struct->j] == 'X')
	{
		if (my_struct->matrix[my_struct->i + 1][my_struct->j] == 'C')
		{
			my_struct->coin--;
		}
		my_struct->matrix[my_struct->i + 1][my_struct->j] = 'P';
		my_struct->matrix[my_struct->i][my_struct->j] = 'E';
	}
}
