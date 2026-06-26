#include "push_swap.h"

static US  ft_sqrt(US n)
{
    US min = 1;
    US max = n;
    US med = (max + min) /2;

    if (n == 0)
        return (0);
    if (n <= 3)
        return (1);
    while (min <= max)
    {
        if (med == n / med)
            return (med);
        if (med > n / med)
            max = med - 1;
        else
            min = med + 1;
        med = (max + min) /2;
    }
    return (med);
}
/*
input = meta A et B, stack A et B
trie ordre  croissant sur A

calcul racine de N * magic number
algo en fenetre glissante

tant qu'il ne reste pas uniquement le max (n - 1)
    si val top A < racine de N + taille de B (permet la fenetre glissante)
        push B
    si ce qu'on vient de push > size B
        si top A > racine N + size B
            rr
        sinon
            rb
    sinon
        ra
greedy
*/
void    chunk(t_ps *s)
{
    const US square = ft_sqrt(s->n) * 4;
    
    while (s->size_a > 1)
    {
        if (VAL(A) < (int)(square + s->size_b) && VAL(A) < s->n - 1)
        {
            pb(s);
            if (VAL(B) > s->size_b)
            {
                if (!(VAL(A) < (square + s->size_b)))
                    RR;
                else
                    RB;
            }
        }
        else
            RA;
    }
    greedy(s);
}
