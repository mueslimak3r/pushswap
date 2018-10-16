#include "../includes/p_swap.h"

void			pushnode(t_node **node, int nb)
{
	t_node		*new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return ;
	new->nb = nb;
	new->next = *node;
	*node = new;
}

int     main(int ac, char **av)
{
    int				argsize;
	int				i;
	t_node			*list;
	t_node			*top;

	list = NULL;
	i = 1;
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