/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:46:02 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/26 15:58:47 by tiana-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_list **list)
{
	int		max;
	int		index;
	int		i;
	t_list	*temp;

	temp = *list;
	max = *(int *)temp->content;
	index = 0;
	i = 0;
	while (temp)
	{
		if (max < *(int *)temp->content)
		{
			max = *(int *)temp->content;
			index = i;
		}
		temp = temp->next;
		i++;
	}
	return (index);
}

int	find_min_index(t_list **list)
{
	int		min;
	int		index;
	int		i;
	t_list	*temp;

	temp = *list;
	min = *(int *)(temp->content);
	index = 0;
	i = 0;
	while (temp)
	{
		if (min > *(int *)(temp->content))
		{
			min = *(int *)(temp->content);
			index = i;
		}
		temp = temp->next;
		i++;
	}
	return (index);
}

int	find_square_root(int n)
{
	int	i;

	i = 0;
	while (i < n / 2)
	{
		if (i * i == n)
			return (i);
		if (i * i < n && (i + 1) * (i + 1) > n)
			return (i);
		i++;
	}
	return (0);
}
