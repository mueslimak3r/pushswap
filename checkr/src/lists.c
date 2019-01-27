#include "../includes/checkr.h"

void			pushnode(t_listp *lists, char *c_nbr)
{
	t_node		*new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return ;
	new->nb = ft_atoi(c_nbr);
	new->next = lists->list_a;
	if (lists->list_a)
		lists->list_a->last = new;
	lists->count_a += 1;
	lists->list_a = new;
}

void	freelist(int size, t_node **head)
{
	t_node *swap;

	swap = NULL;
	while (*head && size > 0)
	{
		if (*head)
		{
			swap = *head;
			*head = (*head)->next;
			swap->next = 0;
			swap->last = 0;
			free (swap);
			//ft_printf("Done!\n");
		}
		size--;
	}
}

void			initstruct(t_listp *lists)
{
	lists->list_a = 0;
	lists->list_b = 0;
	lists->tail_a = 0;
	lists->tail_b = 0;
	lists->count_a = 0;
	lists->count_b = 0;
}

void			swapnodes(t_node **list, t_node *next)
{
	(*list)->next = next->next;
	(next)->next = *list;
	(next)->last = (*list)->last;
	(*list)->last->next = next;
	(*list)->last = next;
}

int				check_nodes(t_node **current)
{
	if ((*current)->nb > (*current)->next->nb)
		return (1);
	return (0);
}