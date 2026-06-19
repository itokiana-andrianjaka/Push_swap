/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:42:33 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/26 13:56:27 by tiana-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	is_valid_arguments(char **res)
{
	int	i;

	if (!res)
		return (0);
	i = 0;
	while (res[i] != NULL)
	{
		if (!is_valid_digit(res[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	have_duplicate(t_list **list, int num)
{
	t_list	*temp;

	temp = *list;
	while (temp)
	{
		if (*(int *)(temp->content) == num)
			return (1);
		temp = temp->next;
	}
	return (0);
}

static void	get_argument(t_list **list, char **res)
{
	int	i;
	int	*val;

	i = -1;
	while (res[++i])
	{
		val = (int *)malloc(sizeof(int));
		if (!val || have_duplicate(list, ft_atoi(res[i])))
		{
			free(val);
			ft_lstclear(list, free);
			error();
		}
		*val = ft_atoi(res[i]);
		ft_lstadd_back(list, ft_lstnew(val));
	}
}

void	parsing(t_list **list, char **argv)
{
	char	**res;
	int		i;
	int		k;

	k = -1;
	while (argv[++k] != NULL)
	{
		res = parse_arguments(argv[k]);
		if (!is_valid_arguments(res))
		{
			i = 0;
			while (res[i])
				free(res[i++]);
			free(res);
			ft_lstclear(list, free);
			error();
		}
		get_argument(list, res);
		i = 0;
		while (res[i])
			free(res[i++]);
		free(res);
	}
}
