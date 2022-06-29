/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:51:51 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/28 13:53:40 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rra_c(t_pos *stack_a)
{
	if (stack_a->size > 1)
		rrotate(stack_a);
}

void	rrb_c(t_pos *stack_b)
{
	if (stack_b->size > 1)
		rrotate(stack_b);
}

void	rrr_c(t_pos *stack_a, t_pos *stack_b)
{
	if (stack_a->size > 1 && stack_b->size > 1)
	{
		rrotate(stack_a);
		rrotate(stack_b);
	}
}
