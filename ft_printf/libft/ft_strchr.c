/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:45:21 by trakotoz          #+#    #+#             */
/*   Updated: 2026/01/28 08:08:32 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*ptr;

	len = ft_strlen(s);
	ptr = (char *) s;
	if (c == '\0')
		return (ptr + len);
	i = 0;
	while (ptr[i])
	{
		if ((unsigned char)ptr[i] == (unsigned char) c)
			return (ptr + i);
		i++;
	}
	return (0);
}
