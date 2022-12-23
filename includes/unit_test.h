/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:30:11 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/23 09:52:11 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TEST_H
# define UNIT_TEST_H

# include <time.h>

/* OPERATIONS */
void	swap(int *a, int *b);

/* SORTING ALGORITHMS */
int		bubble_sort(int	*unsorted, int size);
int		selection_sort(int *unsorted, int size);
int		insertion_sort(int *unsorted, int size);

/* UTILS */
void	summury(int *unsorted, int size, int operations);
int		first_encounter(int number, int *list, int position);
int		*random_numbers(int size, int threshold);

#endif