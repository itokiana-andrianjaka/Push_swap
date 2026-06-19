/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:11:08 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/23 17:11:13 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_strategy(const char *str)
{
	if (ft_strcmp(str, "--adaptive") == 0)
		return (1);
	if (ft_strcmp(str, "--simple") == 0)
		return (1);
	if (ft_strcmp(str, "--medium") == 0)
		return (1);
	if (ft_strcmp(str, "--complex") == 0)
		return (1);
	return (0);
}

t_strat	get_strategy(const char *str)
{
	if (ft_strcmp(str, "--adaptive") == 0)
		return (ADAPTIVE);
	if (ft_strcmp(str, "--simple") == 0)
		return (SIMPLE);
	if (ft_strcmp(str, "--medium") == 0)
		return (MEDIUM);
	if (ft_strcmp(str, "--complex") == 0)
		return (COMPLEX);
	return (ADAPTIVE);
}
