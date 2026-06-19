/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 08:00:35 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/25 16:15:55 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	has_newline(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*extraction_line(char **str_ptr)
{
	char	*line;
	int		count;
	int		i;
	char	*str;

	str = *str_ptr;
	count = 0;
	if (!str || !str[0])
		return (NULL);
	while (str[count] && str[count] != '\n')
		count++;
	line = (char *)malloc(sizeof(char) * (count + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < count)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	*str_ptr = extraction_reminder(str);
	return (line);
}

static int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*extraction_reminder(char *str)
{
	int		i;
	char	*res;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	i++;
	res = (char *)malloc(sizeof(char) * (ft_strlen(str + i) + 1));
	if (!res)
	{
		free(str);
		return (NULL);
	}
	j = 0;
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}

char	*join_read(char *ptr, char *buffer)
{
	char	*res;
	int		i;
	int		j;

	if (!buffer)
		buffer = "";
	res = (char *)malloc(sizeof(char) * (ft_strlen(ptr) + ft_strlen(buffer)
				+ 1));
	if (!res)
	{
		free(ptr);
		return (NULL);
	}
	j = 0;
	i = 0;
	if (ptr)
		while (ptr[i])
			res[j++] = ptr[i++];
	i = 0;
	while (buffer && buffer[i])
		res[j++] = buffer[i++];
	res[j] = '\0';
	free(ptr);
	return (res);
}
