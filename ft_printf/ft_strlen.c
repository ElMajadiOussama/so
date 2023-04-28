/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-maj <ouel-maj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:08:46 by ouel-maj          #+#    #+#             */
/*   Updated: 2023/03/01 12:18:44 by ouel-maj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// int ft_strlen(char *str)
// {
//     int i;

//     i = 0;
//     while (str[i])
//     {
//         i++;
//     }
//     return (i);
// }
size_t	ftt_strlen( const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
