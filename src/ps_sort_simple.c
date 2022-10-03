/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:13:07 by amenadue          #+#    #+#             */
/*   Updated: 2022/10/03 17:08:48 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_s_ab	*order_stacks(t_s_ab *sorted)
{
	t_lst	*last;
	int		i;

	i = 0;
	last = sorted->a->root;
	while (last)
	{
		last->index = i++;
		last = last->next;
	}
	return (sorted);
}

t_s_ab	*bbl_sort(t_s_ab *stacks)
{
	int	i;
	int	j;

	j = stacks->a->size;
	while (j > 1)
	{
		i = 1;
		while (i < j)
		{
			if (stacks->a->root->data < stacks->a->root->next->data)
				swap_stack(stacks->a);
			rotate_stack(stacks->a);
			i++;
		}
		push_stack(stacks->a, stacks->b);
		j--;
	}
	j = stacks->b->size;
	while (j--)
		push_stack(stacks->b, stacks->a);
	return (stacks);
}

/** */
void	ps_index(t_s_ab *stacks)
{
	t_s_ab	*sorted;
	t_lst	*last;
	t_lst	*slast;

	sorted = order_stacks(bbl_sort(clone_stacks(stacks)));
	last = stacks->a->root;
	while (last)
	{
		slast = sorted->a->root;
		while (slast)
		{
			if (last->data == slast->data)
				last->index = slast->index;
			slast = slast->next;
		}
		last = last->next;
	}
}

/** This function is the entry point of running the push_swap algorithm */
void	ps_choose(t_s_ab *stacks)
{
	int	i;

	i = stacks->a->size;
	if (i == 1)
		return ;
	else if (i == 2)
	{
		if (stacks->a->root->data > stacks->a->root->next->data)
			sa(stacks);
	}
	else
	{
		ps_index(stacks);
		check_set_sorted(stacks);
		ps_begin(stacks);
	}
}
