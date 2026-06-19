/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiana-an <tiana-an@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:09:18 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/26 13:56:16 by tiana-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "ft_printf/libft/libft.h"
#include "push_swap.h"

static void	do_part(t_list **list, char **all_commands)
{
	int	index;
	int	size;
	int	part;

	index = find_min_index(list);
	size = ft_lstsize(*list);
	part = size / 2;
	if (index <= part)
	{
		while (index > 0)
		{
			rotate(list);
			take_command(all_commands, "ra");
			index = find_min_index(list);
		}
		return ;
	}
	while (index < size - 1)
	{
		reverse_rotate(list);
		take_command(all_commands, "rra");
		index = find_min_index(list);
	}
	reverse_rotate(list);
	take_command(all_commands, "rra");
}

static void	sort_max_index(t_list **stack_a, char **all_commands)
{
	if (find_max_index(stack_a) == 0)
	{
		rotate(stack_a);
		take_command(all_commands, "ra");
		if (find_min_index(stack_a) != 0)
		{
			swap(stack_a);
			take_command(all_commands, "sa");
		}
	}
	else if (find_max_index(stack_a) == 1)
	{
		reverse_rotate(stack_a);
		take_command(all_commands, "rra");
	}
	else
	{
		swap(stack_a);
		take_command(all_commands, "sa");
	}
}

static void	sort_in_one_list(t_list **stack_a, char **all_commands)
{
	int	size;

	if (compute_disorder(stack_a) == 0)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
	{
		swap(stack_a);
		take_command(all_commands, "sa");
		return ;
	}
	if (find_min_index(stack_a) == 0)
	{
		rotate(stack_a);
		swap(stack_a);
		reverse_rotate(stack_a);
		take_command(all_commands, "ra\nsa\nrra");
		return ;
	}
	sort_max_index(stack_a, all_commands);
}

void	minmax_sort(t_list **stack_a, t_list **stack_b, char **all_commands)
{
	*stack_b = NULL;
	while (*stack_a)
	{
		if (ft_lstsize(*stack_a) <= 3)
		{
			sort_in_one_list(stack_a, all_commands);
			break ;
		}
		do_part(stack_a, all_commands);
		if (compute_disorder(stack_a) == 0)
			break ;
		push(stack_a, stack_b);
		take_command(all_commands, "pb");
	}
	while (*stack_b)
	{
		push(stack_b, stack_a);
		take_command(all_commands, "pa");
	}
}
