/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 09:38:17 by trakotoz          #+#    #+#             */
/*   Updated: 2026/01/28 15:08:35 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(const char *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	*get_word(char *str, char c, size_t index)
{
	char	*word;
	size_t	start;
	size_t	str_len;
	size_t	word_len;
	size_t	j;

	start = index;
	str_len = ft_strlen(str);
	while (str[index] != c && index < str_len)
		index++;
	word_len = index - start;
	word = (char *) malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (start < index)
	{
		word[j] = str[start];
		start++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

static void	free_all_tab(char **res, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index && res[i] != 0)
		free(res[i++]);
	free(res);
}

static char	**make_split(char **ptr, char *str, char c, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] && j < len)
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			ptr[j] = get_word(str, c, i);
			if (!ptr[j])
			{
				free_all_tab(ptr, j);
				return (NULL);
			}
			j++;
		}
		while (str[i] != c && str[i])
			i++;
	}
	ptr[j] = NULL;
	return (ptr);
}

char	**ft_split(const char *str, char c)
{
	char	**ptr;
	size_t	len;

	if (!str)
		return (NULL);
	len = count_word(str, c);
	ptr = (char **) malloc(sizeof(char *) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr = make_split(ptr, (char *)str, c, len);
	return (ptr);
}
