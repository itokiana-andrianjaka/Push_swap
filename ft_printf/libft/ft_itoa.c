/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:01:13 by trakotoz          #+#    #+#             */
/*   Updated: 2026/01/31 20:18:46 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(int num)
{
	size_t	len;
	long	n;

	n = num;
	len = 0;
	if (n <= 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	convert(char *ptr, int n, size_t len)
{
	int		temp;
	long	num;

	num = n;
	if (num < 0)
	{
		num = -num;
		ptr[0] = '-';
	}
	ptr[len--] = '\0';
	if (num == 0)
	{
		ptr[len] = '0';
		return ;
	}
	while (num)
	{
		temp = num % 10;
		ptr[len--] = temp + 48;
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	len;

	len = count_len(n);
	ptr = (char *) malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	convert(ptr, n, len);
	return (ptr);
}
