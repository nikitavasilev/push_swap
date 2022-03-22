/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:19:13 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/22 11:56:35 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int				num;
	struct s_list	*previous;
	struct s_list	*next;
}	t_list;

typedef struct s_pos
{
	t_list	*head;
	t_list	*tail;
}	t_pos;

void	del_list(t_list *lst);
t_list	*create_node(t_list *previous, int num, t_pos *pos);
t_list	*alloc_lst(void);
t_pos	*alloc_pos(void);
void	swap(t_pos *node);
void	rotate(t_pos *node);
void	rrotate(t_pos *node);
void	push(t_pos *src, t_pos *dest);
void	print_list(t_pos *pos);
char	**parse(const char **argv);
t_pos	*fill_stack(char **args);
void	check_dups(t_pos *pos, int *err);

#endif
