#include "../includes/p_swap.h"

void			pushnode(t_node **node, char **c_nbr)
{
	t_node		*new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return ;
	new->nb = ft_atoi(*c_nbr);
	new->next = *node;
	*node = new;
}

void	freelist(t_node **list)
{
	t_node *swap;

	swap = NULL;
	while (*list)
	{
		swap = *list;
		*list = (*list)->next;
		swap->next = NULL;
		free (swap);
	}
}
