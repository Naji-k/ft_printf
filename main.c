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
	va_list	arg;

	x = 0;
	va_start(arg, HOLDER);
	while (*HOLDER)
	{
		while (*HOLDER != '%' && *HOLDER != '\0')
		{
			write(1, HOLDER, 1);
			HOLDER++;
			x++;
		}
		if (*HOLDER == '%')
			HOLDER++;
	}
	va_end(arg);
	return (0);
}

int	main(void)
{
	// printf("hello");
	ft_printf("hello");
}