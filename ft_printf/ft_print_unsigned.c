/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 19:46:25 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/13 12:15:37 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	print_unsigned(unsigned int num)
{
	int		len;
	char	*res;

	res = ft_uitoa(num);
	if (!res)
		return (-1);
	len = print_str(res);
	free(res);
	return (len);
}

int	count_unsigned(unsigned int num)
{
	int	count;

	count = 1;
	while (num >= 10)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*ft_uitoa(unsigned int num)
{
	char	*res;
	int		len;

	len = count_unsigned(num);
	res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (len--)
	{
		res[len] = num % 10 + '0';
		num /= 10;
	}
	return (res);
}
