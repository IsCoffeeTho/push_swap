/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:13:07 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/27 22:29:24 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	reverse_stack(t_s_ab *stacks, int l)
{
	int	i;

	i = 0;
	while (i++ < l)
	{
		pb(stacks);
		rb(stacks);
	}
	i = 0;
	while (i++ < l)
		pa(stacks);
}

/**  */
void	sort_on_radix(t_s_ab *stacks, int radix)
{
	int	i;
	int	l;

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

/** radix sort takes the binary of the elements and sorts it on the different
 * positions of the number:
 * 
 * the beginning, it takes the first bit of the number eg.
 * 5 == 0101
 *         ^ first bit
 * and it will move the elements that have a 0 in that position 
 * into stack B
 * 
 * after it will push all the elements from B to A
 * 
 * then it will look at the next bit and follow the same process
 * 
 * ################
 * 
 * This version will only run radix sort up untill the maximum value
*/
void	radix_sort(t_s_ab *stacks, int max)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (i < (int) sizeof(int) * 8)
	{
		if (max & (0x1 << i))
			l = i;
		i++;
	}
	i = 0;
	while (i <= l)
	{
		sort_on_radix(stacks, (0x1 << i));
		i++;
	}
	i = 0;
}

/** This function is the entry point of running the push_swap algorithm */
void	ps_begin(t_s_ab *stacks)
{
	int	max;
	int	i;
	int	l;

	if (!ps_check(stacks))
		return ;
	i = 0;
	l = (int) stacks->a->size;
	max = (0x1 << ((sizeof(int) * 8) - 1));
	while (i < l)
	{
		if (max <= stacks->a->root->data)
			max = stacks->a->root->data;
		ra(stacks);
		i++;
	}
	radix_sort(stacks, max);
	reverse_stack(stacks, l);
}
