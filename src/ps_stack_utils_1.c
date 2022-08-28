/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:13:07 by amenadue          #+#    #+#             */
/*   Updated: 2022/08/28 23:27:39 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	free_stack(t_stack *stack)
{
	t_lst	*tmpa;
	t_lst	*tmpb;

	if (!stack)
		return ;
	if (stack->root)
	{
		tmpa = stack->root;
		while (tmpa)
		{
			tmpb = tmpa;
			tmpa = tmpa->next;
			free(tmpb);
		}
	}
	free(stack);
}

void	free_stacks(t_s_ab *stacks)
{
	if (!stacks)
		return ;
	if (stacks->a)
		free_stack(stacks->a);
	if (stacks->b)
		free_stack(stacks->b);
	free(stacks);
}