/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiana-an <tiana-an@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:47:57 by tiana-an          #+#    #+#             */
/*   Updated: 2026/02/26 13:55:55 by tiana-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

static int	in_lst(t_list **cpy, t_list *find, int t_jump, int size)
{
	int		i;
	t_list	*temp;
	t_list	*cursor;

	cursor = *cpy;
	i = 0;
	if (t_jump == 0)
		temp = *cpy;
	else
	{
		while (i++ < t_jump && cursor)
			cursor = cursor->next;
		if (!cursor)
			return (0);
		temp = cursor;
	}
	i = 0;
	while (i++ < size && temp)
	{
		if (*(int *)temp->content == *(int *)find->content)
			return (1);
		temp = temp->next;
	}
	return (0);
}

static void	manage_cmp_chunk(int *sq, int *count, int size, int *i)
{
	if (*sq == 0)
		*sq = 1;
	else
	{
		if (*count == (size / *sq))
		{
			*i = *i + (size / *sq);
			*count = 0;
		}
	}
}

static void	shortcut(t_list **stack_a, t_list **stack_b, char **com, int mode)
{
	if (mode == 1)
	{
		push(stack_a, stack_b);
		take_command(com, "pb");
	}
	if (mode == 2)
	{
		rotate(stack_a);
		take_command(com, "ra");
	}
}

static void	cmp_chunk(t_list **stack_a, t_list **stack_b, char **all_commands)
{
	int		size;
	int		i;
	int		count;
	int		sq;
	t_list	*str;

	i = 0;
	count = 0;
	str = ft_sort(*stack_a);
	size = ft_lstsize(*stack_a);
	sq = find_square_root(size);
	while (*stack_a)
	{
		manage_cmp_chunk(&sq, &count, size, &i);
		if (in_lst(&str, *stack_a, i, (size / sq)) && count < (size / sq))
		{
			shortcut(stack_a, stack_b, all_commands, 1);
			count++;
		}
		else
			shortcut(stack_a, stack_b, all_commands, 2);
		manage_cmp_chunk(&sq, &count, size, &i);
	}
	ft_lstclear(&str, free);
}

void	chunk_based_sort(t_list **stack_a, t_list **stack_b,
		char **all_commands)
{
	cmp_chunk(stack_a, stack_b, all_commands);
	while (*stack_b)
	{
		manage_part(stack_b, all_commands);
		push(stack_b, stack_a);
		take_command(all_commands, "pa");
	}
}
