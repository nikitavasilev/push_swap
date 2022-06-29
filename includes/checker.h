/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 04:40:58 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/28 14:42:10 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void	ra_c(t_pos *stack_a);
void	rb_c(t_pos *stack_b);
void	rr_c(t_pos *stack_a, t_pos *stack_b);
void	rra_c(t_pos *stack_a);
void	rrb_c(t_pos *stack_b);
void	rrr_c(t_pos *stack_a, t_pos *stack_b);
void	sa_c(t_pos *stack_a);
void	sb_c(t_pos *stack_b);
void	ss_c(t_pos *stack_a, t_pos *stack_b);
void	pa_c(t_pos *stack_b, t_pos *stack_a);
void	pb_c(t_pos *stack_a, t_pos *stack_b);

#endif
