/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:58:45 by aivanyan          #+#    #+#             */
/*   Updated: 2022/06/06 19:47:50 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putptr_hex(unsigned long long int num);
int		ft_putptr(unsigned long long ptr);
void	ft_putnbr(unsigned int n);
void	ft_puthex(unsigned int num, char specifier);
ssize_t	ft_putpct(void);
int		ft_printf(const char *format, ...);
void	ft_check_format(va_list ap, char format);
#endif