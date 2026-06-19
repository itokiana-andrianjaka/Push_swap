/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 22:07:33 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/13 12:15:31 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	get_ptr(unsigned long val)
{
	int	len;

	len = 0;
	if (val >= 16)
		len += get_ptr(val / 16);
	len += print_char("0123456789abcdef"[val % 16]);
	return (len);
}

int	print_ptr(void *ptr)
{
	int				count;
	unsigned long	val;

	if (!ptr)
	{
		return (print_str("(nil)"));
	}
	val = (unsigned long) ptr;
	count = print_str("0x");
	count += get_ptr(val);
	return (count);
}
