/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:13:07 by amenadue          #+#    #+#             */
/*   Updated: 2022/10/03 17:08:23 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	check_set_sorted(t_s_ab *stacks)
{
	t_lst	*last;
	int		i;

	last = stacks->a->root;
	i = 0;
	while (last)
	{
		if (last->index != i)
			return ;
		last = last->next;
		i++;
	}
	exit(0);
}

t_lst	*clone_lst(t_lst *root)
{
	t_lst	*nroot;
	t_lst	*last;

	if (!root)
		return (NULL);
	nroot = (t_lst *) ft_calloc(1, sizeof(t_lst));
	nroot->data = root->data;
	last = nroot;
	root = root->next;
	while (root)
	{
		last->next = (t_lst *) ft_calloc(1, sizeof(t_lst));
		last = last->next;
		last->data = root->data;
		root = root->next;
	}
	last->next = NULL;
	return (nroot);
}

t_stack	*clone_stack(t_stack *stack)
{
	t_stack	*nstack;

	if (!stack)
		return (NULL);
	nstack = (t_stack *) ft_calloc(1, sizeof(t_stack));
	nstack->root = clone_lst(stack->root);
	nstack->size = stack->size;
	return (nstack);
}

t_s_ab	*clone_stacks(t_s_ab *stacks)
{
	t_s_ab	*nstacks;

	if (!ps_check(stacks))
		return (NULL);
	nstacks = (t_s_ab *) ft_calloc(1, sizeof(t_s_ab));
	nstacks->a = clone_stack(stacks->a);
	nstacks->b = clone_stack(stacks->b);
	return (nstacks);
}
