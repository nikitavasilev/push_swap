/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 06:49:14 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/18 03:33:05 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

static void	free_2d(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

static int	check_args(char *str, int *err)
{
	int	num;

	num = atoi_err_overflow(str, err);
	if (*err)
		return (1);
	return (num);
}

static void	free_stack_err(t_pos *pos, char **args)
{
	free_2d(args);
	del_list(pos->head);
	free(pos);
	ft_error("Error");
}

static t_list	*create_first_node(char **args, int *err, t_pos *pos)
{
	t_list	*list;

	list = alloc_lst();
	list->num = check_args(args[0], err);
	if (*err)
		free_stack_err(pos, args);
	list->previous = NULL;
	list->next = NULL;
	pos->head = list;
	pos->tail = list;
	return (list);
}

t_pos	*fill_stack(char **args)
{
	size_t	i;
	t_list	*list;
	t_pos	*pos;
	int		num;
	int		err;

	err = 0;
	pos = alloc_pos();
	list = create_first_node(args, &err, pos);
	i = 1;
	while (args[i])
	{
		num = check_args(args[i], &err);
		if (err)
			free_stack_err(pos, args);
		list = create_node(list, num, pos);
		i++;
	}
	free_2d(args);
	return (pos);
}
