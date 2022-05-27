/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 02:47:55 by nvasilev          #+#    #+#             */
/*   Updated: 2022/05/27 07:05:08 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"

static void	push_to_b(t_pos *stack_a, t_pos *stack_b, int median)
{
	t_list	*current;

	current = stack_a->head;
	while (current)
	{
		if (stack_a->size == 1)
			return ;
		if (current->data != median)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		current = stack_a->head;
	}
}

void	insertion_sort(t_pos *stack_a, t_pos *stack_b, int median)
{
	t_list	*current;

	printf("median = %d\n", median);
	push_to_b(stack_a, stack_b, median);
	current = stack_b->head;
	print_stacks(stack_a, stack_b);
}
