/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:01:48 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/25 13:21:19 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "common.h"
# include "get_next_line_bonus.h"

void	start_execution(t_list **stack_a);
void	parsing(t_list **list, char **argv);

int		is_sorted(t_list **list);

int		evaluation(t_list **stack_a, t_list **stack_b);
void	apply_command(char *command, t_list **stack_a, t_list **stack_b);

#endif
