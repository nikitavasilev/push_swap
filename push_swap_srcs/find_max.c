/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:30:51 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/06 05:31:33 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_pos *stack)
{
	t_list	*current;
	int		max;

	current = stack->head;
	max = current->data;
	while (current)
	{
		if (current->data > max)
			max = current->data;
		current = current->next;
	}
	return (max);
}
