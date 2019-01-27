#include "../includes/p_swap.h"

void			printa(t_node *a, int size)
{
	ft_printf("size: %d\n", size);
	while (a && size > 0)
	{
		ft_printf("    %d\n", a->nb);
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
	if (av[i][0] == 'v' && !av[i][1])
		f->v = 1;
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
		if (*(++av))
		{
			pushnode(&lists, *(av++));
			lists.tail_a = lists.list_a;
			while (*av)
				pushnode(&lists, *(av++));
			lists.list_a->last = lists.tail_a;
			lists.tail_a->next = lists.list_a;
			small_sort(&lists, &f);
			freelist(lists.count_a, &(lists.list_a));
			freelist(lists.count_b, &(lists.list_b));
			return (0);
		}
	}
	return (1);
}