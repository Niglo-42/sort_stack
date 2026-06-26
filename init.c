#include "push_swap.h"

static int normalizator(US n_elem, int *tab, t_ps *s)
{
	int i;
	int count;
	int j;
	int seen[MAX_NBR];

	i = 0;
	while (i < n_elem)
		seen[i++] = 0;
	i = 0;
	while (i < n_elem)
	{
		count = 0;
		j = 0;
		while (j < n_elem)
			if (tab[i] > tab[j++])
				count++;
		if (seen[count])
			return (1);
		seen[count] = 1;
		VAL(MAX_NBR - n_elem + i) = count;
		i++;
	}
	return (0);
}

static void	init(t_ps *s, US n_elem)
{
	US i;

	i = 0;
	while (++i <= n_elem)
	{
		PREV(MAX_NBR - i) = MAX_NBR - i - 1;
		NEXT(MAX_NBR - i) = MAX_NBR - i + 1;
	}
	NEXT(MAX_NBR - 1) = MAX_NBR - n_elem;
	PREV(MAX_NBR - n_elem) = MAX_NBR - 1;
}

void	init_all(t_ps *s, US n_elem, int *tab)
{
	s->size_a = (size_t)n_elem;
	s->size_b = 0;
	s->n = (size_t)n_elem;
	A = MAX_NBR - n_elem;
	B = 0;
	s->cost_a = 0;
	s->cost_b = 0;
	s->target = 0;
	s->count = 0;
	normalizator(n_elem, tab, s);
	init(s, n_elem);
}
