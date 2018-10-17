#ifndef P_SWAP_H
# define P_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "../../libft/libft.h"

typedef struct      s_node
{
    int             nb;
    struct s_node   *next;
}                   t_node;

typedef struct      s_listp
{
    struct s_node   *list_a;
    struct s_node   *list_b;
}                   t_listp;

void    freelist(t_listp *lists);
void    pushnode(t_listp *lists, char **c_nbr);

#endif