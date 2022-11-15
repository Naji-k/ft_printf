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

#include "ft_printf.h"
# include "libft/libft.h"
#include <stdio.h>
#include <string.h>

static void	converter(unsigned long num, char *base_table, unsigned long base_system)
{
	if (num >= base_system)
	{
		converter((num / base_system), base_table, base_system);
		converter((num % base_system), base_table, base_system);
	}
	if (num < base_system)
		ft_putchar_fd(base_table[num], 1);
}

void	ft_itoa_base(unsigned long num, char *base_table)
{
	unsigned long		base_system;
	// unsigned int	nb;
	// nb = num;
	base_system = strlen(base_table);
	converter(num, base_table, base_system);
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