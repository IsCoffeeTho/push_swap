/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:40:25 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/13 05:17:52 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

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
