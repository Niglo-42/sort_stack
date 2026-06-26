/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:37:08 by tbelard           #+#    #+#             */
/*   Updated: 2026/01/08 15:37:17 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_smallest
{
	int		val;
	size_t	idx;
	size_t	i;
} t_smallest;

static void	find_min(t_smallest	*var, t_ps s)
{
	if (var->val == 0x7fffffff)
	{
    	var->i = -1;
    	var->val = VAL_(A_);
		while (++var->i < s.size_a)
		{
			if (VAL_(A_) < var->val)
			{
				var->val = VAL_(A_);
				var->idx = var->i;
			}
			A_ = NEXT_(A_);
		}
	}
}

int	small_big(t_ps s, US target)
{
	t_smallest	var;

	var.val = 0x7fffffff;
	var.idx = 0;
	var.i = -1;
	while (++var.i < s.size_a)
	{
		if (VAL_(A_) > target && VAL_(A_) < var.val)
		{
				var.val = VAL_(A_);
				var.idx = var.i;
		}
		A_ = NEXT_(A_);
	}
	find_min(&var, s);
	if (var.idx > s.size_a / 2)
		return (var.idx - s.size_a);
	return (var.idx);
}
