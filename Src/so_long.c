/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-maj <ouel-maj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:33:47 by ouel-maj          #+#    #+#             */
/*   Updated: 2023/03/02 10:48:09 by ouel-maj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Incl/so_long.h"

void	initialize(t_data *my_struct)
{
	my_struct->check_e = 0;
	my_struct->check_p = 0;
	my_struct->coin = 0;
	my_struct->coin2 = 0;
	my_struct->move = 0;
}

int	main(int argc, char **argv)
{
	t_data	my_struct;

	if (argc != 2)
		error_display(1, argc);
	error_argc2(argc, argv);
	initialize(&my_struct);
	my_struct.map = argv[1];
	if (matrix_filling(&my_struct) == 0)
		exit(EXIT_FAILURE);
	my_struct.mlx = mlx_init();
	create_img(&my_struct);
	my_struct.win = mlx_new_window(my_struct.mlx,
			my_struct.width * 32, my_struct.height * 32, "So_long");
	put_map(&my_struct);
	my_struct.loop = 0;
	mlx_hook(my_struct.win, 17, 0, &exit_window, &my_struct);
	mlx_hook(my_struct.win, 3, 0, check, &my_struct);
	mlx_loop(my_struct.mlx);
}
