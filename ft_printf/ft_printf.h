/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-maj <ouel-maj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:03:37 by ouel-maj          #+#    #+#             */
/*   Updated: 2023/03/01 12:18:41 by ouel-maj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_printchar(char c);
size_t	ftt_strlen(const char *str);
char	*ft_strdup(const char *s1);
int		ft_checklen(int n);
int		ft_printnbr(int len);
char	*ft_itoa(int n);
int		ft_printstr(char *str);
int		ft_printf(const char *str, ...);
int		ft_printpercent(void);
int		ft_num_len(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		ft_printunsigned(unsigned int n);
int		ft_hex_len(unsigned	int num);
void	ft_put_hex(unsigned int num, const char format);
int		ft_printhexa(unsigned int num, const char format);
void	ft_putchar_fd(char c, int fd);
int		ft_ptr_len(uintptr_t num);
void	ft_put_ptr(uintptr_t num);
int		ft_print_ptr(unsigned long long ptr);
#endif