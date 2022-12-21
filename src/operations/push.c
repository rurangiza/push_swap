/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:54:42 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/21 09:40:30 by Arsene           ###   ########.fr       */
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
		dll_clear_all(&stack, dll_clear_one);
        return ;
    }
    dll_add_back(&stack, node);
}
