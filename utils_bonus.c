/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:51:10 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/25 13:46:46 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "common.h"
#include "ft_printf/libft/libft.h"

int	is_sorted(t_list **list)
{
	int	val;

	if (!list || !*list)
		return (1);
	val = compute_disorder(list);
	if (val != 0)
		return (0);
	return (1);
}

int	evaluation(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !*stack_a)
		return (0);
	if (!is_sorted(stack_a))
		return (0);
	if (stack_b && *stack_b != NULL)
		return (0);
	return (1);
}
