/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-maj <ouel-maj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:33:36 by ouel-maj          #+#    #+#             */
/*   Updated: 2023/03/02 09:33:36 by ouel-maj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Incl/so_long.h"

int	check(int keycode, t_data *my_struct)
{
	my_struct->move_count = my_struct->move - 1;
	if (keycode == 36)
		my_struct->start = 1;
	if (keycode == 53 || keycode == 12)
		quit(my_struct);
	else if (my_struct->start != 0)
	{
		if (my_struct->end == 1)
			return (0);
		if (keycode == 13 || keycode == 126)
			move_up(my_struct);
		if (keycode == 0 || keycode == 123)
			move_left(my_struct);
		if (keycode == 1 || keycode == 125)
			move_down(my_struct);
		if (keycode == 2 || keycode == 124)
			move_right(my_struct);
		put_map(my_struct);
		while (my_struct->move != ++my_struct->move_count)
			ft_printf("\n%d", my_struct->move);
		return (1);
	}
	return (0);
}

void	move_right(t_data *my_struct)
{
	if (my_struct->matrix[my_struct->i][my_struct->j + 1] == '1')
		return ;
	move_right_utils(my_struct);
	if (my_struct->matrix[my_struct->i][my_struct->j + 1] == '0')
	{
		my_struct->matrix[my_struct->i][my_struct->j] = '0';
		my_struct->matrix[my_struct->i][my_struct->j + 1] = 'P';
	}
	else if (my_struct->matrix[my_struct->i][my_struct->j + 1] == 'E'
			&& my_struct->coin == 0)
		return (quit(my_struct));
	else if (my_struct->matrix[my_struct->i][my_struct->j + 1] == 'E')
	{
		my_struct->matrix[my_struct->i][my_struct->j + 1] = 'X';
		my_struct->matrix[my_struct->i][my_struct->j] = '0';
	}
	else if (my_struct->matrix[my_struct->i][my_struct->j + 1] == 'C')
	{
		my_struct->coin--;
		my_struct->matrix[my_struct->i][my_struct->j + 1] = 'P';
		my_struct->matrix[my_struct->i][my_struct->j] = '0';
	}
	my_struct->move++;
	my_struct->j++;
}

void	move_left(t_data *my_struct)
{
	if (my_struct->matrix[my_struct->i][my_struct->j - 1] == '1')
		return ;
	move_left_utils(my_struct);
	if (my_struct->matrix[my_struct->i][my_struct->j - 1] == '0')
	{
		my_struct->matrix[my_struct->i][my_struct->j] = '0';
		my_struct->matrix[my_struct->i][my_struct->j - 1] = 'P';
	}
	else if (my_struct->matrix[my_struct->i][my_struct->j - 1] == 'E'
			&& my_struct->coin == 0)
		return (quit(my_struct));
	else if (my_struct->matrix[my_struct->i][my_struct->j - 1] == 'E')
	{
		my_struct->matrix[my_struct->i][my_struct->j - 1] = 'X';
		my_struct->matrix[my_struct->i][my_struct->j] = '0';
	}
	else if (my_struct->matrix[my_struct->i][my_struct->j - 1] == 'C')
	{
		my_struct->coin--;
		my_struct->matrix[my_struct->i][my_struct->j - 1] = 'P';
		my_struct->matrix[my_struct->i][my_struct->j] = '0';
	}
	my_struct->move++;
	my_struct->j--;
}

void	move_up(t_data *my_struct)
{
	if (my_struct->matrix[my_struct->i - 1][my_struct->j] == '1')
		return ;
	move_up_utils(my_struct);
	if (my_struct->matrix[my_struct->i - 1][my_struct->j] == '0')
	{
		my_struct->matrix[my_struct->i][my_struct->j] = '0';
		my_struct->matrix[my_struct->i - 1][my_struct->j] = 'P';
	}
	else if (my_struct->matrix[my_struct->i - 1][my_struct->j] == 'E'
			&& my_struct->coin == 0)
		return (quit(my_struct));
	else if (my_struct->matrix[my_struct->i - 1][my_struct->j] == 'E')
	{
		my_struct->matrix[my_struct->i - 1][my_struct->j] = 'X';
		my_struct->matrix[my_struct->i][my_struct->j] = '0';
	}
	else if (my_struct->matrix[my_struct->i - 1][my_struct->j] == 'C')
	{
		my_struct->coin--;
		my_struct->matrix[my_struct->i - 1][my_struct->j] = 'P';
		my_struct->matrix[my_struct->i][my_struct->j] = '0';
	}
	my_struct->move++;
	my_struct->i--;
}

void	move_down(t_data *my_struct)
{
	if (my_struct->matrix[my_struct->i + 1][my_struct->j] == '1')
		return ;
	move_down_utils(my_struct);
	if (my_struct->matrix[my_struct->i + 1][my_struct->j] == '0')
	{
		my_struct->matrix[my_struct->i][my_struct->j] = '0';
		my_struct->matrix[my_struct->i + 1][my_struct->j] = 'P';
	}
	else if (my_struct->matrix[my_struct->i + 1][my_struct->j] == 'E'
			&& my_struct->coin == 0)
		return (quit(my_struct));
	else if (my_struct->matrix[my_struct->i + 1][my_struct->j] == 'E')
	{
		my_struct->matrix[my_struct->i + 1][my_struct->j] = 'X';
		my_struct->matrix[my_struct->i][my_struct->j] = '0';
	}
	else if (my_struct->matrix[my_struct->i + 1][my_struct->j] == 'C')
	{
		my_struct->coin--;
		my_struct->matrix[my_struct->i + 1][my_struct->j] = 'P';
		my_struct->matrix[my_struct->i][my_struct->j] = '0';
	}
	my_struct->move++;
	my_struct->i++;
}
