#include "push_swap.h"

void	quick_2(t_ps *s)
{
	US	i;
	US	median;

	i = s->size_a;
	median = s->n - (i / 2);
	while (s->size_a > (i / 2) && s->size_a > 3)
	{
		if (VAL(A) < median)
		{
			pb(s);
			if (VAL(B) < (i / 4 + (s->n - i)))
			{
				if (VAL(A) >= median)
					RR;
				else
					RB;
			}
		}
		else
			RA;
	}
}

void	quick_turk(t_ps *s)
{
	while (s->size_a > 3)
		quick_2(s);
	algo_2move(s);
	greedy(s);
}
