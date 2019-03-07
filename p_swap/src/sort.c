#include "../includes/p_swap.h"

void sort(t_node **a, t_node **b, t_flags *f)
{
    int temp;

    temp = 0;
    if (!a || !(*a)->next)
        return ;
    fillb(a, b, f);
//    while (*b || !checksort(*a))
//    {
    if (*a)
        ft_printf("a is not empty\n");
    while (*b)
    {
        temp = (*b)->nb;
        if (*a && ((*a)->nb > temp))
        {
            rotate("rb\n", b);
            while (*a && (*a)->nb > temp)
                lst_push("pb\n", b, a, f);
            rev_rotate("rrb\n", b);
        }
        lst_push("pa\n", b, a, f);
    }
//    }
}