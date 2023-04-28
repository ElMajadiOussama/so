/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-maj <ouel-maj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:06:58 by ouel-maj          #+#    #+#             */
/*   Updated: 2023/03/01 12:25:02 by ouel-maj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;
	char	*x;

	i = 0;
	x = ((dest = (char *)malloc(ftt_strlen(s1) * sizeof(char) + 1)));
	if (!x)
	{
		return (0);
	}
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_checklen(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;
	char	modulo;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_checklen(n);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	if (n < 0)
		res[0] = '-';
	res[len] = '\0';
	while (n != 0)
	{
		len--;
		modulo = n % 10;
		if (n < 0)
			modulo *= -1;
		res[len] = modulo + '0';
		n /= 10;
	}
	return (res);
}

int	ft_printnbr(int len)
{
	char	*c;

	c = ft_itoa(len);
	len = ft_printstr(c);
	free(c);
	return (len);
}
