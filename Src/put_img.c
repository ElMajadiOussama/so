/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-maj <ouel-maj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:32:41 by ouel-maj          #+#    #+#             */
/*   Updated: 2023/03/02 09:32:44 by ouel-maj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Incl/so_long.h"

void	path_img(t_data *my_struct)
{
	my_struct->path = (void **)malloc(sizeof(void **) * 7);
	if (!my_struct->path)
		return ;
	my_struct->img = (void **)malloc(sizeof(void **) * 7);
	if (!my_struct->img)
		return ;
	my_struct->path[0] = "./image/layers.xpm";
	my_struct->path[1] = "./image/wall.xpm";
	my_struct->path[2] = "./image/player.xpm";
	my_struct->path[3] = "./image/open_exit.xpm";
	my_struct->path[4] = "./image/exit.xpm";
	my_struct->path[5] = "./image/coin.xpm";
	my_struct->path[6] = "./image/player_on_exit.xpm";
}

void	create_img(t_data *my_struct)
{
	int	x;
	int	y;
	int	index;

	path_img(my_struct);
	index = -1;
	while (++index < 7)
		my_struct->img[index] = mlx_xpm_file_to_image(my_struct->mlx,
				my_struct->path[index], &x, &y);
	if (!my_struct->img[0] || !my_struct->img[1] || !my_struct->img[2]
		|| !my_struct->img[3] || !my_struct->img[4] || !my_struct->img[5])
	{
		destroy_img(my_struct);
		ft_printf("%s", "Error\n");
		exit(EXIT_FAILURE);
	}
}

void	destroy_img(t_data *my_struct)
{
	if (my_struct->img[0])
		mlx_destroy_image(my_struct->mlx, my_struct->img[0]);
	if (my_struct->img[1])
		mlx_destroy_image(my_struct->mlx, my_struct->img[1]);
	if (my_struct->img[2])
		mlx_destroy_image(my_struct->mlx, my_struct->img[2]);
	if (my_struct->img[3])
		mlx_destroy_image(my_struct->mlx, my_struct->img[3]);
	if (my_struct->img[4])
		mlx_destroy_image(my_struct->mlx, my_struct->img[4]);
	if (my_struct->img[5])
		mlx_destroy_image(my_struct->mlx, my_struct->img[5]);
}

void	put_img(t_data *my_struct, int i, int j)
{
	if (my_struct->matrix[i][j] == '0')
		mlx_put_image_to_window(my_struct->mlx,
			my_struct->win, my_struct->img[0], j * 32, i * 32);
	if (my_struct->matrix[i][j] == '1')
		mlx_put_image_to_window(my_struct->mlx,
			my_struct->win, my_struct->img[1], j * 32, i * 32);
	if (my_struct->matrix[i][j] == 'C')
		mlx_put_image_to_window(my_struct->mlx,
			my_struct->win, my_struct->img[5], j * 32, i * 32);
	if (my_struct->matrix[i][j] == 'P')
		mlx_put_image_to_window(my_struct->mlx,
			my_struct->win, my_struct->img[2], j * 32, i * 32);
	if (my_struct->matrix[i][j] == 'X')
		mlx_put_image_to_window(my_struct->mlx,
			my_struct->win, my_struct->img[6], j * 32, i * 32);
	if (my_struct->coin == 0 && my_struct->matrix[i][j] == 'E')
		mlx_put_image_to_window(my_struct->mlx,
			my_struct->win, my_struct->img[3], j * 32, i * 32);
	else if (my_struct->matrix[i][j] == 'E')
		mlx_put_image_to_window(my_struct->mlx,
			my_struct->win, my_struct->img[4], j * 32, i * 32);
}

void	put_map(t_data *my_struct)
{
	int	i;
	int	j;

	i = -1;
	while (++i < my_struct->height)
	{
		j = -1;
		while (++j < my_struct->width)
			put_img(my_struct, i, j);
	}
}
