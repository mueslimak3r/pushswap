#include "../includes/p_swap.h"

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
