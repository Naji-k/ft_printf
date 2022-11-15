/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/09 20:30:35 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/11/09 20:30:35 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <string.h>

static void	converter(unsigned int num, char *base_table, int base_system)
{
	if (num >= base_system)
	{
		converter((num / base_system), base_table, base_system);
		converter((num % base_system), base_table, base_system);
	}
	if (num < base_system)
		ft_putchar_fd(base_table[num], 1);
}

void	ft_itoa_base(int num, char *base_table)
{
	int		base_system;
	unsigned int	nb;

	nb = num;
	base_system = strlen(base_table);
	// if (num < 0)
	// {
	// 	nb *= -1;
	// 	ft_putchar_fd('-', 1);
	// }
	converter(nb, base_table, base_system);
}

/* int	main(void)
{
	char	*hexa_base;
	char	*base_10;

	hexa_base = "0123456789ABCDEF";
	base_10 = "0123456789";
	ft_itoa_base(-2147483648, base_10);
}
 */