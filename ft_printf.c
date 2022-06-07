/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:00:55 by aivanyan          #+#    #+#             */
/*   Updated: 2022/06/07 13:20:45 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = write(1, "0x", 2);
	count += ft_puthex(ptr, 'x', 0);
	return (count);
}

ssize_t	ft_putpct(void)
{
	return (write(1, "%", 1));
}

int	ft_check_format(va_list ap, char format)
{
	int	return_value;

	return_value = 0;
	if (format == 'c')
		return_value += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		return_value += ft_putstr(va_arg(ap, const char *));
	else if (format == 'p')
		return_value += ft_putptr(va_arg(ap, unsigned long long));
	else if (format == 'd' || format == 'i')
		return_value += ft_putnbr(va_arg(ap, int), 0);
	else if (format == 'u')
		return_value += ft_putunnbr(va_arg(ap, unsigned int), 0);
	else if (format == 'x' || format == 'X')
		return_value += ft_puthex(va_arg(ap, unsigned int), format, 0);
	else if (format == '%')
		return_value += ft_putpct();
	return (return_value);
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
			return_value += ft_check_format(ap, format[++i]);
		else
			return_value += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (return_value);
}
