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

#include "ft_printf.h"
#include "libft/libft.h"
#include <limits.h>
#include <stdio.h>

int	ft_printf(const char *HOLDER, ...)
{
	int		x;
	va_list	args;
	char	*hexa;
	char	*HEXA;
	int		num;
	void	*adrss;
	char	c;
	char	*str;

	hexa = "0123456789abcdef";
	HEXA = "0123456789ABCDEF";
	x = 0;
	va_start(args, HOLDER);
	while (*HOLDER != '\0')
	{
		if (*HOLDER == '%')
		{
			HOLDER++;
			if (*HOLDER == 'c')
			{
				c = va_arg(args, int);
				ft_putchar_fd(c, 1);
				x++;
			}
			else if (*HOLDER == 's')
			{
				str = va_arg(args, char *);
				ft_putstr_fd(str, 1);
				x += ft_strlen(str);
			}
			else if (*HOLDER == 'i' || *HOLDER == 'd')
			{
				num = va_arg(args, int);
				ft_putnbr_fd(num, 1);
				x += nbr_len(num, 10);
			}
			else if (*HOLDER == 'x')
			{
				num = va_arg(args, int);
				x += ft_itoa_base(num, hexa);
			}
			else if (*HOLDER == 'X')
			{
				num = va_arg(args, int);
				ft_itoa_base(num, HEXA);
				x += nbr_len(num, 16);
			}
			else if (*HOLDER == 'p')
			{
				adrss = va_arg(args, void *);
				ft_putstr_fd("0x", 1);
				x += ft_itoa_base((unsigned long)adrss, hexa) + 2;
			}
			else if (*HOLDER == '%')
			{
				write(1, "%", 1);
				x++;
			}
		}
		else if (*HOLDER != '%' && *HOLDER != '\0')
		{
			x++;
			write(1, HOLDER, 1);
		}
		HOLDER++;
		// printf("\nx=%d\n",x);
		// x++;
	}
	va_end(args);
	return (x);
}

/* int	main(void)
{
	// ft_printf("%s %s ", "1", "2");
	// printf("\n%s %s ", "1", "2");
	// printf("\n %c %c %c ", '0', 0, '1');
	// printf("\n %c ", '0' + 256);
	printf("\t%d", printf(" %d ", 0));
	printf("\n----me----\n");
	printf("\t%d", ft_printf(" %d ", 0));
}
 */