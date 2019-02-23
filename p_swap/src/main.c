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
	if (ft_strequ("-v", av[i]))
	{
		f->v = 1;
		i++;
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
	return (1);
}

void			checksort(char **av, t_listp *lists, t_flags *f, int c)
{
	t_node		*a;
	t_node		*b;

	while (c > 1 && av[c - 1])
	{
		pushnode(lists, av[c - 1]);
		c--;
	}
	if (!(lists->list_a))
		return ;
	f->count_a = lists->count_a;
	f->count_b = lists->count_b;
	a = lists->list_a;
	b = lists->list_b;
	if (c <= 5)
		;//	do_smallsort(&a, &b, f);
	printa(a, f->count_a);
	lists->count_a = f->count_a;
	lists->count_b = f->count_b;
}

int     		main(int ac, char **av)
{
	t_listp			lists;
	t_flags			f;
	int			count;

	count = 1;
	initstruct(&lists, &f);
	if (checkargs(ac, av, &f))
	{
		if (f.v)
		{
			print_vflag_greeting();
			count++;
		}
		if (av[count])
		{
			while (av[count])
				count++;
			checksort(av, &lists, &f, count);
			freelist(lists.count_a, &(lists.list_a));
			freelist(lists.count_b, &(lists.list_b));
			return (0);
		}
	}
	return (1);
}