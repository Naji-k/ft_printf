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
#include <string.h>

static int	num_len(int n)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (n <= 0)
		sign += 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i + sign);
}

/* static void	converter(int num, char *base_table, char *str,int index)
{
	if (num == 0)
		str[index] = '0';
	if (num > 9)
	{
		recursive(str, (num / 10), index - 1);
		recursive(str, (num % 10), (index));
	}
	else if (num <= 9)
	{
		str[index] = num + '0';
		num = num / 10;
	}
} */

void	ft_itoa_base(int num, char *base_table)
{
	int	base_system;
	int	nem_len;

	nem_len = num_len(num);
	base_system = strlen(base_table);
	if (num >= base_system)
	{
		ft_itoa_base((num / base_system), base_table);
		ft_itoa_base((num % base_system), base_table);
	}
	// else if (num > 0)
	else if (num == 0)
	{

		write(1,"0",1);
	}
	write(1, &base_table[num], 1);
}
int	main(void)
{
	char *hexa_base = "0123456789ABCDEF";
	char *base_10 = "0123456789";
	ft_itoa_base(2147483647, base_10);
}