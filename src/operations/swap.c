/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:54:27 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/26 16:33:54 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* (swap a): Swap the first 2 elements at the top of stack a. 
 * Do nothing if there is only one or no elements.
*/

// static void	swap(int *a, int *b)
// {
// 	int	tmp;

// 	tmp = *a;
// 	*a = *b;
// 	*b = tmp;
// }

void    sa(t_node *stack_a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stack_a->next;
	if (first->next == NULL)
		return ;
	second = first->next;
	if (second->next == NULL)
		return ;
	third = second->next;
	
	stack_a->next = second;
	first->next = second->next;
	second->next = first;
	
	second->previous = stack_a;
	first->previous = second;
	third->previous = first;

	t_node *stack_b = NULL;
	display_stack(stack_a, stack_b);
	//write(1, "sa\n", 3);
}


/* (swap b): Swap the first 2 elements at the top of stack b.
 * Do nothing if there is only one or no elements.
*/
void    sb()
{
    
}

/* sa and sb at the same time. */
void    ss()
{
    
}