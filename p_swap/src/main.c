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

int     main(int ac, char **av)
{
	int				i;
	t_node			*list;
	t_node			*top;

	list = NULL;
	i = 1;
	if (ac > 1)
		printf("found params\n");
	while (av[i])
		pushnode(&list, &av[i++]);
	top = list; //sort_dirs(&list, flags);
    while (list)
    {
        printf ("nb: %d", list->nb);
        list = list->next;
    }
    freelist(&top);
}