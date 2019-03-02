#ifndef P_SWAP_H
# define P_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "../../libft/libft.h"

//typedef void (sortit)(t_listp *)(t_fl *);

typedef struct      s_node
{
    int             nb;
    struct s_node   *next;
    struct s_node   *last;
}                   t_node;

typedef struct      s_flags
{
    int             v;
    int             standrd;
    int             count_a;
    int             count_b;
}                   t_flags;

typedef struct      s_listp
{
    struct s_node   *list_a;
    struct s_node   *list_b;
    int             count_a;
    int             count_b;

}                   t_listp;

t_node	*lst_pop(t_node **node);
void    freelist(int size, t_node **head);
void    pushnode(t_listp *lists, char *c_nbr);
int		check_nodes(t_node **current);
void    swapnodes(t_node **list);
void	initstruct(t_listp *lists, t_flags *f);
void    printa(t_node *a, int size);
void	lst_push(char *note, t_node **src, t_node **dst, t_flags *f);
void	rotate(char *n, t_node **h, t_flags *f);
void	rev_rotate(char *note, t_node **head);
void    print_vflag_greeting(void);
void    smallsort(t_node **a, t_node **b, t_flags *f);

#endif