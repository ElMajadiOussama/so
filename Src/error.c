/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-maj <ouel-maj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:33:10 by ouel-maj          #+#    #+#             */
/*   Updated: 2023/03/02 09:47:51 by ouel-maj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Incl/so_long.h"

int	error_display(int error_num, int nb_argc)
{
	if (error_num == 1)
		ft_printf ("Error\nVous avez entré %d arguments.\n", nb_argc);
	exit(EXIT_FAILURE);
}

int	verif_ber(char *str)
{
	int	x;

	ft_strlen(str);
	x = ft_strlen(str);
	x--;
	if (str[x] == 'r')
	{
		x--;
		if (str[x] == 'e')
		{
			x--;
			if (str[x] == 'b')
			{
				x--;
				if (str[x] == '.')
					return (1);
			}
		}
	}
	else
	{
		ft_printf("\nError\nLa map doit être de type .ber\n");
		exit(EXIT_FAILURE);
	}
	return (1);
}

int	error_argc2(int argc, char **argv)
{
	int	i;
	int	x;

	i = 1;
	x = 0;
	while (i < argc)
	{
		if (i == 1)
		{
			while (argv[x])
			{
				verif_ber(argv[i]);
				x++;
			}
		}
		i++;
	}
	return (0);
}

int	exit_window(t_data *my_struct)
{
	destroy_img(my_struct);
	exit(EXIT_SUCCESS);
}

void	quit(t_data *my_struct)
{
	mlx_destroy_window(my_struct->mlx, my_struct->win);
	exit (0);
}
