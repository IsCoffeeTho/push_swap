/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:40:25 by amenadue          #+#    #+#             */
/*   Updated: 2022/08/28 22:30:56 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

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