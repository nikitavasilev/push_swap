/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 02:44:10 by nvasilev          #+#    #+#             */
/*   Updated: 2022/05/27 02:44:49 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_pos *stack)
{
	t_list	*current;
	int		min;

	current = stack->head;
	min = current->data;
	while (current)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	return (min);
}
