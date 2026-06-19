/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_lsd_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:07:51 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/26 13:49:21 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

static void	sort_array(int *res, int size)
{
	int	i;
	int	j;
	int	key;

	if (!res)
		return ;
	i = 0;
	while (++i < size)
	{
		j = i;
		key = res[i];
		while (--j >= 0 && res[j] > key)
			res[j + 1] = res[j];
		res[j + 1] = key;
	}
}

static int	*get_indexes(t_list **list)
{
	int		*res;
	int		size;
	int		i;
	t_list	*temp;

	size = ft_lstsize(*list);
	res = (int *)malloc(sizeof(int) * size);
	if (!res)
		return (NULL);
	i = -1;
	temp = *list;
	while (++i < size && temp)
	{
		res[i] = *(int *)(temp->content);
		temp = temp->next;
	}
	sort_array(res, size);
	return (res);
}

static void	apply_index(t_list **list, int *sorted, int size)
{
	t_list	*temp;
	int		value;
	int		i;
	int		*new_content;

	temp = *list;
	while (temp)
	{
		value = *(int *)(temp->content);
		i = 0;
		while (i != size && sorted[i] != value)
			i++;
		free(temp->content);
		new_content = (int *)malloc(sizeof(int));
		if (!new_content)
		{
			ft_lstclear(list, free);
			error();
		}
		*new_content = i;
		temp->content = new_content;
		temp = temp->next;
	}
}

static void	radix_algorithm(t_list **stack_a, t_list **stack_b,
		char **all_commands, int bit)
{
	int	size;
	int	i;

	i = -1;
	size = ft_lstsize(*stack_a);
	while (++i < size)
	{
		if ((((*(int *)((*stack_a)->content) >> bit)) & 1) == 0)
		{
			push(stack_a, stack_b);
			take_command(all_commands, "pb");
		}
		else
		{
			rotate(stack_a);
			take_command(all_commands, "ra");
		}
	}
	while (*stack_b)
	{
		push(stack_b, stack_a);
		take_command(all_commands, "pa");
	}
}

void	radix_lsd_sort(t_list **stack_a, t_list **stack_b, char **all_commands)
{
	int	*indexes;
	int	size;
	int	bits_max;
	int	bit;

	indexes = get_indexes(stack_a);
	if (!indexes)
		return ;
	size = ft_lstsize(*stack_a);
	bits_max = 0;
	while (((ft_lstsize(*stack_a) - 1) >> bits_max) != 0)
		bits_max++;
	apply_index(stack_a, indexes, size);
	bit = -1;
	while (++bit < bits_max)
		radix_algorithm(stack_a, stack_b, all_commands, bit);
	free(indexes);
}
