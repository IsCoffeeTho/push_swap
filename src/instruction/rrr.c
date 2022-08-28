/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:40:25 by amenadue          #+#    #+#             */
/*   Updated: 2022/08/28 22:32:54 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

static void	rrotate_stack(t_stack *stack)
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

void	rrr(t_s_ab *stacks)
{
	if (!ps_check(stacks))
		return ;
	rrotate_stack(stacks->a);
	rrotate_stack(stacks->b);
	ft_printf("rrr\n");
}