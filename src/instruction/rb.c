/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:40:25 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/27 22:34:34 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

/** (rotate b): shifts all elements in B up by one
 * 	first element of B becomes the last element of B
 */
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
