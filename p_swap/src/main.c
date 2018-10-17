#include "../includes/p_swap.h"

t_node			*swapnodes(t_node **list, t_node **next)
{
	int			nbr;

	nbr = (*next)->nb;
	(*next)->nb = (*list)->nb;
	(*list)->nb = nbr;
	return (*list);
}

int				check_nodes(t_node **current)
{
	if ((*current)->nb > (*current)->next->nb)
		return (1);
	return (0);
}

void			ft_bubblesort(t_listp *lists)
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
				swapnodes(&current, &(current->next));
				swap = 1;
			}
			current = current->next;
		}
	}
}

t_listp			initstruct(void)
{
	t_listp		lists;

	lists.list_a = NULL;
	lists.list_b = NULL;
	return (lists);
}

int     		main(int ac, char **av)
{
	int				i;
	t_listp			lists;

	lists = initstruct();
	i = 1;
	if (ac > 1)
	{
		while (av[i])
			pushnode(&lists, &av[i++]);
		ft_bubblesort(&lists);
		while (lists.list_a)
		{
			printf ("%d", lists.list_a->nb);
			if (lists.list_a->next)
				printf(" ");
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