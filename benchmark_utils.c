/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 08:04:29 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/26 13:47:25 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

int	is_benchmark(const char *str)
{
	if (ft_strcmp(str, "--bench") == 0)
		return (1);
	return (0);
}

int	have_bench(const char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		if (is_benchmark(argv[i]))
			return (1);
	return (0);
}

void	init_ops_bench(t_ops *ops)
{
	ops->ra = 0;
	ops->rb = 0;
	ops->rr = 0;
	ops->pa = 0;
	ops->pb = 0;
	ops->rra = 0;
	ops->rrb = 0;
	ops->rrr = 0;
	ops->sa = 0;
	ops->sb = 0;
	ops->ss = 0;
	ops->total = 0;
}

static void	check_command(char *commands, t_ops *ops)
{
	if (ft_strcmp(commands, "rrr") == 0)
		ops->rrr += 1;
	if (ft_strcmp(commands, "rra") == 0)
		ops->rra += 1;
	if (ft_strcmp(commands, "rrb") == 0)
		ops->rrb += 1;
	if (ft_strcmp(commands, "rr") == 0)
		ops->rr += 1;
	if (ft_strcmp(commands, "ra") == 0)
		ops->ra += 1;
	if (ft_strcmp(commands, "rb") == 0)
		ops->rb += 1;
	if (ft_strcmp(commands, "ss") == 0)
		ops->ss += 1;
	if (ft_strcmp(commands, "sa") == 0)
		ops->sa += 1;
	if (ft_strcmp(commands, "sb") == 0)
		ops->sb += 1;
	if (ft_strcmp(commands, "pa") == 0)
		ops->pa += 1;
	if (ft_strcmp(commands, "pb") == 0)
		ops->pb += 1;
}

void	parse_command_bench(char *all_command, t_ops *ops)
{
	char	**commands;
	int		i;

	if (!all_command)
		error();
	commands = ft_split(all_command, '\n');
	if (!commands)
		error();
	i = 0;
	while (commands[i] != NULL)
	{
		check_command(commands[i], ops);
		i++;
	}
	ops->total += ops->rrr + ops->rra + ops->rrb;
	ops->total += ops->rr + ops->ra + ops->rb;
	ops->total += ops->ss + ops->sa + ops->sb;
	ops->total += ops->pa + ops->pb;
	i = 0;
	while (commands[i])
		free(commands[i++]);
	free(commands);
}
