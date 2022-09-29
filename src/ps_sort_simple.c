/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:13:07 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/29 12:54:58 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

/** Simple */
void	ps_simple(t_s_ab *stacks)
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
				sa(stacks);
			ra(stacks);
			i++;
		}
		pb(stacks);
		j--;
	}
	j = stacks->b->size;
	while (j--)
		pa(stacks);
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
	else if (i <= 10)
		ps_simple(stacks);
	else
		ps_begin(stacks);
}
