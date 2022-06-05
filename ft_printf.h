/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:58:45 by aivanyan          #+#    #+#             */
/*   Updated: 2022/06/06 00:05:30 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_puthex(unsigned long long int num, char specifier);
int		ft_putptr(unsigned long long ptr);
void	ft_putnbr(unsigned int n);
void	ft_puthex(unsigned int num, char specifier);

#endif