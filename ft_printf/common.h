/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:36:38 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/14 16:23:56 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

int		manage_print(char c, va_list *ap);

int		print_char(char c);
int		print_str(const char *str);
int		print_int(long num);
int		print_unsigned(unsigned int num);
int		print_hex(unsigned int num, char t);
int		print_ptr(void *ptr);

int		count_int(long num);
int		count_unsigned(unsigned int num);
int		count_hex(unsigned int num);

char	*ft_uitoa(unsigned int num);
char	*ft_uitoa_hex(unsigned int num, char *hex);

int		get_ptr(unsigned long val);
int		ptr_len(unsigned long val);

#endif
