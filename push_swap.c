/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:07:41 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/26 13:49:10 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

static void	print_bench_sorted(t_strat strategy, int bench)
{
	char	*all_commands;

	if (!bench)
		return ;
	all_commands = "";
	print_bench(all_commands, 0, strategy, 0);
}

void	start_algo(t_list **list, t_strat strategy, int bench)
{
	t_list	*stack_b;
	char	*all_commands;
	int		disorder;

	stack_b = NULL;
	all_commands = NULL;
	disorder = compute_disorder(list);
	if (disorder == 0)
	{
		print_bench_sorted(strategy, bench);
		return ;
	}
	if (strategy == SIMPLE)
		minmax_sort(list, &stack_b, &all_commands);
	if (strategy == MEDIUM)
		chunk_based_sort(list, &stack_b, &all_commands);
	if (strategy == COMPLEX)
		radix_lsd_sort(list, &stack_b, &all_commands);
	if (strategy == ADAPTIVE)
		adaptive_sort(list, &stack_b, &all_commands);
	ft_printf("%s", all_commands);
	if (bench)
		print_bench(all_commands, disorder, strategy, ft_lstsize(*list));
	free(all_commands);
	ft_lstclear(&stack_b, free);
}
