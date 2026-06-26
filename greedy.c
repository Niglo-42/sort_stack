#include "push_swap.h"

static int	where_is_0(t_ps s)
{
	US i;

	i = 0;
	while(i < s.size_a && VAL_(A_) != 0)
	{
		A_ = NEXT_(A_);
		i++;
	}
	return (i < s.size_a / 2);
}

static void	moves(t_ps *s)
{
	short	abs_a;
	short	abs_b;

	abs_b = ft_abs(s->cost_b);
	abs_a = ft_abs(s->cost_a);
	while (abs_a-- > 0)
	{
		if (s->cost_a < 0)
			RRA;
		else
			RA;
	}
	while (abs_b-- > 0)
	{
		if (s->cost_b < 0)
			RRB;
		else
			RB;
	}
}

typedef struct s_calcul
{
	US		i;
	short	cost_b;
	short	cost_tot;
	short	cost_a;
	short	new_cost;
	US		b_cpy;
}	t_calcul;

static void	calcul_cost(t_ps *s)
{
	t_calcul	t;

	t.b_cpy = B;
	t.cost_tot = 0x7fff;
	t.i = 0;
	while (t.i < s->size_b)
	{
		t.cost_a = small_big(*s, VAL(t.b_cpy));
		t.cost_b = t.i - (s->size_b * (t.i > s->size_b / 2)); 
		if ((t.cost_a < 0 && t.cost_b < 0) || (t.cost_a >= 0 && t.cost_b >= 0))
			t.new_cost = ft_max(ft_abs(t.cost_a), ft_abs(t.cost_b));
		else
			t.new_cost = ft_abs(t.cost_a) + ft_abs(t.cost_b);
		if (t.new_cost < t.cost_tot)
		{
			s->cost_b = t.cost_b;
			s->cost_a = t.cost_a;
			t.cost_tot = t.new_cost;
		}
		t.b_cpy = NEXT(t.b_cpy);
		t.i++;
	}
}

typedef struct	s_moves
{
	short	mutual;
	short	remain_a;
	short	remain_b;
	char	dir;
}	t_moves;

static void	init_m(t_ps *s, t_moves *m)
{
	m->dir = (s->cost_a < 0);
	m->mutual = ft_min(ft_abs(s->cost_a), ft_abs(s->cost_b));
	m->remain_a = ft_abs(s->cost_a) - m->mutual;
	m->remain_b = ft_abs(s->cost_b) - m->mutual;
}

static void	mutual_moves(t_ps *s)
{
	t_moves	m;

	init_m(s, &m);
	while (m.mutual--)
	{
		if (m.dir)
			RRR;
		elsegreedy(s);
			RR;
	}
	while (m.remain_a--)
	{
		if (m.dir)
			RRA;
		else
			RA;
	}
	while (m.remain_b--)
	{
		if (m.dir)
			RRB;
		else
			RB;
	}
}

void	greedy(t_ps *s)
{
	while (s->size_b)
	{
		calcul_cost(s);
		if ((s->cost_a < 0 && s->cost_b < 0)
			|| (s->cost_a >= 0 && s->cost_b >= 0))
			mutual_moves(s);
		else
			moves(s);
		pa(s);
	}
	if (where_is_0(*s))
	{
		while (VAL(A) != 0)
			RA;
	}
	else
		while (VAL(A) != 0)
			RRA;
}
