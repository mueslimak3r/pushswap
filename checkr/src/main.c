#include "../includes/checkr.h"

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

void				checkrsort(t_listp *lists, t_flags *f)
{
	char			*args;

	args = 0;
	while (get_next_line(0, &args))
	{
		ft_printf("%s\n", args);
		if (ft_strequ("ra", args))
			rotate("ra\n", &(lists->list_a));
		else if (ft_strequ("rra", args))
			rev_rotate("rra\n", &(lists->list_a));
		else if (ft_strequ("rb", args))
			rotate("rb\n", &(lists->list_b));
		else if (ft_strequ("rrb", args))
			rev_rotate("rb\n", &(lists->list_b));
		else if (ft_strequ("sa", args))
		{
			swapnodes(&(lists->list_a));
		}
		else if (ft_strequ("sb", args))
		{
			swapnodes(&(lists->list_b));
		}
		else if (ft_strequ("pb", args))
		{
			lst_push("pb\n", &(lists->list_a), &(lists->list_b), f);
		}
		else if (ft_strequ("pa", args))
		{
			lst_push("pa\n", &(lists->list_b), &(lists->list_a), f);
		}
		ft_strdel(&args);
	}
	checksolve(lists->list_a, lists->count_a);
}

int				    checkargs(int ac, char **av, int *c)
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
	*c = i - 1;
	return (1);
}

int                 main(int ac, char **av)
{
    t_listp			lists;
	t_flags			f;
	int				count;
	int				count2;

	count = 0;
	initstruct(&lists, &f);
	if (checkargs(ac, av, &count))
	{
		count2 = count;
		if (av[count])
		{
			while (av[count] && count > 0)
			{
				pushnode(&lists, av[count]);
				count--;
			}
		}
		f.count_a = lists.count_a;
		checkrsort(&lists, &f);
		freelist(lists.count_a, &(lists.list_a));
		freelist(lists.count_b, &(lists.list_b));
		return (0);
	}
}