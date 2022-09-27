/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:13:07 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/27 22:39:15 by amenadue         ###   ########.fr       */
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

void	stack_count(t_stack *stack)
{
	t_lst	*last;
	int		i;

	if (stack)
	{
		if (!stack->root)
		{
			stack->size = 0;
		}
		else
		{
			i = 0;
			last = stack->root;
			while (last->next)
			{
				last = last->next;
				i++;
			}
			stack->size = i;
		}
	}
	stack->size = 0;
}
