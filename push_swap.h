#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>

# ifndef MAX_NBR
#  define MAX_NBR 500
# endif
# ifndef MAX_CASE
#  define MAX_CASE MAX_NBR * 3
# endif

/* ========================= STACK LAYOUT ========================= */

# define US unsigned short
# define VAL(i)   s->stack[(i) * 3 + 0]
# define PREV(i)  s->stack[(i) * 3 + 1]
# define NEXT(i)  s->stack[(i) * 3 + 2]
# define A s->head_a
# define B s->head_b

/* ========================= STACK FOR VIEWER ========================= */

# define VAL_(i)   s.stack[(i) * 3 + 0]
# define PREV_(i)  s.stack[(i) * 3 + 1]
# define NEXT_(i)  s.stack[(i) * 3 + 2]
# define A_ s.head_a
# define B_ s.head_b

/* ========================= INSTRUCTIONS ========================= */

# define RA rotate(s, 2, (US*[]){&A, 0}, "3ra\n")
# define RRA rotate(s, 1, (US*[]){&A, 0}, "4rra\n")
# define RB rotate(s, 2, (US*[]){0, &B}, "3rb\n")
# define RRB rotate(s, 1, (US*[]){0, &B}, "4rrb\n")
# define RR rotate(s, 2, (US*[]){&A, &B}, "3rr\n")
# define RRR rotate(s, 1, (US*[]){&A, &B}, "4rrr\n")
# define SA swap(s,(US*[]){&A, 0}, "3sa\n")
# define SB swap(s,(US*[]){0, &B}, "3sa\n")
# define SS swap(s,(US*[]){&A, &B}, "3ss\n")


/* ========================= CORE STRUCT ========================= */

typedef struct s_ps
{
	US		stack[MAX_CASE];
	US		head_a;
	US		head_b;
	US		size_a;
	US		size_b;
	short	cost_a;
	short	cost_b;
	US		target;
	char	**op;
	US		n;
	US		count;
}	t_ps;

/* ========================= DATA OBJECT ========================= */

typedef struct s_duo_stk
{
	US	n;
	US	*a;
	US	*b;
}	t_duo_stk;

/* ========================= INIT / PARSING ========================= */

long	parse(int ac, char **av, int *t);
void	init_all(t_ps *s, US n_elem, int *tab);
float	desorder(t_ps s);

/* ========================= ALGO ========================= */

void	greedy(t_ps *ps);
void	algo_2move(t_ps *s);
int		small_big(t_ps s, US target);
void	insertion(t_ps *ps);
void	quick_turk(t_ps *ps);
void	chunk(t_ps *ps);

/* ========================= APPLY ========================= */

void	apply_n(t_ps *ps, size_t (*op)(t_ps *), short n);

/* ========================= DEBUG ========================= */

void	ft_print_stack(t_ps s);

/* ========================= OPS ========================= */

void 	rotate(t_ps *s, uint8_t dir, US *stk[2], char *op);
void	swap(t_ps *s, US *stk[2], char *op);
void	pa(t_ps *s);
void	pb(t_ps *s);

/* ========================= UTILS ========================= */

US		ft_abs(short n);
short	ft_min(short a, short b);
short	ft_max(short a, short b);

#endif
