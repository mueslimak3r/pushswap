#include "../includes/p_swap.h"

void			printa(t_node *a, int size)
{
	while (a && size > 0)
	{
		ft_printf("%-4d", a->nb);
		a = a->next;
		size--;
	}
	ft_printf("\n");
}

t_node			*lst_pop(t_node **node)
{
	t_node		*temp;

	if ((*node)->next)
		(*node)->next->last = 0;
	temp = *node;
	*node = (*node)->next;
	temp->next = 0;
	temp->last = 0;
	
	return (temp);
}

void			lst_push(char *note, t_node **src, t_node **dst, t_flags *f)
{
	t_node		*temp;

	ft_printf("%s", note);
	temp = lst_pop(src);
	temp->next = *dst;
	if (*dst)
		(*dst)->last = temp;
	*dst = temp;
	if (!(ft_strcmp("pb\n", note)))
	{
		f->count_b += 1;
		f->count_a -= 1;
	}
	else
	{
		f->count_a += 1;
		f->count_b -= 1;
	}
}

void			rotate(char *n, t_node **h, t_flags *f)
{
	t_node	*temp;
	t_node	*top;

	ft_printf("%s", n);
	temp = *h;
	top = *h;
	*h = (*h)->next;
	(*h)->last = 0;
	while (temp->next)
		temp = temp->next;	
	temp->next = top;
	top->next = 0;
	top->last = temp;
}

void			rev_rotate(char *note, t_node **head)
{
	t_node	*temp;
	t_node	*top;

	ft_printf("%s\n", note);
	temp = *head;
	top = *head;
	(*head)->last = 0;
	while (temp->next)
		temp = temp->next;
	temp->last->next = 0;
	temp->last = 0;
	temp->next = top;
	top->last = temp;
	*head = temp;
}

void			swapnodes(t_node **list)
{
	t_node *temp;

	temp = (*list)->next;
	(*list)->next = temp->next;
	temp->next = *list;
	temp->last = 0;
	(*list)->last = temp;
	*list = temp;
}
