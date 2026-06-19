/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 09:15:46 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/15 14:36:14 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;
	size_t	i;

	if (!format)
		return (-1);
	count = 0;
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += manage_print(format[i], &ap);
		}
		else
		{
			print_char(format[i]);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
