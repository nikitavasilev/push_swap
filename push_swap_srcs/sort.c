/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 08:02:52 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/06 04:35:20 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	sort(t_pos *stack_a, t_pos *stack_b)
{
	/*t_values	*a_values;

	a_values = find_median(stack_a);
	if (!a_values)
		return (0);*/
	(void)stack_b;
	if (is_sorted(stack_a))
	{
		//free(a_values);
		return (1);
	}
	if (stack_a->size <= 50)
		selection_sort(stack_a, stack_b);
	else
		partial_sort(stack_a, stack_b);
	//free(a_values);
	return (1);
}
