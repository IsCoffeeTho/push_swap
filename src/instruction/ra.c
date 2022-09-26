/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:40:25 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/26 02:51:52 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

/** (rotate a):  */
void	ra(t_s_ab *stacks)
{
	t_lst	*first;
	t_lst	*second;
	t_lst	*last;

	if (!ps_check(stacks))
		return ;
	if (!stacks->a->root)
		return ;
	if (!stacks->a->root->next)
		return ;
	first = stacks->a->root;
	second = stacks->a->root->next;
	last = stacks->a->root;
	while (last->next)
		last = last->next;
	last->next = first;
	stacks->a->root = second;
	first->next = NULL;
	ft_printf("ra\n");
}
