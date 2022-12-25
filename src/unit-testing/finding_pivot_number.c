/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_pivot_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 09:52:50 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/25 17:39:31 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

typedef struct s_node {
	int	content;
	struct s_node	*next;
	struct s_node	*previous;
	int				index;
	int				order;
}	t_node;

int	calc_average(t_node *stack_a, int start, int end)
{
	int	stack_size;
	int	sum;
	int	average;

	stack_size = get_list_size(stack_a);
	sum = 0;
	while (stack_a)
	{
		sum += stack_a->content;
		stack_a = stack_a->next;
	}
	average = sum / stack_size;
	return (average);
}

int	ft_abs(int x)
{
	if (x < 0)
		return -x;
	else
		return (x);
}

int	find_pivot(t_node *stack_a)
{
	int	closest;
	int	closest_number;
	int	target;

	target = calc_average(stack_a);
	
	closest = INT_MAX;
	closest_number = 0;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (ft_abs(stack_a->content - target) < ft_abs(closest - target))
		{
			closest = stack_a->content;
			closest_number = stack_a->content;
		}
		stack_a = stack_a->next;
	}
	return (closest_number);
}

int main(void)
{
    t_node  *stack_a;
    int     size;
    int     pivot;
    
    size = 10;
    stack_a = malloc(sizeof(t_node) * size);
    pivot = finc_pivot(stack_a);
    printf("pivot: %d\n", pivot);

    return (0);
}