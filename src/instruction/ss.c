/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:40:25 by amenadue          #+#    #+#             */
/*   Updated: 2022/08/28 23:32:01 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

static void	swap_stack(t_stack *stack)
{
	t_lst	*first;
	t_lst	*second;

	if (!stack)
		return ;
	if (!stack->root)
		return ;
	first = stack->root;
	if (!first->next)
		return ;
	second = first->next;
	if (!second->next)
		return ;
	first->next = second->next;
	second->next = first;
	stack->root = second;
}

void	ss(t_s_ab *stacks)
{
	t_lst	*first;
	t_lst	*second;

	if (!ps_check(stacks))
		return ;
	swap_stack(stacks->a);
	swap_stack(stacks->b);
	ft_printf("ss\n");
}