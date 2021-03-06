#include "../includes/p_swap.h"

int			is_sorted(t_node *lst)
{
	while (lst && lst->next)
	{
		if (lst->nb > lst->next->nb)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void		sort_a(t_node **a, t_node **b, t_flags *f)
{
	int		temp;
	while ((*a)->next)
	{
		if ((*a)->nb < (*a)->next->nb)
		{
			if (f->v)
			{
				printa(*a, f->count_a);
				printa(*b, f->count_b);
			}
			temp = (*a)->nb;
			rotate("ra\n", a, f);
			while (*b && (*b)->nb > temp)
				lst_push("", b, a, f);
			rev_rotate("rra", a);
			lst_push("pb\n", a, b, f);
			if (f->v)
			{
				printa(*a, f->count_a);
				printa(*b, f->count_b);
				ft_printf("\n");
			}
		}
 
	}
}

void		sort_b(t_node **b, t_node **a, t_flags *f)
{
	while (*b)
	{
		if (!(*b)->next || (*b)->nb > (*b)->next->nb)
		{
			if (f->v)
			{
				printa(*a, f->count_a);
				printa(*b, f->count_b);
			}
			rotate("ra", a, f);
			while (*b && (*b)->nb > temp)
				lst_push("", b, a, f);
			lst_push("", b, a, f);
			ft_putstr("pa\n");
			if (f->v)
			{
				printa(*a, f->count_a);
				printa(*b, f->count_b);
				ft_printf("\n");
			}
		}
		else
		{
			if (f->v)
			{
				printa(*a, f->count_a);
				printa(*b, f->count_b);
			}
			swapnodes(b);
			ft_putstr("sb\n");
			if (f->v)
			{
				printa(*a, f->count_a);
				printa(*b, f->count_b);
				ft_printf("\n");
			}
		}
	}
}

void        smallsort(t_node **a, t_node **b, t_flags *f)
{
    sort_a(a, b, f);
    sort_b(b, a, f);
}