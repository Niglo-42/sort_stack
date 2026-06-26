#include "push_swap.h"

float	desorder(t_ps s)
{
	int mistake;
	int	total_pairs;
	US	i;
	US	j;

	i = s.head_a;
	mistake = 0;
	total_pairs = 0;
	while (i < MAX_NBR)
	{
		j = i + 1; 
		while (j < MAX_NBR)
		{
			total_pairs++;
			if (VAL_(i) > VAL_(j))
				mistake++;
			j++;
		}
		i++;
	}
	return ((float)(mistake / total_pairs));
}

static void	ft_push_swap(t_ps *s)
{
	float	disorder;

	disorder = desorder(*s);
	if (s->size_a < 4)
		algo_2move(s);
	else if (disorder < 0.2)
		insertion(s);
	else if (disorder < 0.5)
		chunk(s);
	else
		quick_turk(s);
}

int main(int ac, char **av)
{
	t_ps 	s;
	US		n_elem;
	int 	tab[MAX_CASE];

	if (ac < 2)
		return (write(1, "error", 5));

	n_elem = parse(ac, av, tab);
	init_all(&s, n_elem, tab);
	ft_print_stack(s);
	ft_push_swap(&s);
	ft_print_stack(s);
	printf("count  =  %hd\n", s.count);
}

