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
	int			swap;
	t_node		*current;

	current = NULL;
	swap = 1;
	while (swap == 1)
	{
		current = lists->list_a;
		swap = 0;
		while (current)
		{
			if (check_nodes(&current) == 1)
			{
				swapnodes(&current, &(current->next));
				swap = 1;
				break ;
			}
			current = current->next;
		}
	}
}

int     		main(int ac, char **av)
{
	int				i;
	t_listp			lists;
	t_node			*tail;

	lists = initstruct();
	i = 1;
	if (ac > 1)
	{
		if (av[i])
		{
			pushnode(&lists, &av[i++]);
			tail = lists.list_a;
		}
		while (av[i])
			pushnode(&lists, &av[i++]);
		tail->next = lists.list_a;
		sort(&lists);
		while (lists.list_a)
		{
			printf ("%d", lists.list_a->nb);
			if (lists.list_a->next)
				printf(" ");
			if (lists.list_a->next->nb < lists.list_a->nb)
			{
				lists.list_a = lists.list_a->next;
				break ;
			}
			lists.list_a = lists.list_a->next;
		}
		freelist(&lists);
		printf("\n");
	}
	else
	{
		write(2, "usage: push_swap [int] [int] ...\n", 34);
		return (1);
	}
	return (0);
}