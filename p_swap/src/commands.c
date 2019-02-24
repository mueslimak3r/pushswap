#include "../includes/p_swap.h"

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
	if (!(ft_strcmp("pb ", note)))
	{
		f->count_b += 1;
		f->count_a -= 1;
	}
	else
	{
		f->count_a += 1;
		f->count_b -= 1;
	}
	*dst = temp;
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
