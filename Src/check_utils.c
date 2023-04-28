/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-maj <ouel-maj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:01:12 by ouel-maj          #+#    #+#             */
/*   Updated: 2023/03/02 11:05:19 by ouel-maj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Incl/so_long.h"

void	count_player_exit_coin(t_data *my_struct)
{
	if (my_struct->matrix[my_struct->x][my_struct->y] == 'P')
	{
		my_struct->i = my_struct->x;
		my_struct->j = my_struct->y;
		my_struct->check_p++;
	}
	if (my_struct->matrix[my_struct->x][my_struct->y] == 'E')
		my_struct->check_e++;
	if (my_struct->matrix[my_struct->x][my_struct->y] == 'C')
	{
		my_struct->coin++;
		my_struct->coin2++;
	}
}
