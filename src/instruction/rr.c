/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:40:25 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/29 14:39:05 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

void	rotate_stack(t_stack *stack)
{
	t_lst	*first;
	t_lst	*second;
	t_lst	*last;

	if (!stack)
		return ;
	if (!stack->root)
		return ;
	if (!stack->root->next)
		return ;
	first = stack->root;
	second = stack->root->next;
	last = stack->root;
	while (last->next)
		last = last->next;
	last->next = first;
	stack->root = second;
	first->next = NULL;
}

/** (rotate r): shifts all elements in both stacks up by one
 * 	first element of A becomes the last element of A
 * 	first element of B becomes the last element of B
 */
void	rr(t_s_ab *stacks)
{
	if (!ps_check(stacks))
		return ;
	rotate_stack(stacks->a);
	rotate_stack(stacks->b);
	ft_printf("rr\n");
}
