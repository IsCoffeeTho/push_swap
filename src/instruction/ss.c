/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:40:25 by amenadue          #+#    #+#             */
/*   Updated: 2022/10/03 17:04:27 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

/* Runs the swap stack */
void	swap_stack(t_stack *stack)
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
	first->next = second->next;
	second->next = first;
	stack->root = second;
}

/** (swap s): swaps the first two elements of each stack
 *  see (swap a) sa.c
*/
void	ss(t_s_ab *stacks)
{
	if (!ps_check(stacks))
		return ;
	swap_stack(stacks->a);
	swap_stack(stacks->b);
	ft_printf("ss\n");
}
