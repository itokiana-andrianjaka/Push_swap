/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:53:19 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/14 14:17:37 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	manage_print(char c, va_list *ap)
{
	int	count;

	count = 0;
	if (c == '%')
		return (print_char('%'));
	if (c == 'c')
		return (print_char(va_arg(*ap, unsigned int)));
	if (c == 's')
		return (print_str(va_arg(*ap, char *)));
	if (c == 'd' || c == 'i')
		return (print_int(va_arg(*ap, int)));
	if (c == 'u')
		return (print_unsigned(va_arg(*ap, unsigned int)));
	if (c == 'x' || c == 'X')
		return (print_hex(va_arg(*ap, unsigned int), c));
	if (c == 'p')
		return (print_ptr(va_arg(*ap, void *)));
	return (count);
}

int	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_str(const char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (ft_strlen("(null)"));
	}
	ft_putstr_fd((char *)str, 1);
	return (ft_strlen(str));
}

int	print_int(long num)
{
	int	count;

	count = 0;
	if (num < 0)
		count++;
	ft_putnbr_fd(num, 1);
	return (count_int(num) + count);
}

int	count_int(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}
