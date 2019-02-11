#include "../includes/p_swap.h"

void			pushb(char *note, t_node **a, t_node **b, t_flags *f)
{
	t_node		*temp;

	ft_printf("%s\n", note);
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

void			rotate_a(char *n, t_node **h, t_node *hp, t_flags *f)
{
	t_node	*temp;
	t_node	*top;

	ft_printf("%s", n);
	if (f->v)
	{
		ft_printf("  ");
		printa(*h, f->count_a);
	}
	temp = hp;
	top = hp;
	*h = (*h)->next;
	(*h)->last = 0;
	while (temp->next)
		temp = temp->next;	
	temp->next = top;
	top->next = 0;
	top->last = temp;
	if (f->v)
	{
		ft_printf("    ");
		printa(*h, f->count_a);
	}
	ft_printf("\n");
}

void			rev_rotate_a(char *note, t_node **head, t_node *headp)
{
	t_node	*temp;
	t_node	*top;

	ft_printf("%s\n", note);
	temp = headp;
	top = headp;
	(*head)->last = 0;
	while (temp->next)
		temp = temp->next;
	temp->last->next = 0;
	temp->last = 0;
	temp->next = top;
	top->last = temp;
	*head = temp;
}

void			swapnodes(t_node **list, t_node *next)
{

	(*list)->next = next->next;
	(next)->next = *list;
	(next)->last = (*list)->last;
	if ((*list)->last && next)
		(*list)->last->next = next;
	(*list)->last = next;
	*list = next;
}
