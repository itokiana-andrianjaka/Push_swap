/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiana-an <tiana-an@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:34:29 by tiana-an          #+#    #+#             */
/*   Updated: 2026/02/26 13:56:39 by tiana-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

typedef enum e_strat
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
}		t_strat;

void	start_algo(t_list **list, t_strat strategy, int bench);
void	parsing(t_list **list, char **argv, t_strat *strat, int *bench);

int		is_strategy(const char *str);
int		have_bench(const char **argv);
t_strat	get_strategy(const char *str);

void	take_command(char **all_commands, char *command);

int		find_square_root(int n);
int		find_max_index(t_list **list);
int		find_min_index(t_list **list);

void	minmax_sort(t_list **stack_a, t_list **stack_b, char **all_commands);
void	chunk_based_sort(t_list **stack_a, t_list **stack_b,
			char **all_commands);
int		find_square_root(int n);
t_list	*ft_sort(t_list *argv);
void	manage_part(t_list **list, char **all_commands);
void	chunk_based_sort(t_list **stack_a, t_list **stack_b,
			char **all_commands);
void	radix_lsd_sort(t_list **stack_a, t_list **stack_b, char **all_commands);
void	adaptive_sort(t_list **stack_a, t_list **stack_b, char **all_commands);

typedef struct s_ops
{
	int	ra;
	int	rb;
	int	rr;
	int	pa;
	int	pb;
	int	rra;
	int	rrb;
	int	rrr;
	int	sa;
	int	sb;
	int	ss;
	int	total;
}		t_ops;

void	init_ops_bench(t_ops *ops);
int		is_benchmark(const char *str);
void	buff_add(char **buffer, char *str);
void	for_bench_adaptive(char **buffer, int disorder, int size);
char	*get_bench(const char *all_commands, int disorder, t_strat strat,
			int size);
void	parse_command_bench(char *all_command, t_ops *ops);
void	print_bench(const char *all_commands, int compute_disorder,
			t_strat strat, int size);

#endif
