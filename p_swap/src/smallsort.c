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
			lst_push("pb ", a, b, f);
		}
		else
		{
			swapnodes(a);
			ft_putstr("sa ");
		}
	}
}

void		sort_b(t_node **b, t_node **a, t_flags *f)
{
	while (*b)
	{
		if (!(*b)->next || (*b)->nb > (*b)->next->nb)
		{
			lst_push("", b, a, f);
			if (!(*b) && is_sorted(*a))
				ft_putstr("pa\n");
			else
				ft_putstr("pa ");
		}
		else
		{
			swapnodes(b);
			ft_putstr("sb ");
		}
	}
}

void        smallsort(t_node **a, t_node **b, t_flags *f)
{
    sort_a(a, b, f);
    sort_b(a, b, f);
}