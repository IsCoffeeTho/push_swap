/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:13:07 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/26 18:49:47 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

/** This function is an adaptation of mergeSort
 *  
 */
void	sort(t_s_ab *stacks, int from, int to)
{
	int	mid;

	ft_printf("sort(%d, %d)\n", from, to);
	if (to < from)
		return ;
	if ((to - from) > 1)
	{
		mid = ((to - from) / 2) + from;
		sort(stacks, from, mid);
		sort(stacks, mid+1, to);
	}
	else
	{
		pb(stacks);
	}
}

/** This function is the entry point of running the push_swap algorithm */
void	ps_begin(t_s_ab *stacks)
{ 
	if (!ps_check(stacks))
		return ;
	sort(stacks, 0, stacks->a->size);
	#ifdef DEBUG
		dump_stack(stacks->a);
		dump_stack(stacks->b);
	#endif
}
