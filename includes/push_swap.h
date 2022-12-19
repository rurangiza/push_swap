/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:26:35 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/19 13:50:32 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/library/libft.h"
# include <stdlib.h> // malloc, free

/* TYPEDEFS AND STRUCTURES */
typedef struct s_list {
	int             data;
	struct s_list	*next;
}	t_list;

/* FUNCTION PROTOTYPES */
int count_numbers(int ac, char **av);
void    push(int node_content, t_list **stack);
int	first_encounter(int number, char *arguments, int position);
int count_numbers(int ac, char **av);

# endif