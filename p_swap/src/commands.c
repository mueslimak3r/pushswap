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

void			rotate_a(t_node **head, t_node *headp)
{
	t_node	*temp;
	t_node	*top;

	ft_printf("ra\n");
	temp = headp;
	top = headp;
	*head = (*head)->next;
	(*head)->last = 0;
	while (temp->next)
		temp = temp->next;	
	temp->next = top;
	top->next = 0;
	top->last = temp;
}
