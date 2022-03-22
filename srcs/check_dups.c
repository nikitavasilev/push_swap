/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dups.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 23:06:45 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/22 11:32:28 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

void	check_dups(t_pos *pos, int *err)
{
	t_list	*current;

	current = pos->head;
	while (current != pos->tail)
	{
		if (current->num == pos->tail->num)
		{
			*err = 1;
			break ;
		}
		current = current->next;
	}
}
