/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 21:25:06 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/13 12:15:21 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	print_hex(unsigned int num, char t)
{
	int		len;
	char	*res;
	char	*hex;

	hex = "0123456789abcdef";
	if (t == 'X')
		hex = "0123456789ABCDEF";
	res = ft_uitoa_hex(num, hex);
	if (!res)
		return (-1);
	len = print_str(res);
	free(res);
	return (len);
}

int	count_hex(unsigned int num)
{
	int	count;

	count = 1;
	while (num >= 16)
	{
		num /= 16;
		count++;
	}
	return (count);
}

char	*ft_uitoa_hex(unsigned int num, char *hex)
{
	char	*res;
	int		len;
	int		index;

	len = count_hex(num);
	res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (len--)
	{
		index = num % 16;
		res[len] = hex[index];
		num /= 16;
	}
	return (res);
}
