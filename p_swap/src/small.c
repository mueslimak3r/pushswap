#include "../includes/p_swap.h"

void			fill_b(t_node **a, t_node **b, t_flags *f)
{
	int			i;

	i = 0;
	if (*b)
	{
		;
	}
	while (i < f->count_a - 1)
	{
		if ((*a)->nb > (*a)->next->nb)
		{
			ft_printf("sa");
			if (f->v)
			{
				ft_printf("      ");
				printa(*a, f->count_a);
			}
			swapnodes(a, (*a)->next);
			if (f->v)
			{
				ft_printf("        ");
				printa((*a)->last, f->count_a);
			}
			ft_printf("\n");
		}
		i++;
		*a = (*a)->next;
		ft_printf("ra\n");
	}
}

int				checksort(t_node *head)
{
	int			count;

	count = 0;
	while (head && head->next)
	{
		if ((head)->nb > (head)->next->nb)
			count += 1;
		head = head->next;
	}
	if (count == 0)
		return (1);
	return (0);
}

void			do_smallsort(t_node **a, t_node **b, t_flags *f)
{
	int			count;
	int			i;
	t_node 		*head;

	i = 0;
	count = 1;
	if (*b)
	{
		;
	}
	head = *a;
	while (count > 0)
	{
		count = 0;
		i = 0;
		while (head && i < f->count_a)
		{
			if (head && head->next && (head)->nb > (head)->next->nb)
			{
				count += 1;
				ft_printf("sa");
				if (f->v)
				{
					ft_printf("  ");
					printa(head, f->count_a);
				}
				swapnodes(&head, head->next);
				if (f->v)
				{
					ft_printf("    ");
					printa(head, f->count_a);
				}
				ft_printf("\n");
			}
			i++;
			if (checksort(head))
				break ;
			else
				rotate_a("ra", &head, head, f);
		}
	}
}

void			small_sort(t_listp *lists, t_flags *f)
{
	t_node		*a;
	t_node		*b;

	if (!(lists->list_a))
		return ;
	f->count_a = lists->count_a;
	f->count_b = lists->count_b;
	a = lists->list_a;
	b = lists->list_b;
	ft_printf("counta: %d\n", f->count_a);
	do_smallsort(&a, &b, f);
	printa(a, f->count_a);
	lists->count_a = f->count_a;
	lists->count_b = f->count_b;
}

/*
void			small_sort(t_listp *lists, t_flags *f)
{
	int			count;
	int			i;
	t_node		*a;

	i = 0;
	count = 1;
	if (!(lists->list_a))
		return ;
	a = lists->list_a;
    //printa(a, lists->count_a);
	while (count > 0)
	{
		count = 0;
		i = 0;
		while (i < lists->count_a - 1)
		{
			if (a->nb > a->next->nb)
			{
				count += 1;
				ft_printf("sa");
				if (f->v)
				{
					ft_printf("  ");
					//printa(a);
				}
				swapnodes(&a, a->next);
				if (f->v)
				{
					ft_printf("\n\n");
					//printa(a);
				}
				a = a->last;
				ft_printf("\n");
			}
			i++;
			a = a->next;
			ft_printf("ra\n");
		}
		a = a->next;
		ft_printf("ra\n");
	}
    //printa(a, lists->count_a);
}
*/
