/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:40:25 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/27 22:36:04 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

/** (rotate rotate b): shifts all elements in B down by one
 * 	last element of B becomes the first element of B
 */
void	rrb(t_s_ab *stacks)
{
	t_lst	*first;
	t_lst	*penult;
	t_lst	*last;

	if (!ps_check(stacks))
		return ;
	if (!stacks->b->root)
		return ;
	if (!stacks->b->root->next)
		return ;
	first = stacks->b->root;
	last = first;
	while (last->next)
	{
		penult = last;
		last = last->next;
	}
	penult->next = NULL;
	last->next = first;
	stacks->b->root = last;
	ft_printf("rrb\n");
}
