/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:39:11 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/28 13:41:28 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ra_c(t_pos *stack_a)
{
	if (stack_a->size > 1)
		rotate(stack_a);
}

void	rb_c(t_pos *stack_b)
{
	if (stack_b->size > 1)
		rotate(stack_b);
}

void	rr_c(t_pos *stack_a, t_pos *stack_b)
{
	if (stack_a->size > 1)
		rotate(stack_a);
	if (stack_b->size > 1)
		rotate(stack_b);
}
