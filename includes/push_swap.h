/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:26:35 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/20 17:07:12 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/library/libft.h"
# include <stdlib.h> // malloc, free

/* TYPEDEFS AND STRUCTURES */
typedef struct s_list {
	int            content;
	int				index;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

/* FUNCTION PROTOTYPES */
int		valid_number(char **arg_list, int index, int arg_type);
void    push(int node_content, t_list *stack);
int		first_encounter(int number, char *arguments, int position, int arg_type);
char	**init_matrix(int arg_count, char **argv, int *arg_type, int *index);

# endif