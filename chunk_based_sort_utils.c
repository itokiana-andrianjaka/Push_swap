/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based_sort_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiana-an <tiana-an@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:37:24 by tiana-an          #+#    #+#             */
/*   Updated: 2026/02/26 15:24:15 by tiana-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

static t_list	*ft_cpy(t_list *argv)
{
	t_list	*copy;
	int		*var;

	copy = NULL;
	while (argv)
	{
		var = (int *)malloc(sizeof(int));
		*var = *(int *)argv->content;
		ft_lstadd_back(&copy, ft_lstnew(var));
		argv = argv->next;
	}
	return (copy);
}

t_list	*ft_sort(t_list *argv)
{
	t_list	*copy;
	t_list	*tempo;
	t_list	*tmp;
	char	*key;

	if (!argv)
		return (NULL);
	copy = ft_cpy(argv);
	tmp = copy;
	while (tmp)
	{
		tempo = tmp->next;
		while (tempo)
		{
			if (*(int *)tmp->content > *(int *)tempo->content)
			{
				key = tmp->content;
				tmp->content = tempo->content;
				tempo->content = key;
			}
			tempo = tempo->next;
		}
		tmp = tmp->next;
	}
	return (copy);
}

void	manage_part(t_list **list, char **all_commands)
{
	int	index;
	int	size;
	int	part;

	index = find_max_index(list);
	size = ft_lstsize(*list);
	part = size / 2;
	if (index <= part)
	{
		while (index > 0)
		{
			rotate(list);
			take_command(all_commands, "rb");
			index = find_max_index(list);
		}
		return ;
	}
	while (index < size - 1)
	{
		reverse_rotate(list);
		take_command(all_commands, "rrb");
		index = find_max_index(list);
	}
	reverse_rotate(list);
	take_command(all_commands, "rrb");
}
