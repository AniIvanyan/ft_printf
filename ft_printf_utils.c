/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:18:15 by aivanyan          #+#    #+#             */
/*   Updated: 2022/06/06 00:16:57 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

// for pointer printing
void	ft_putptr_hex(unsigned long long int num)
{
	if (num >= 16)
	{
		ft_putptr_hex(num / 16);
		ft_putptr_hex(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd(num + 48, 1);
		else
			ft_putchar_fd(num + 87, 1);
	}
}

int	ft_putptr(unsigned long long ptr)
{
	int	count;

	count = write(1, "0x", 2);
	ft_putptr_hex(ptr);
	return (count);
}

// for unsigned int
void	ft_putnbr(unsigned int n)
{
	if (n < 10)
		ft_putchar_fd(n + '0', 1);
	else
	{
		ft_putnbr_fd(n / 10, 1);
		ft_putchar_fd (n % 10 + '0', 1);
	}	
}

// for hexadecimal
void	ft_puthex(unsigned int num, char specifier)
{
	if (num >= 16)
	{
		ft_puthex(num / 16, specifier);
		ft_puthex(num % 16, specifier);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd(num + 48, 1);
		else
		{
			if (specifier == 'x')
				ft_putchar_fd(num + 87, 1);
			if (specifier == 'X')
				ft_putchar_fd(num + 55, 1);
		}
	}
}

// for percent sign
ssize_t	ft_putpct(void)
{
	return (write(1, "%", 1));
}
