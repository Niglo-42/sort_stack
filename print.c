#include "push_swap.h"

void	ft_print_stack(t_ps s)
{
	printf("\n\tETAT STACK A\n\n");
	for(size_t p = 0; p < s.size_a; p++)
	{
		printf("\n\t[%d]\t(val = %hd)\t", s.head_a, VAL_(A_));
		for (int i = 0; i < VAL_(s.head_a); i++)
			printf("\033[0;35m■\033[0m");
		s.head_a = NEXT_(s.head_a);
	}
	printf("\n\tETAT STACK B\n\n");
	for(size_t p = 0; p < s.size_b; p++)
	{
		printf("\n\t[%d]\t(val = %hd)\t", s.head_b, VAL_(B_));
		for (int i = 0; i < VAL_(s.head_b); i++)
			printf("\033[0;35m■\033[0m");
		s.head_b = NEXT_(s.head_b);
	}
	printf("\n");
}
