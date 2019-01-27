#include "../includes/p_swap.h"

void			pushb(t_node **a, t_node **b, t_flags *f)
{
	t_node		*temp;


	(*a)->last->next = (*a)->next;
	(*a)->next->last = (*a)->last;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	if (*b)
		(*b)->last = temp;
	f->count_b += 1;
	f->count_a -= 1;
	*b = temp;
}
