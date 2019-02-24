#include "../includes/p_swap.h"

void			printa(t_node *a, int size)
{
	while (a && size > 0)
	{
		ft_printf(((size != 1) ? ("%-4d") : ("%-4d\n")), a->nb);
		a = a->next;
		size--;
	}
}

int				checkargs(int ac, char **av, t_flags *f)
{
	int			i;

	i = 1;
	if (ac < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (ft_strequ("-v", av[1]))
	{
		f->v = 1;
		print_vflag_greeting();
		i = 2;
	}
	while (av[i])
	{
		if (ft_atoi(av[i]) == 0 && !(ft_strequ("0", av[i])))
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	f->count_a = i - 1;
	return (1);
}

void			checksort(char **av, t_listp *lists, t_flags *f, int c)
{
	t_node		*a;
	t_node		*b;

	while (c > f->v && av[c])
		pushnode(lists, av[c--]);
	if (!(lists->list_a))
		return ;
	a = lists->list_a;
	b = lists->list_b;
	if (f->count_a <= 5)
		smallsort(&a, &b, f);
	printa(a, f->count_a);
	printa(b, f->count_b);
	lists->count_a = f->count_a;
	lists->count_b = f->count_b;
}

int     		main(int ac, char **av)
{
	t_listp			lists;
	t_flags			f;

	initstruct(&lists, &f);
	if (checkargs(ac, av, &f))
	{
		checksort(av, &lists, &f, f.count_a);
		freelist(lists.count_a, &(lists.list_a));
		freelist(lists.count_b, &(lists.list_b));
		return (0);
	}
	return (1);
}