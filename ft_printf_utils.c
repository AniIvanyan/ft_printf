/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:18:15 by aivanyan          #+#    #+#             */
/*   Updated: 2022/06/07 00:24:05 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

ssize_t	ft_putstr(char *s)
{
	ssize_t	count;

	count = 0;
	while (s[count])
		write(1, &s[count++], 1);
	return (count);
}

ssize_t	ft_putnbr(int n, ssize_t count)
{
	long	num;

	num = n;
	if (num < 0)
	{
		num = -num;
		count += ft_putchar('-');
	}
	if (num < 10)
		count += ft_putchar(num + '0');
	else
	{
		count += ft_putnbr(num / 10, 0);
		count += ft_putchar(num % 10 + '0');
	}
	return (count);
}

ssize_t	ft_putunnbr(unsigned int n, ssize_t count)
{
	if (n < 10)
		count += ft_putchar(n + '0');
	else
	{
		count += ft_putunnbr(n / 10, 0);
		count += ft_putchar(n % 10 + '0');
	}
	return (count);
}

ssize_t	ft_puthex(unsigned long long num, char specifier, ssize_t count)
{
	if (num >= 16)
	{
		count += ft_puthex(num / 16, specifier, 0);
		count += ft_puthex(num % 16, specifier, 0);
	}
	else
	{
		if (num <= 9)
			count += ft_putchar(num + 48);
		else
		{
			if (specifier == 'x')
				count += ft_putchar(num + 87);
			if (specifier == 'X')
				count += ft_putchar(num + 55);
		}
	}
	return (count);
}
