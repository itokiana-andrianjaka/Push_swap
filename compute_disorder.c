/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:27:54 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/25 17:44:04 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "common.h"

int	compute_disorder(t_list **list)
{
	int		mistakes;
	int		total_pair;
	t_list	*i;
	t_list	*j;

	mistakes = 0;
	total_pair = 0;
	i = *list;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pair++;
			if (*(int *)(i->content) > *(int *)(j->content))
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pair == 0)
		return (0);
	return (mistakes * 10000 / total_pair);
}
