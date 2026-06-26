#include "push_swap.h"

void	algo_2move(t_ps *s)
{
	if (VAL(A) > VAL(NEXT(A)) && VAL(A) > VAL(NEXT(NEXT(A))))
		RA;
	else if (VAL(NEXT(A)) > VAL(NEXT(NEXT(A))))
		RRA;
	if (VAL(A) > VAL(NEXT(A)))
		SA;
}

void	insertion(t_ps *s)
{
	while (s->size_a)
	{
		pb(s);
		if (VAL(B) < s->n / 2 && VAL(A) < s->n / 2)
			RR;
		else if (VAL(B) < s->n / 2)
			RB;
	}
	greedy(s);
}
