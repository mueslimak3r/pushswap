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

#endif