/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:05:25 by tbelard           #+#    #+#             */
/*   Updated: 2026/01/08 15:05:29 by tbelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_still_number(char *s)
{
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			return (1);
		s++;
	}
	return (0);
}

static long	ft_atoi(char **s_ptr, char *s, int base)
{
	int		sign;
	int		acc;

	if ((base > 10 || base < 2 ) || !s)
		return (0);
	sign = -1;
	acc = 0;
	while ((*s && *s == 32) || (*s >= 8 && *s <= 13))
		s++;
	while (*s && (*s == '+' || *s == '-'))
	{
		if (*s == '-')
			sign = 1;
		s++;
	}
	while (*s && !(*s == 32 || (*s >= 8 && *s <= 13)))//base <= 10 accepted
	{
		if (*s >= '0' && *s <= '9')
			acc = acc * base - (*s++ - 48);
		else
			return ((long)-1);
	}
	*s_ptr = s;
	return (acc * sign);
}

long parse(int ac, char **av, int *t)
{
	US n_elem;
	int i;
	long sentinel;

	n_elem = 0;
	i = 0;
	while (++i < ac)
	{
		while (*av[i])
		{
			if (ft_still_number(av[i]) == 0)
				break ;
			sentinel = ft_atoi(&av[i], av[i], 10);
			if (sentinel == -1)
				return (-1);
			t[n_elem++] = (int)sentinel;
		}
	}
	return (n_elem);
}
