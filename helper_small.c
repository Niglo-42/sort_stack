/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:02:50 by tbelard           #+#    #+#             */
/*   Updated: 2026/01/08 15:02:52 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


US ft_abs(short n)
{
	if (n < 0)
		return (-n);
	return (n);
}

short ft_max(short a, short b)
{
	if (a > b)
		return (a);
	return (b);
}

short ft_min(short a, short b)
{
	if (a < b)
		return (a);
	return (b);
}
