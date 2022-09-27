/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:40:25 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/27 22:37:15 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

/** (swap a): swaps the first two elememts of A */
void	sa(t_s_ab *stacks)
{
	t_lst	*first;
	t_lst	*second;

	if (!ps_check(stacks))
		return ;
	if (!stacks->a->root)
		return ;
	first = stacks->a->root;
	if (!first->next)
		return ;
	second = first->next;
	if (!second->next)
		return ;
	first->next = second->next;
	second->next = first;
	stacks->a->root = second;
	ft_printf("sa\n");
}
