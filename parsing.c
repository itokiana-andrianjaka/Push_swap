/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:31:37 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/26 13:49:03 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

static int	is_valid_arguments(char **res)
{
	int	i;

	if (!res)
		return (0);
	i = 0;
	while (res[i] != NULL)
	{
		if (!is_valid_digit(res[i]) && !is_strategy(res[i])
			&& !is_benchmark(res[i]))
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

static void	get_argument(t_list **list, char **res, t_strat *strat,
		int *have_strat)
{
	int	i;
	int	*val;

	i = -1;
	while (res[++i])
	{
		if (is_benchmark(res[i]))
			continue ;
		if (is_strategy(res[i]) && !*have_strat)
		{
			*strat = get_strategy(res[i]);
			*have_strat = 1;
			continue ;
		}
		if (is_strategy(res[i]) && *have_strat)
			continue ;
		val = (int *)malloc(sizeof(int));
		if (!val || have_duplicate(list, ft_atoi(res[i])))
			(free(val), ft_lstclear(list, free), error());
		*val = ft_atoi(res[i]);
		ft_lstadd_back(list, ft_lstnew(val));
	}
}

static void	free_split(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
}

void	parsing(t_list **list, char **argv, t_strat *strat, int *bench)
{
	char	**res;
	int		k;
	int		have_strat;

	k = -1;
	have_strat = 0;
	while (argv[++k] != NULL)
	{
		res = parse_arguments(argv[k]);
		if (!is_valid_arguments(res))
		{
			ft_lstclear(list, free);
			free_split(res);
			error();
		}
		if (have_bench((const char **)res))
			*bench = 1;
		get_argument(list, res, strat, &have_strat);
		free_split(res);
	}
}
