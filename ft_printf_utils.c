/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:18:15 by aivanyan          #+#    #+#             */
/*   Updated: 2022/06/05 22:31:05 by aivanyan         ###   ########.fr       */
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
	int count;

	count = write(1,"0x",2);
	ft_putptr_hex(ptr);
	return (count);
}
