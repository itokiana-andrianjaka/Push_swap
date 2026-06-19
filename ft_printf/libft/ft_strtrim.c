/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:18:42 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/01 15:39:58 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(const char c, const char *set)
{
	size_t	i;
	size_t	set_len;

	i = 0;
	set_len = ft_strlen(set);
	while (i < set_len)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*copy_to(char *ptr, const char *src, int start, int end)
{
	size_t	i;

	i = 0;
	while (start <= end)
		ptr[i++] = src[start++];
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strtrim(char const *src, char const *set)
{
	char	*ptr;
	size_t	len;
	size_t	start;
	size_t	end;

	if (!src || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(src);
	if (end == 0)
		return (ft_strdup(""));
	end--;
	while (start <= end && is_in_set(src[start], set))
		start++;
	while (end > start && is_in_set(src[end], set))
		end--;
	if (start > end)
		return (ft_strdup(""));
	len = end - start + 1;
	ptr = (char *) malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr = copy_to(ptr, src, start, end);
	return (ptr);
}
