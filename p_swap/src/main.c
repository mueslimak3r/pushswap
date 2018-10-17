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

t_node			*ft_bubblesort(t_node **top)
{
	int			swap;
	t_node		*current;

	current = NULL;
	swap = 1;
	while (swap == 1)
	{
		current = *top;
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
	return (*top);
}

struct listp	initstruct(void)
{
	struct listp	lists;

	lists.list_a = NULL;
	lists.list_b = NULL;
	lists.top_a = 0;
	lists.top_b = 0;
	lists.tail_a = 0;
	lists.tail_b = 0;
	return (lists);
}

int     		main(int ac, char **av)
{
	int				i;
	//struct listp	lists;
	t_node			*list;
	t_node			*top;

	//lists = initstruct();
	list = NULL;
	i = 1;
	if (ac > 1)
	{
		while (av[i])
			pushnode(&list, &av[i++]);
		top = ft_bubblesort(&list);
		while (list)
		{
			printf ("%d", list->nb);
			if (list->next)
				printf(" ");
			list = list->next;
		}
		freelist(&top);
		printf("\n");
	}
	else
	{
		write(2, "usage: push_swap [int] [int] ...\n", 34);
		return (1);
	}
	return (0);
}