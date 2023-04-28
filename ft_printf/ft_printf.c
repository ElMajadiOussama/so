/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-maj <ouel-maj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:50:46 by ouel-maj          #+#    #+#             */
/*   Updated: 2022/12/29 17:50:27 by ouel-maj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	format(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		print_length += ft_printnbr(va_arg(args, int));
	else if (format == '%')
		print_length += ft_printpercent();
	else if (format == 'u')
		print_length += ft_printunsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_printhexa(va_arg(args, unsigned int), format);
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long long));
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print_length;
	va_list	args;

	print_length = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += format(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}

// #include<stdio.h>
// int	main(void)
// {
// 	char	a;
// 	char	*b;

// 	b = "hello";
// 	a = 'n';
// 	ft_printf("%1c, %1c, %1c\n", '5', 'x', '\n');
// 	printf("printf; %1c, %1c, %1c", '5', 'x', '\n');
// }
