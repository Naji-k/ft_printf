/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 15:35:33 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/11/08 15:35:33 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *HOLDER, ...)
{
	int		x;
	va_list	args;
	char	*hexa;
	char	*HEXA;
	int		num;

	hexa = "0123456789abcdef";
	HEXA = "0123456789ABCDEF";
	x = 0;
	va_start(args, HOLDER);
	while (*HOLDER)
	{
		while (*HOLDER != '%' && *HOLDER != '\0')
		{
			write(1, HOLDER, 1);
			HOLDER++;
			x++;
		}
		if (*HOLDER == '%')
		{
			HOLDER++;
			switch (*HOLDER)
			{
			case 'c':
				ft_putchar_fd(va_arg(args, int), 1);
				break ;
			case 's':
				ft_putstr_fd(va_arg(args, char *), 1);
				break ;
			case 'i':
				ft_putnbr_fd(va_arg(args, int), 1);
				break ;
			case 'd':
				ft_putnbr_fd(va_arg(args, int), 1);
				break ;
			case 'x':
				num = va_arg(args, int);
				ft_itoa_base(num, hexa);
				break ;
			case 'X':
				num = va_arg(args, int);
				ft_itoa_base(num, HEXA);
			case 'p':
				num = va_arg(args, int);
				ft_putstr_fd("0x7ff7", 1);
				ft_itoa_base(num, hexa);
				break ;
			default:
				break ;
			}
		}
		HOLDER++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	char* s = "geet";
	printf("%p\n", &s);
	ft_printf("%p", &s);
}