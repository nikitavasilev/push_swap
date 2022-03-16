/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:05:38 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/16 20:07:10 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_list(t_pos *pos)
{
	t_list	*current;
	size_t	i;

	i = 0;
	current = pos->head;
	while (current != pos->tail)
	{
		printf("Node no %zu: %d\n", i++, current->num);
		current = current->next;
	}
	printf("Node no %zu: %d\n", i++, current->num);
}
