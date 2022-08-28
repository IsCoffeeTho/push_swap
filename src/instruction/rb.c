/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:40:25 by amenadue          #+#    #+#             */
/*   Updated: 2022/08/28 23:29:05 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

void	rb(t_s_ab *stacks)
{
	t_lst	*first;
	t_lst	*second;
	t_lst	*last;

	if (!ps_check(stacks))
		return ;
	if (!stacks->b->root)
		return ;
	if (!stacks->b->root->next)
		return ;
	first = stacks->b->root;
	second = stacks->b->root->next;
	last = stacks->b->root;
	while (last->next)
		last = last->next;
	last->next = first;
	stacks->b->root = second;
	first->next = NULL;
	ft_printf("rb\n");
}