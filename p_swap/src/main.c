#include "../includes/p_swap.h"

void			printa(t_node *a)
{
	while (a)
	{
		ft_printf("    %d\n", a->nb);
		if (a->nb == a->next->nb || a->nb > a->next->nb)
			break ;
		a = a->next;
	}
}

void			sort(t_listp *lists, t_f *f)
{
	int			count;
	int			i;
	t_node		*a;

	i = 0;
	count = 1;
	if (!(lists->list_a))
		return ;
	a = lists->list_a;
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
					printa(a);
				}
				swapnodes(&a, a->next);
				if (f->v)
				{
					ft_printf("\n\n");
					printa(a);
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
}

int				checkargs(int ac, char **av, t_f *f)
{
	int			i;
	int			v;

	v = 0;
	i = 1;
	if (ac < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (av[i][0] == 'v' && !av[i][1])
		v = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) == 0 && !(ft_strequ("0", av[i])))
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1 + v);
}

int     		main(int ac, char **av)
{
	t_listp			lists;
	t_f				f;

	initstruct(&lists, &f);
	if (checkargs(ac, av, &f))
	{
		if (*(++av))
		{
			pushnode(&lists, *(av++));
			lists.tail_a = lists.list_a;
			while (*av)
				pushnode(&lists, *(av++));
		}
		lists.list_a->last = lists.tail_a;
		lists.tail_a->next = lists.list_a;
		sort(&lists, &f);
		freelist(&lists);
		return (0);
	}
	return (1);
}