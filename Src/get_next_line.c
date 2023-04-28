/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-maj <ouel-maj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:33:17 by ouel-maj          #+#    #+#             */
/*   Updated: 2023/03/16 10:35:59 by ouel-maj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Incl/so_long.h"

char	*line(char *a, int i)
{
	char	*new_a;

	new_a = malloc(i + 1);
	if (!new_a)
		return (0);
	i = 0;
	while (a[i])
	{
		new_a[i] = a[i];
		i++;
	}
	new_a[i] = '\0';
	return (new_a);
}

char	*get_next_line(int fd)
{
	char	a[999999];
	char	buffer[1];
	char	*new_a;
	int		i;

	if (fd < 0)
		return (NULL);
	i = 0;
	a[i] = 0;
	while (read(fd, buffer, 1) == 1)
	{
		a[i] = buffer[0];
		a[i + 1] = '\0';
		if (a[i] == '\0')
			break ;
		i++;
	}
	new_a = line(a, i);
	return (new_a);
}
