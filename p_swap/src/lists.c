#include "../includes/p_swap.h"

void			fillb(t_node **a, t_node **b, t_flags *f)
{
	while (*a)
		lst_push("pb\n", a, b, f);
}

void			pushnode(t_listp *lists, char *c_nbr)
{
	t_node		*new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return ;
	new->nb = ft_atoi(c_nbr);
	new->next = lists->list_a;
	new->last = 0;
	if (lists->list_a)
		lists->list_a->last = new;
	lists->count_a += 1;
	lists->list_a = new;
}

void	freelist(int size, t_node **head)
{
	t_node *swap;

	while (*head && size > 0)
	{
		swap = *head;
		*head = (*head)->next;
		swap->next = 0;
		swap->last = 0;
		free (swap);
		size--;
	}
}

void			initstruct(t_listp *lists, t_flags *f)
{
	lists->list_a = 0;
	lists->list_b = 0;
	lists->count_a = 0;
	lists->count_b = 0;
	f->v = 0;
	f->standrd = 0;
	f->count_a = 0;
	f->count_b = 0;
}

int				check_nodes(t_node *current)
{
	if (current->nb > current->next->nb)
		return (1);
	return (0);
}

void			print_vflag_greeting(void)
{
	ft_printf("Push Swap by calamber\n\nSyntax of -v ");
	ft_printf("mode:\ncommand      list a            ");
	ft_printf("list b\n       list before operation\n");
	ft_printf("       list after operation\n");
}
