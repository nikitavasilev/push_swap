/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:54:57 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/28 13:56:30 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sa_c(t_pos *stack_a)
{
	if (stack_a->size > 1)
		swap(stack_a);
}

void	sb_c(t_pos *stack_b)
{
	if (stack_b->size > 1)
		swap(stack_b);
}

void	ss_c(t_pos *stack_a, t_pos *stack_b)
{
	if (stack_a->size > 1 && stack_b->size > 1)
	{
		swap(stack_a);
		swap(stack_b);
	}
}
