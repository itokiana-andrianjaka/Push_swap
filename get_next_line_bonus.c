/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 07:59:18 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/26 13:47:58 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_buffer(char **ptr, int fd)
{
	char	*buffer;
	int		count;

	while (!has_newline(*ptr))
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0)
		{
			free(buffer);
			free(*ptr);
			return (NULL);
		}
		if (count == 0)
		{
			free(buffer);
			break ;
		}
		buffer[count] = '\0';
		*ptr = join_read(*ptr, buffer);
		free(buffer);
	}
	return (*ptr);
}

char	*get_next_line(int fd)
{
	static char	*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ptr = read_buffer(&ptr, fd);
	if (!ptr || !ptr[0])
	{
		free(ptr);
		ptr = NULL;
		return (NULL);
	}
	return (extraction_line(&ptr));
}
