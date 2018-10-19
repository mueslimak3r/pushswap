#include "../includes/p_swap.h"

void			pushnode(t_listp *lists, char **c_nbr)
{
	t_node		*new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return ;
	new->nb = ft_atoi(*c_nbr);
	new->next = lists->list_a;
	
	lists->list_a = new;
}

void	freelist(t_listp *lists)
{
	t_node *swap;

	swap = NULL;
	while (lists->list_a)
	{
		swap = lists->list_a;
		lists->list_a = lists->list_a->next;
		swap->next = NULL;
		free (swap);
	}
}

t_listp			initstruct(void)
{
	t_listp		lists;

	lists.list_a = NULL;
	lists.list_b = NULL;
	return (lists);
}

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