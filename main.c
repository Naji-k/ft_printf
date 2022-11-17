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


int	ft_printf(const char *holder, ...)
{
	int		x;
	va_list	args;
	char	*hexa;
	char	*hexa_upper;

	hexa = "0123456789abcdef";
	hexa_upper = "0123456789ABCDEF";
	x = 0;
	va_start(args, holder);
	while (*holder != '\0')
	{
		if (*holder == '%')
		{
			holder++;
			if (*holder == 'c')
				x = print_char(x, va_arg(args, int));
			else if (*holder == 's')
				x += print_string(va_arg(args, char *));
			else if (*holder == 'i' || *holder == 'd')
				x += print_dec(va_arg(args, int));
			else if (*holder == 'x')
				x += ft_itoa_base((unsigned int)va_arg(args, int), hexa);
			else if (*holder == 'X')
				x += ft_itoa_base((unsigned int)va_arg(args, int), hexa_upper);
			else if (*holder == 'p')
				x += print_pointer((unsigned long)va_arg(args, void *));
			else if (*holder == 'u')
				x += ft_itoa_base(va_arg(args, unsigned int), "0123456789");
			else if (*holder == '%')
			{
				write(1, "%", 1);
				x++;
			}
		}
		else if (*holder != '%' && *holder != '\0')
		{
			x++;
			write(1, holder, 1);
		}
		holder++;
	}
	va_end(args);
	return (x);
}
/* 
int	main(void)
{
	char s = 's';
	// ft_printf("%s %s ", "1", "2");
	// printf("\n%s %s ", "1", "2");
	// printf("\n %c %c %c ", '0', 0, '1');
	// printf("\n %c ", '0' + 256);
	printf("\t%d", printf("%s", "hello"));
	printf("\n----me----\n");
	printf("\t%d", ft_printf("%s", "hello"));
} */