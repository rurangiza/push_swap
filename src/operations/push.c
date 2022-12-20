/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:54:42 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/20 17:24:54 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* (push a): Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
*/
void    pa()
{
    
}

/* (push b): Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
*/
void    pb()
{
    
}

/* Add an element to the top of a stack */
void    push(int node_content, t_dllist *stack)
{
    t_dllist *node;
    
    node = dll_create_node(node_content);
    if (node == NULL)
    {
        error_msg(0, "couldn't create new node");
		ft_lstclear(stack, ft_lstdelone);
        return ;
    }
    dll_add_back(stack, node);
}
