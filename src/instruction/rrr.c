/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:40:25 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/29 14:39:06 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

void	rrotate_stack(t_stack *stack)
{
	t_lst	*first;
	t_lst	*penult;
	t_lst	*last;

	if (!stack)
		return ;
	if (!stack->root)
		return ;
	if (!stack->root->next)
		return ;
	first = stack->root;
	last = first;
	while (last->next)
	{
		penult = last;
		last = last->next;
	}
	penult->next = NULL;
	last->next = first;
	stack->root = last;
}

/** (rotate rotate r): shifts all elements in both stacks down by one
 * 	last element of A becomes the first element of A
 * 	last element of B becomes the first element of B
 */
void	rrr(t_s_ab *stacks)
{
	if (!ps_check(stacks))
		return ;
	rrotate_stack(stacks->a);
	rrotate_stack(stacks->b);
	ft_printf("rrr\n");
}
