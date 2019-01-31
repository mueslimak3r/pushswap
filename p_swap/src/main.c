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

int     		main(int ac, char **av)
{
	t_listp			lists;
	t_flags				f;

	initstruct(&lists, &f);
	if (checkargs(ac, av, &f))
	{
		if (f.v)
		{
			ft_printf("Push Swap by calamber\n\nSyntax of -v ");
			ft_printf("mode:\ncommand      list a            ");
			ft_printf("list b\n       list before operation\n");
			ft_printf("       list after operation\n");
			av++;
		}
		if (*(++av))
		{
			while (*av)
				pushnode(&lists, *(av++));
			small_sort(&lists, &f);
			freelist(lists.count_a, &(lists.list_a));
			freelist(lists.count_b, &(lists.list_b));
			return (0);
		}
	}
	return (1);
}