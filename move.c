/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <tbelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:25:17 by tbelard           #+#    #+#             */
/*   Updated: 2025/12/28 17:06:51 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_ps *s, US *stk[], char *op)
{
	US	tmp;

	if (stk[0])
	{
		if (s->size_a < 2)
			return ;
		tmp = VAL(*stk[0]);
		VAL(*stk[0]) = VAL(NEXT(*stk[0]));
		VAL(NEXT(*stk[0])) = tmp;
	}
	if (stk[1])
	{
		if (s->size_b < 2)
			return ;
		tmp = VAL(*stk[1]);
		VAL(*stk[1]) = VAL(NEXT(*stk[1]));
		VAL(NEXT(*stk[1])) = tmp;
	}
	write(1, op + 1, op[0] - '0');
	s->count++;
}

void rotate(t_ps *s, uint8_t dir, US *stk[2], char *op)
{
	if (stk[0])
		*stk[0] = s->stack[(*stk[0]) * 3 + dir];
	if (stk[1])
		*stk[1] = s->stack[(*stk[1]) * 3 + dir];
	write(1, op + 1, op[0] - '0');
	s->count++;
}

void	pa(t_ps *s)
{
	US	node;

	if (s->size_b == 0)
		exit(1);
	PREV(NEXT(B)) = PREV(B);
	NEXT(PREV(B)) = NEXT(B);
	node = B;
	B = NEXT(B);
	if (s->size_b-- == 1)
		B = 0;
	if (s->size_a++ == 0)
	{
		PREV(node) = node;
		NEXT(node) = node;
		A = node;
	}
	else
	{
		NEXT(node) = A;
		PREV(node) = PREV(A);
		NEXT(PREV(A)) = node;
		PREV(A) = node;
		A = node;
	}
	write(1, "pa\n", 3);
	s->count++;
}

void	pb(t_ps *s)//a modif
{
	US	node;

	if (s->size_a == 0)
		exit(1);
	PREV(NEXT(A)) = PREV(A);
	NEXT(PREV(A)) = NEXT(A);
	node = A;
	A = NEXT(A);
	if (s->size_a-- == 1)
		A = 0;
	if (s->size_b++ == 0)
	{
		PREV(node) = node;
		NEXT(node) = node;
		B = node;
	}
	else
	{
		NEXT(node) = B;
		PREV(node) = PREV(B);
		NEXT(PREV(B)) = node;
		PREV(B) = node;
		B = node;
	}
	write(1, "pb\n", 3);
	s->count++;
}
