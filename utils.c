/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:45:49 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/25 11:43:39 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

long	ft_atoi_long(const char *str)
{
	size_t	i;
	size_t	len;
	long	val;
	int		sign;

	i = 0;
	val = 0;
	len = ft_strlen(str);
	sign = 1;
	while (i < len && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (i < len && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (i < len && ft_isdigit(str[i]))
	{
		val *= 10;
		val += str[i] - '0';
		i++;
	}
	return (val * sign);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	is_valid_digit(const char *str)
{
	int		i;
	long	val;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	val = ft_atoi_long(str);
	if (val > 2147483647 || val < -2147483648)
		return (0);
	return (1);
}

char	**parse_arguments(char *str)
{
	char	**res;

	res = ft_split(str, ' ');
	if (!res)
		return (NULL);
	return (res);
}
