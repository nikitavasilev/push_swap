/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:57:14 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/28 14:00:29 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	pa_c(t_pos *stack_b, t_pos *stack_a)
{
	if (stack_b->head)
	{
		push(stack_b, stack_a);
		stack_a->size++;
		stack_b->size--;
	}
}

void	pb_c(t_pos *stack_a, t_pos *stack_b)
{
	if (stack_a->head)
	{
		push(stack_a, stack_b);
		stack_b->size++;
		stack_a->size--;
	}
}
