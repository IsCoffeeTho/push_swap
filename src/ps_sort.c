/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:13:07 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/27 16:29:11 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	dump_stacks(t_s_ab *stacks)
{
	dump_stack(stacks->a);
	dump_stack(stacks->b);
}

/** This function is an adaptation of mergeSort
 *  
 */
void	sortOnRadix(t_s_ab *stacks, int radix)
{
	int i;
	int l;
	
	i = 0;
	l = stacks->a->size;
	while (i < l)
	{
		if (stacks->a->root->data & radix)
			pb(stacks);
		else
			ra(stacks);
		i++;
	}
	while (i)
	{
		pa(stacks);
		i--;
	}
}

void radixSort(t_s_ab *stacks, int max)
{
	int	i;
	int l;

	i = 0;
	l = 0;
	
	while (i < (int) sizeof(int) * 8)
	{
		if (max & (0x1 << i))
			l = 0x1 << i;
		i++;
	}
	i = 0;
	while (i < l)
	{
		sortOnRadix(stacks, (0x1 << i));
		i++;
	}
}

/** This function is the entry point of running the push_swap algorithm */
void	ps_begin(t_s_ab *stacks)
{
	int max;
	int i;
	
	if (!ps_check(stacks))
		return ;
	i = 0;
	max = (0x1 << ((sizeof(int) * 8) - 1));
	while (i < (int) stacks->a->size)
	{
		if (max <= stacks->a->root->data)
			max = stacks->a->root->data;
		ra(stacks);
		i++;
	}
	radixSort(stacks, max);
	dump_stacks(stacks);
}
