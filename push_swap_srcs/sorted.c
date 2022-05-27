/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 02:38:13 by nvasilev          #+#    #+#             */
/*   Updated: 2022/05/27 02:39:25 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_pos *stack)
{
	t_list	*lst;

	lst = stack->head;
	while (lst->next)
	{
		if (lst->data > lst->next->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	is_rev_sorted(t_pos *stack)
{
	t_list	*lst;

	lst = stack->head;
	while (lst->next)
	{
		if (lst->data < lst->next->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}
