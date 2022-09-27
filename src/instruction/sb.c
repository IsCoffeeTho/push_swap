/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:40:25 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/27 22:37:26 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

/** (swap b): swaps the first two elememts of B */
void	sb(t_s_ab *stacks)
{
	t_lst	*first;
	t_lst	*second;

	if (!ps_check(stacks))
		return ;
	if (!stacks->b->root)
		return ;
	first = stacks->b->root;
	if (!first->next)
		return ;
	second = first->next;
	if (!second->next)
		return ;
	first->next = second->next;
	second->next = first;
	stacks->b->root = second;
	ft_printf("sb\n");
}
