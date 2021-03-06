/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shortest_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 02:46:52 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/28 01:02:28 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_shortest_path(size_t index, size_t size, t_pos *stack)
{
	if (index > size / 2)
	{
		while (index < size)
		{
			rra(stack);
			index++;
		}
	}
	else
	{
		while (index > 0)
		{
			ra(stack);
			index--;
		}
	}
	return (index);
}
