/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:42:31 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/26 13:47:19 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

void	buff_add(char **buffer, char *str)
{
	char	*temp;

	if (!*buffer)
	{
		*buffer = ft_strdup(str);
		return ;
	}
	temp = ft_strjoin(*buffer, str);
	free(*buffer);
	*buffer = temp;
}

static void	buff_add_nbr(char **buffer, int number)
{
	char	*num;

	num = ft_itoa(number);
	buff_add(buffer, num);
	free(num);
}

static void	get_bench_ops(char **buffer, t_ops *ops)
{
	buff_add(buffer, "[bench]");
	buff_add(buffer, " sa: ");
	buff_add_nbr(buffer, ops->sa);
	buff_add(buffer, " sb: ");
	buff_add_nbr(buffer, ops->sb);
	buff_add(buffer, " ss: ");
	buff_add_nbr(buffer, ops->ss);
	buff_add(buffer, " pa: ");
	buff_add_nbr(buffer, ops->pa);
	buff_add(buffer, " pb: ");
	buff_add_nbr(buffer, ops->pb);
	buff_add(buffer, "\n");
	buff_add(buffer, "[bench]");
	buff_add(buffer, " ra: ");
	buff_add_nbr(buffer, ops->ra);
	buff_add(buffer, " rb: ");
	buff_add_nbr(buffer, ops->rb);
	buff_add(buffer, " rr: ");
	buff_add_nbr(buffer, ops->rr);
	buff_add(buffer, " rra: ");
	buff_add_nbr(buffer, ops->rra);
	buff_add(buffer, " rrb: ");
	buff_add_nbr(buffer, ops->rrb);
	buff_add(buffer, " rrr: ");
	buff_add_nbr(buffer, ops->rrr);
}

static void	get_bench_strategy(char **buffer, int disorder, t_strat strat,
		int size)
{
	buff_add(buffer, "[bench] strategy:\t");
	if (disorder == 0 && strat == ADAPTIVE)
		buff_add(buffer, "Adaptive / O(1)\n");
	else if (strat == SIMPLE)
		buff_add(buffer, "Simple / O(n^2)\n");
	else if (strat == MEDIUM)
		buff_add(buffer, "Medium / O(n√n)\n");
	else if (strat == COMPLEX)
		buff_add(buffer, "Complex / O(nlogn)\n");
	else if (strat == ADAPTIVE)
		for_bench_adaptive(buffer, disorder, size);
}

char	*get_bench(const char *all_commands, int disorder, t_strat strat,
		int size)
{
	t_ops	ops;
	char	*bench_info;

	if (!all_commands)
		return (NULL);
	init_ops_bench(&ops);
	parse_command_bench((char *)all_commands, &ops);
	bench_info = NULL;
	buff_add(&bench_info, "[bench] disorder:\t");
	buff_add_nbr(&bench_info, disorder / 100);
	buff_add(&bench_info, ".");
	if (disorder % 100 < 10)
		buff_add(&bench_info, "0");
	buff_add_nbr(&bench_info, disorder % 100);
	buff_add(&bench_info, "%");
	buff_add(&bench_info, "\n");
	get_bench_strategy(&bench_info, disorder, strat, size);
	buff_add(&bench_info, "[bench] total_ops:\t");
	buff_add_nbr(&bench_info, ops.total);
	buff_add(&bench_info, "\n");
	get_bench_ops(&bench_info, &ops);
	buff_add(&bench_info, "\n");
	return (bench_info);
}
