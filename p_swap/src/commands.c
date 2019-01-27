#include "../includes/p_swap.h"

void			pushb(t_listp *lists, char *c_nbr)
{
	t_node		*temp;

	temp = lists->list_a;
	new->next = lists->list_b;
	if (lists->list_a)
		lists->list_a->last = new;
	lists->count_a += 1;
	lists->list_b = temp;
}