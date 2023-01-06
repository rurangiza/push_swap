/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:24:01 by arurangi          #+#    #+#             */
/*   Updated: 2023/01/06 10:13:05 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	divisions_by_two(int nbr)
{
	int	count;
	
	count = 0;
	while (nbr > 2)
	{
		nbr /= 2;
		count++;
	}
	return (count);
}




