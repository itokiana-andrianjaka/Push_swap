/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:43:48 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/07 14:39:36 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	is_sign(int c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static int	to_num(int c)
{
	return (c - '0');
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	size_t	len;
	int		val;
	int		sign;

	i = 0;
	val = 0;
	len = ft_strlen(nptr);
	sign = 1;
	while (i < len && is_whitespace(nptr[i]))
		i++;
	if (i < len && is_sign(nptr[i]))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (i < len && ft_isdigit(nptr[i]))
	{
		val *= 10;
		val += to_num(nptr[i]);
		i++;
	}
	return (val * sign);
}
