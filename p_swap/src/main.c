#include "../includes/p_swap.h"

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
	while (c > f->v && av[c])
		pushnode(lists, av[c--]);
	if (!(lists->list_a))
		return ;
	if (f->count_a <= 8)
		sort(&(lists->list_a), &(lists->list_b), f);
	printa(lists->list_a, f->count_a);
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