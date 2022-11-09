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
			default:
				break ;
			}
		}
		HOLDER++;
	}
	va_end(args);
	return (0);
}
static int	nbr_len(int n)
{
	int	i;
	int	sign;

	sign = 0;
	i = 0;
	if (n <= 0)
		sign += 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
}
static void	converter(long num, int base, char *base_table)
{
	if (num > base_system)
	{
		converter((num / base), base, base_table);
		converter((num % base), base, base_table);
	}
	else if (num < base)
	{
		
		write(1, &num, 1);
	}
}
int	ft_putnbr_base(int nbr, char *base)
{
	int	base_system;
	int	str_len;

	base_system = ft_strlen(base);
	if (nbr == 0)
		write(1, "0", 1);
	converter(nbr, base_system, base);
	// str_len = nbr_len(nbr);
	return (0);
}

int	main(void)
{
	int s = 2;
	printf("%x", -1234);
	// ft_printf("%d", 0001);
}