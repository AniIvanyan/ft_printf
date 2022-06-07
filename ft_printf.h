/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:58:45 by aivanyan          #+#    #+#             */
/*   Updated: 2022/06/07 13:23:48 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

ssize_t	ft_putchar(char c);
ssize_t	ft_putstr(const	char *s);
ssize_t	ft_putnbr(int n, ssize_t count);
ssize_t	ft_putunnbr(unsigned int n, ssize_t count);
ssize_t	ft_puthex(unsigned long long num, char specifier, ssize_t count);
int		ft_putptr(unsigned long long ptr);
ssize_t	ft_putpct(void);
int		ft_check_format(va_list ap, char format);
int		ft_printf(const char *format, ...);

#endif