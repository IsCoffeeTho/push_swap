/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:13:07 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/28 08:14:25 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

/** This function revserses the stack order of stack A
 * 
 *  comp: O(2n)
*/
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

/** This function gets ran everytime radix sort runs through the numbers
 * 	it takes the radix as a power of 2 and matches numbers up to see if
 * 	they have the bit that the po2 has on aswell.
 * 
 * 	this is just a helper function to split out each run through of
 * 	the list
 */
int	radix_sort_neg(t_s_ab *stacks)
{
	int	i;
	int	l;

	i = 0;
	l = stacks->a->size;
	while (i < l)
	{
		if (stacks->a->root->data < 0)
		{
			pb(stacks);
			smrt_rb(stacks);
		}
		else
			smrt_ra(stacks);
		i++;
	}
	i = stacks->b->size;
	while (i--)
	{
		pa(stacks);
		ra(stacks);
	}
	return (l);
}

/** This function gets ran everytime radix sort runs through the numbers
 * 	it takes the radix as a power of 2 and matches numbers up to see if
 * 	they have the bit that the po2 has on aswell.
 * 
 * 	this is just a helper function to split out each run through of
 * 	the list
 */
int	sort_on_radix(t_s_ab *stacks, int radix)
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
			smrt_ra(stacks);
		i++;
	}
	i = stacks->b->size;
	while (i--)
		pa(stacks);
	return (l);
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
 * This version will only run radix sort up untill the maximum between:
 * 		maximum positive value; or
 * 		minimum negative value;
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
	l <<= 1;
	i = 0;
	while (i <= l)
	{
		sort_on_radix(stacks, (0x1 << i));
		i++;
	}
}

/** This function is the entry point of running the push_swap algorithm */
void	ps_begin(t_s_ab *stacks)
{
	int	max;
	int	and_neg;
	int	i;
	int	l;

	if (!ps_check(stacks))
		return ;
	i = 0;
	l = (int) stacks->a->size;
	max = (0x1 << ((sizeof(int) * 8) - 1));
	and_neg = 0;
	while (i < l)
	{
		if (max <= stacks->a->root->data)
			max = stacks->a->root->data;
		if (stacks->a->root->data < 0)
			and_neg = -1;
		ra(stacks);
		i++;
	}
	radix_sort(stacks, max);
	if (and_neg)
		radix_sort_neg(stacks);
	reverse_stack(stacks, l);
}
