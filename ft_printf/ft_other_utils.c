/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:23:35 by trakotoz          #+#    #+#             */
/*   Updated: 2026/02/14 16:23:43 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	ptr_len(unsigned long val)
{
	int	len;

	if (val == 0)
		return (1);
	len = 0;
	while (val)
	{
		val /= 16;
		len++;
	}
	return (len);
}
