/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:05:38 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/31 04:33:36 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_list(t_pos *pos, char stack)
{
	t_list	*current;
	size_t	i;

	i = 0;
	current = pos->head;
	printf("\nStack %c of size %zu:\n", stack, pos->size);
	while (current != pos->tail)
	{
		printf("Node no %zu: %d\n", i++, current->num);
		current = current->next;
	}
	if (pos->tail)
		printf("Node no %zu: %d\n", i++, current->num);
}
