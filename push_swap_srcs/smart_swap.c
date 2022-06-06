/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 02:42:03 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/06 05:28:03 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smart_swap_a(t_pos *stack_a)
{
	if (stack_a->size == 2)
	{
		if (stack_a->head->data > stack_a->head->next->data)
		{
			sa(stack_a);
			return (1);
		}
	}
	else if (stack_a->size >= 3)
	{
		if (stack_a->head->next->next->data > stack_a->head->data
			&& stack_a->head->next->next->data > stack_a->head->next->data)
		{
			sa(stack_a);
			return (1);
		}
	}
	return (0);
}

int	smart_swap_b(t_pos *stack_b)
{
	if (stack_b->size == 2)
	{
		if (stack_b->head->data > stack_b->head->next->data)
		{
			sb(stack_b);
			return (1);
		}
	}
	else if (stack_b->size >= 3)
	{
		if (stack_b->head->next->next->data > stack_b->head->data
			&& stack_b->head->next->next->data > stack_b->head->next->data)
		{
			sb(stack_b);
			return (1);
		}
	}
	return (0);
}
