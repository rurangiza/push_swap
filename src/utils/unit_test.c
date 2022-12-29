/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:46:49 by Arsene            #+#    #+#             */
/*   Updated: 2022/12/29 12:08:37 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*/

#include "../../includes/push_swap.h"

// empty input, duplicates, non-digits, integer overflow


// 1 : generate a random number
// 3 : generate 10 combinations of 3 random numbers
// 5 : generate 10 combinations of 5 random numbers
// 100 : generate 10 combinations of 
// 500 :

int main(void)
{
    int random_1 = malloc(sizeof(int) * 1);
    int *random_3 = malloc(sizeof(int) * 3);
    int *random_5 = malloc(sizeof(int) * 5);
    int *random_100 = malloc(sizeof(int) * 100);
    int *random_500 = malloc(sizeof(int) * 500);
    int threshold = 500;
    /* ARRANGE
     * Set up the conditions for your test. This might involve creating objects,
     * setting up variables or anything else that’s required for your test.
    */
    random_1 = random_numbers(1, threshold);
    random_3 = random_numbers(3, 100);
    random_5 = random_numbers(5, 100);
    random_100 = random_numbers(100, 500);
    random_500 = random_numbers(500, 1000);

    /* ACT
     * This is where you actually execute the code that you are testing.
    */

    /* ASSERT
     * Verify that the code you’re testing behaves as expected. This might
     * involve checking the value of a variable, or verifying that a certain
     * method was called.
    */
}