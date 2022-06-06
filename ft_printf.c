/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:00:55 by aivanyan          #+#    #+#             */
/*   Updated: 2022/06/06 20:03:56 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_check_format(va_list ap, char format)
{
	if (format == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (format == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (format == 'p')
		ft_putptr(va_arg(ap, unsigned long long));
	else if (format == 'd' || format == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (format == 'u')
		ft_putnbr(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		ft_puthex(va_arg(ap, unsigned int), format);
	else if (format == '%')
		ft_putpct();
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		return_value;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	return_value = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ft_check_format(ap, format[++i]);
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(ap);
	return (return_value);
}
