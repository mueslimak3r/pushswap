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

struct listp
{
    struct s_node   *list_a;
    struct s_node   *list_b;
    int             top_a;
    int             top_b;
    int             tail_a;
    int             tail_b;
};

void    freelist(t_node **list);
void    pushnode(t_node **node, char **c_nbr);

#endif