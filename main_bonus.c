/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:56:33 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/27 11:43:15 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "ft_printf/libft/libft.h"

int	main(int argc, char **argv)
{
	t_list	*list;

	if (argc < 2)
		return (0);
	list = NULL;
	parsing(&list, &argv[1]);
	start_execution(&list);
	ft_lstclear(&list, free);
	return (0);
}
