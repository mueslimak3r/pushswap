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
