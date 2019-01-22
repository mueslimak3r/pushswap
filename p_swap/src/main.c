#include "../includes/p_swap.h"

/*void			sort(t_listp *lists)
{
	int			swap;
	t_node		*current;

	current = NULL;
	swap = 1;
	while (swap == 1)
	{
		current = lists->list_a;
		swap = 0;
		while (current->next)
		{
			if (check_nodes(&current) == 1)
			{
				push_d();
				swap = 1;
			}
		}
	}
}*/

void			sort(t_listp *lists)
{
	int			count;
	int			i;
	t_node		*a;
	//t_node		*b;

	i = 0;
	count = 1;
	if (!(lists->list_a))
		return ;
	a = lists->list_a;
	//b = lists->list_b;
	//printf("%d\n", lists->count_a);
	while (count > 0)
	{
		count = 0;
		i = 0;
		while (i < lists->count_a - 1)
		{
			//printf("prior-a: %d an: %d i: %d\n", a->nb, a->next->nb, i);
			if (a->nb > a->next->nb)
			{
				count += 1;
				swapnodes(&a, a->next);
				a = a->last;
				printf("sa\n");
				//printf("after-a: %d an: %d i: %d count: %d\n", a->nb, a->next->nb, i, count);
			}
			i++;
			a = a->next;
			printf("ra\n");
		}
		a = a->next;
		printf("ra\n");
		//printf("afterl: %d %d %d %d i: %d c: %d\n", a->nb, a->next->nb, a->next->next->nb, a->next->next->next->nb, i, count);
	}
	//printa(a);
}

int				checkargs(int ac, char **av)
{
	int			i;

	i = 1;
	if (ac < 2)
	{
		write(2, "Error\n", 29);
		return (0);
	}
	while (av[i])
	{
		if (ft_atoi(av[i]) == 0 && !(ft_strequ("0", av[i])))
		{
			write(2, "Error\n", 29);
			return (0);
		}
		i++;
	}
	return (1);
}

int     		main(int ac, char **av)
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
		sort(&lists);
		freelist(&lists);
		return (0);
	}
	return (1);
}