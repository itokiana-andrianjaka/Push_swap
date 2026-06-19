/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:57:44 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/26 13:48:16 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
# include <stdlib.h>

int		compute_disorder(t_list **list);
void	error(void);

int		is_valid_digit(const char *str);
char	**parse_arguments(char *str);

long	ft_atoi_long(const char *str);
int		ft_strcmp(const char *s1, const char *s2);

void	swap(t_list **list);
void	swap_ab(t_list **a, t_list **b);
void	push(t_list **a, t_list **b);

void	rotate_ab(t_list **a, t_list **b);
void	rotate(t_list **list);

void	reverse_rotate(t_list **list);
void	reverse_rotate_ab(t_list **a, t_list **b);

#endif
