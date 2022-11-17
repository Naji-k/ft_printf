/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 00:16:06 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/11/08 00:16:06 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *holder, ...);
int	ft_itoa_base(unsigned long num, char *base_table);
int	nbr_len(unsigned long num, int base_system);
int	print_char(int x, char param);
int	print_string(char *param);
int	print_dec(int num);
int	print_pointer(unsigned long address);

#endif