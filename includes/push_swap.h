/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:19:13 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/07 05:44:18 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_list
{
	int				data;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_pos
{
	t_list	*head;
	t_list	*tail;
	size_t	size;
}	t_pos;

typedef struct s_values
{
	int	max;
	int	min;
	int	median;
}	t_values;

typedef struct s_chunks
{
	int				*data;
	size_t			count;
}	t_chunks;


t_list		*alloc_lst(void);
t_pos		*alloc_pos(void);
t_list		*create_node(t_list *prev, int data, t_pos *pos);

char		**parse(const char **argv);
t_pos		*fill_stack(char **args);
void		check_dups(t_pos *pos, int *err);

void		sa(t_pos *stack_a);
void		sb(t_pos *stack_b);
void		ss(t_pos *stack_a, t_pos *stack_b);

void		ra(t_pos *stack_a);
void		rb(t_pos *stack_b);
void		rr(t_pos *stack_a, t_pos *stack_b);

void		rra(t_pos *stack_a);
void		rrb(t_pos *stack_b);
void		rrr(t_pos *stack_a, t_pos *stack_b);

void		pa(t_pos *stack_b, t_pos *stack_a);
void		pb(t_pos *stack_a, t_pos *stack_b);

void		print_stacks(t_pos *stack_a, t_pos *stack_b);
void		free_stacks(t_pos *stack_a, t_pos *stack_b);
void		del_list(t_list *lst);

int			sort(t_pos *stack_a, t_pos *stack_b);
int			bubble_sort(int *array, unsigned int size);
t_values	*find_median(t_pos *stack_a);
void		selection_sort(t_pos *stack_a, t_pos *stack_b);
void		insertion_sort(t_pos *stack_a, t_pos *stack_b, int median);
int			is_sorted(t_pos *stack);
int			is_rev_sorted(t_pos *stack);
int			smart_swap_a(t_pos *stack_a);
int			find_min(t_pos *stack);
size_t		find_shortest_path(size_t index, size_t size, t_pos *stack);
void		partial_sort(t_pos *stack_a, t_pos *stack_b);
int			smart_swap_b(t_pos *stack_b);
void		selection_sort_invert(t_pos *stack_a, t_pos *stack_b);
void		selection_sort_stop(t_pos *stack_a, t_pos *stack_b);
size_t		find_shortest_path_b(size_t index, size_t size, t_pos *stack);
int			find_max(t_pos *stack);
void		selection_sort_stop_min_max(t_pos *stack_a, t_pos *stack_b);
void		selection_sort_small(t_pos *stack_a, t_pos *stack_b);

#endif
