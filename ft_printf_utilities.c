/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utilities.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 19:38:21 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/11/17 19:38:21 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int x, char param)
{
	ft_putchar_fd(param, 1);
	x++;
	return (x);
}

int	print_string(char *param)
{
	char	*str;

	str = param;
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	print_dec(int num)
{
	char	*base_10;
	int		x;

	base_10 = "0123456789";
	x = 0;
	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
		x++;
	}
	x += ft_itoa_base((unsigned int)num, base_10);
	return (x);
}

int	print_pointer(unsigned long address)
{
	int		x;
	char	*hexa;

	x = 0;
	hexa = "0123456789abcdef";
	ft_putstr_fd("0x", 1);
	x += ft_itoa_base(address, hexa) + 2;
	return (x);
}
