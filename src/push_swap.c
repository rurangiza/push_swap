/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:26:12 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/15 12:48:40 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Sort data on a stack
 * with limited set of instructions
 * using the lowest number of actions
*/

#include "../includes/push_swap.h"

int nbrlen(int *nbr)
{
    int i;

    i = 0;
    while (nbr[i])
        i++;
    return (i);
}

int main(void)
{
    int unsorted[] = {2, 4, 8, 1};
    
    int i = 0;
    int tmp;
    int permutation_count;

    while (i < nbrlen(unsorted) - 1)
        info_msg(1, "%d", unsorted[i++]);

    permutation_count = 1;
    while (permutation_count > 0)
    {
        permutation_count = 0;
        if (i < 3 && unsorted[i] < unsorted[i] + 1)
        {
            tmp = unsorted[i];
            unsorted[i] = unsorted[i + 1];
            unsorted[i + 1] = tmp;
            permutation_count++;
        }
        i++;
    }
    success_msg(1, "sorted");

    i = 0;
    while (i < nbrlen(unsorted) - 1)
        info_msg(1, "%d", unsorted[i++]);
    return (0);
}