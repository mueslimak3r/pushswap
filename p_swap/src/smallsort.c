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
	while ((*a)->next)
	{
		if ((*a)->nb < (*a)->next->nb)
		{
			//printa(*a, f->count_a);
			//printa(*b, f->count_b);
			lst_push("pb\n", a, b, f);
			//printa(*a, f->count_a);
			//printa(*b, f->count_b);
			//ft_printf("\n");
		}
		else
		{
			//printa(*a, f->count_a);
			//printa(*b, f->count_b);
			swapnodes(a);
			ft_putstr("sa\n");
			//printa(*a, f->count_a);
			//printa(*b, f->count_b);
			//ft_printf("\n");
		}
	}
}

void		sort_b(t_node **b, t_node **a, t_flags *f)
{
	while (*b)
	{
		if (!(*b)->next || (*b)->nb > (*b)->next->nb)
		{
			//printa(*a, f->count_a);
			//printa(*b, f->count_b);
			lst_push("", b, a, f);
			if (!(*b) && is_sorted(*a))
				ft_putstr("pa\n");
			else
				ft_putstr("pa\n");
			//printa(*a, f->count_a);
			//printa(*b, f->count_b);
			//ft_printf("\n");
		}
		else
		{
			//printa(*a, f->count_a);
			//printa(*b, f->count_b);
			//ft_printf("\n");
			swapnodes(b);
			ft_putstr("sb\n");
			//printa(*a, f->count_a);
			//printa(*b, f->count_b);
			//ft_printf("\n");
		}
	}
}

void        smallsort(t_node **a, t_node **b, t_flags *f)
{
    sort_a(a, b, f);
    sort_b(b, a, f);
}