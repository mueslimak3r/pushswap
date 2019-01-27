#include "../includes/checkr.h"

void			printa(t_node *a)
{
	while (a)
	{
		ft_printf("%d\n", a->nb);
		if (a->nb == a->next->nb || a->nb > a->next->nb)
			break ;
		a = a->next;
	}
}

void				checksolve(t_node *a, int count_a)
{
	int				count;
	int				i;

	count = 0;
	i = 0;
	while (i < count_a - 1)
	{
		if (a->nb > a->next->nb)
			count += 1;
		a = a->next;
		i++;
	}
	a = a->next;
	if (count == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void				checkrsort(t_listp *lists)
{
	char			*args;

	args = 0;
	while (get_next_line(0, &args))
	{
		ft_printf("%s\n", args);
		if (ft_strequ("ra", args))
			lists->list_a = lists->list_a->next;
		else if (ft_strequ("sa", args))
		{
			swapnodes(&(lists->list_a), lists->list_a->next);
			lists->list_a = lists->list_a->last;
		}
		ft_strdel(&args);
	}
	checksolve(lists->list_a, lists->count_a);
}

int				    checkargs(int ac, char **av)
{
	int			i;

	i = 1;
	if (ac < 2)
	{
		ft_printf("Error\n");
		return (0);
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

int                 main(int ac, char **av)
{
    t_listp			lists;

	initstruct(&lists);
	if (checkargs(ac, av))
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
		checkrsort(&lists);
		freelist(lists.count_a, &(lists.list_a));
		freelist(lists.count_b, &(lists.list_b));
		return (0);
	}
}